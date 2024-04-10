# CsvLoader Plugin ![Build Status](https://github.com/ManiVaultStudio/CsvLoader/actions/workflows/build.yml/badge.svg?branch=master)

Comma-separated values (CSV) loader plugin for the [ManiVault](https://github.com/ManiVaultStudio/core) visual analytics framework.

```bash
git clone git@github.com:ManiVaultStudio/CsvLoader.git
```

<p align="middle">
  <img src="https://github.com/ManiVaultStudio/CsvLoader/assets/58806453/a26c4abb-818a-4282-86ab-9a5043fad583" align="middle"  width="40%" /> </br>
  CSV loader UI
</p>

## How to use
- Either right-click an empty area in the data hierachy and select `Import` -> `CSV Loader` or in the main menu, open `File` -> `Import data...` -> `CSV Loader)`. A file dialog will open and you can select a `.csv` file
- If the loaded CSV file has a header (e.g. dimension names), toggle "Has Headers" in the loader UI
- Limitations:
  - Custom separators (anything but ",") are not supported
  - Missing values are not supported
