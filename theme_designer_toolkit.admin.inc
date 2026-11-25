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

  return $build;
}
