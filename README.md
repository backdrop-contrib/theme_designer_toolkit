# Theme Designer Toolkit

Theme Designer Toolkit is a lightweight module for Backdrop CMS that provides a central interface for discovering and accessing theme design and development tools.

The module helps theme designers discover useful tools, check their availability, and access them from a single administration page without replacing or duplicating their functionality.

## Features

- Central interface for theme design and development tools.
- Detects the status of each tool: Enabled, Disabled, or Not installed.
- Direct links to available tools and their project pages.
- JSON-based tools registry.
- Manual updates of the tools list without requiring a new module release.
- Local storage of the updated tools list.
- Fallback to the bundled tools list when the local file is unavailable or invalid.
- Automatic cleanup of generated files during uninstallation.
- No additional module dependencies, custom database tables, or cron tasks.

## Installation

1. Install and enable the Theme Designer Toolkit module.
2. Navigate to **Administration > Appearance > Theme Designer Toolkit**.
3. Explore the available tools.
4. Click **Update tools list** to retrieve the latest tools registry.

## Included Tools

- [Devel](https://backdropcms.org/project/devel)
- [Style Guide](https://backdropcms.org/project/styleguide)
- [Design Tokens](https://backdropcms.org/project/design_tokens)
- [CSS Injector](https://backdropcms.org/project/css_injector)

## Updating the Tools List

The module includes a default `tools.json` file.

When a manual update is requested, the latest tools registry is downloaded, validated, and stored in:

`public://theme_designer_toolkit/tools.json`

The module uses the updated local file when available and valid. Otherwise, it falls back to the bundled file.

No automatic external requests or scheduled updates are performed.

## Design Philosophy

Theme Designer Toolkit is intended primarily for the theme design and development process. It can be safely uninstalled when development is complete.

The goal is to provide a simple, lightweight, and extensible toolkit while keeping individual tools independent.

## Contributing

Contributions are welcome!

Developers can suggest new theme design and development tools or improve existing entries by submitting an issue or a pull request to update the `tools.json` file.

Adding or updating tools does not require changes to the module's code or a new module release.

## License

This project is licensed under the GNU General Public License, version 2 or later (GPL-2.0-or-later).

## Credits

- Created for Backdrop CMS by [shabib-m](https://github.com/shabib-m).
- Developed with AI assistance.