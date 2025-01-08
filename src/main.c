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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linux_setup.h"

int main(void)
{
        /* prints license info */
        print_license_info();
        
        /* takes user's name for setting up shell */
        char username[50];
        printf("Please enter the name of your user: ");
        fgets(username, 50, stdin);
        
        /* installs essential software */
        if (system(install_software) != 0) {
                perror("Error: failed to install essential software!\n");
                return 1;
        }
        
        /* removes /etc/iptables */
        if (system(clear_iptables) != 0) {
                perror("Error: failed to clear old iptables directory!\n");
                return 2;
        }
        
        /* creates empty /etc/iptables */
        if (system(setdir_iptables) != 0) {
                perror("Error: failed to create new directory for iptables!\n");
                return 3;
        }
        
        /* sets up zsh as default shell for root */
        if (system(zsh_set_default) != 0) {
                perror("Error: failed to set zsh as default shell for root\n");
                return 2;
        }
        
        /* sets up zsh as default shell for user */
        if (system(strcat(zsh_set_default, username)) != 0) {
                fprintf(stderr, "Error: failed to set zsh as default shell for user %s\n", username);
                return 3;
        }
        
        /* installs oh-my-zsh */
        if (system(omz_install) != 0) {
                perror("Error: failed to install oh-my-zsh\n");
                return 4;
        }
        
        /* installs zsh-autosuggestions */
        if (system(zsh_autosug) != 0) {
                perror("Error: failed to install zsh-autosuggestions\n");
                return 5;
        }
        
        /* installs zsh-syntax-highlighting */
        if (system(zsh_syntax_color) != 0) {
                perror("Error: failed to install zsh syntax-highliting\n");
                return 6;
        }
    
        return 0;
} /* main */
