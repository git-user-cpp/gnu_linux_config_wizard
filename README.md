# GNU/Linux Config Wizard

The ultimate post-installation setup assistant for GNU/Linux, streamlining your configuration process with ease and precision.

---

![GitLab Release](https://img.shields.io/gitlab/v/release/git-user-cpp%2Fgnu_linux_config_wizard?display_name=release&date_order_by=released_at&style=flat-square&logo=gitlab)
![GitLab Stars](https://img.shields.io/gitlab/stars/git-user-cpp%2Fgnu_linux_config_wizard?style=flat-square&logo=gitlab)

![GitLab Contributors](https://img.shields.io/gitlab/contributors/git-user-cpp%2Fgnu_linux_config_wizard?style=flat-square&logo=gitlab) ![GitLab Last Commit](https://img.shields.io/gitlab/last-commit/git-user-cpp%2Fgnu_linux_config_wizard?style=flat-square&logo=gitlab)

![GitLab License](https://img.shields.io/gitlab/license/git-user-cpp%2Fgnu_linux_config_wizard?style=flat-square&logo=gitlab)

---

To use the program download the latest version here: https://gitlab.com/git-user-cpp/gnu_linux_config_wizard/-/tree/main/releases?ref_type=heads

Unpack the archive:
```
tar -xzf gnu_linux_config_wizard_1_1_0.tar.gz
```
Then enter the "program" directory:
```
cd gnu_linux_config_wizard_1_1_0/program
```
And finally run the program:
```
sudo ./gnulinwiz
```

---

All set! Your GNU/Linux system is ready to use!

---

If you want to build the program: create and enter the build/ directory
```
mkdir build
cd build
```
Run cmake command with mode release:
```
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./gnulinwiz
```
If you need to use debugger use:
```
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
gdb gnulinwiz
```

---

## ⚠️ LICENSE ⚠️

    GNU/Linux Config Wizard: The ultimate post-installation setup assistant for Linux,
    streamlining your configuration process with ease and precision.

    Copyright (C) 2025  Andrew Kushyk

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

---
