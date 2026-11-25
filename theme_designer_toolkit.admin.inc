<?php
/**
 * @file
 * Administration pages for Theme Designer Toolkit.
 */

/**
 * Page callback for the Theme Designer Toolkit administration page.
 */
function theme_designer_toolkit_admin_page() {
  $build = array();

  $build['intro'] = array(
    '#markup' => '<p>' . t('Discover and access tools that simplify theme design and development in Backdrop CMS.') . '</p>',
  );

  $tools = theme_designer_toolkit_get_tools();
  $modules = system_rebuild_module_data();

  $header = array(
    t('Tool'),
    t('Description'),
    t('Status'),
    t('Operations'),
  );

  $rows = array();

  foreach ($tools as $module => $tool) {
    $installed = isset($modules[$module]);
    $enabled = $installed && !empty($modules[$module]->status);

    if ($enabled) {
    $status = t('Enabled');
    }
    elseif ($installed) {
    $status = t('Disabled');
    }
    else {
    $status = t('Not installed');
    }

    $operations = array();

    if ($enabled && !empty($tool['path']) && backdrop_valid_path($tool['path'])) {
      $operations[] = l(t('Open tool'), $tool['path']);
    }

    if (!empty($tool['project'])) {
      $operations[] = l(t('Project page'), $tool['project']);
    }

    $rows[] = array(
      check_plain($tool['name']),
      check_plain($tool['description']),
      $status,
      implode(' | ', $operations),
    );
  }

  $build['tools'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No tools are available.'),
  );

  
  $build['update'] = backdrop_get_form(
    'theme_designer_toolkit_update_form'
   );


  return $build;
}


/**
 * Form for updating the tools registry.
 */
function theme_designer_toolkit_update_form($form, &$form_state) {
  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update tools list'),
  );

  return $form;
}


/**
 * Submit handler for the tools update form.
 */
function theme_designer_toolkit_update_form_submit($form, &$form_state) {
  if (theme_designer_toolkit_update_tools()) {
    backdrop_set_message(t('Tools list updated successfully.'));
  }
  else {
    backdrop_set_message(t('Unable to update the tools list.'), 'error');
  }

  $form_state['redirect'] = 'admin/appearance/toolkit';
}
