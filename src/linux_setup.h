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

#ifndef LINUX_SETUP_H
#define LINUX_SETUP_H

/* char array for storing username */
extern char username[];

/* command for installing essentials */
extern const char *const install_software;

/* command for deleting old iptables directory */
extern const char *const clear_iptables;

/* command for creating new iptables directory */
extern const char *const setdir_iptables;

/* command for setting permisions for iptables.rules file */
extern const char *const setperms_iptables;

/* command for setting zsh as default shell for root and user */
extern char zsh_set_default[];

/* command for installing oh-my-zsh */
extern const char *const omz_install;

/* command for installing zsh_autosuggestions */
extern const char *const zsh_autosug;

/* command for installing zsh_syntax_highlighting */
extern const char *const zsh_syntax_color;

/* reads system's username */
void read_username(void);

/* prints license info */
void print_license_info(void);

/* sets up iptables rules */
int iptables_setup(void);

/* sets up zsh config and plugins */
int zsh_setup(void);

/* sets up vim config */
int vim_setup(void);

/* sets up root cfg files */
int root_setup(void);

#endif /* LINUX_SETUP_H */
