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
        print_license_info();
        
        username_setup();
        
        if (system(install_software) != 0) {
                perror("Error: failed to install essential software!\n");
                return 1;
        }
        
        if (system(clear_iptables) != 0) {
                perror("Error: failed to clear old iptables directory!\n");
                return 2;
        }
        
        if (system(setdir_iptables) != 0) {
                perror("Error: failed to create new directory for iptables!\n");
                return 3;
        }
        
        if (iptables_setup() != 0) {
                perror("Error: failed to set up iptables!\n");
                return 4;
        }
        
        if (system(setperms_iptables) != 0) {
                perror("Error: failed to change permissions for /etc/iptables/iptables.rules\n");
                return 5;
        }
        
        if (vim_setup() != 0) {
                perror("Error: failed to set up vim!\n");
                return 6;
        }
        
        if (system(zsh_set_default) != 0) {
                perror("Error: failed to set zsh as default shell for root\n");
                return 7;
        }
        
        if (system(strcat(zsh_set_default, username)) != 0) {
                fprintf(stderr, "Error: failed to set zsh as default shell for user %s\n", username);
                return 8;
        }
        
        if (system(omz_install) != 0) {
                perror("Error: failed to install oh-my-zsh\n");
                return 9;
        }
        
        if (system(zsh_autosug) != 0) {
                perror("Error: failed to install zsh-autosuggestions\n");
                return 10;
        }
        
        if (system(zsh_syntax_color) != 0) {
                perror("Error: failed to install zsh syntax-highliting\n");
                return 11;
        }
        
        if (zsh_setup() != 0) {
                perror("Error: failed to set up zsh!\n");
                return 12;
        }
        
        if (root_setup() != 0) {
                perror("Error: failed to set up symbolic links for root user!\n");
                return 13;
        }
        
        if (zram_swap_setup() != 0) {
                perror("Error: failed to set up zram swap!\n");
                return 14;
        }
        
        printf("Your GNU/Linux system is all set! No errors were reported.\n");
        
        return 0;
} /* main */
