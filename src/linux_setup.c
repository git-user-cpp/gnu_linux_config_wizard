/*    GNU/Linux Config Wizard: The ultimate post-installation setup assistant for Linux,
 *    streamlining your configuration process with ease and precision.
 *
 *    Copyright (C) 2025  Andrew Kushyk
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "linux_setup.h"
#include <stdio.h>

/* command for installing essentials */
const char *const install_software = "sudo pacman -Sy firefox clang zsh git zed gimp mpv spectacle";

/* command for setting zsh as default shell for root and user */
char zsh_set_default[100] = "sudo chsh -s /usr/bin/zsh ";

/* commands for installing oh-my-zsh, zsh-autosuggestions and zsh-syntax-highlighting */
const char *const omz_install = "sh -c \"$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)\"";
const char *const zsh_autosug = "git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions";
const char *const zsh_syntax_color = "git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting";


/* prints license info */
void print_license_info(void) {
    printf("Linux Config Wizard  Copyright (C) 2025  Andrew Kushyk\n\
This program comes with ABSOLUTELY NO WARRANTY; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\n");
}