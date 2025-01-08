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
#include <stdlib.h>
#include <string.h>

/* arrays for storing username and path */
char username[50];

/* char array for storing path  to /home */
static char home_dir[] = "/home/";

/* command for installing essentials */
const char *const install_software = "sudo pacman -Sy firefox clang zsh git zed gimp mpv spectacle";

/* commands for setting up iptables directory */
const char *const clear_iptables = "sudo rm -rf /etc/iptables";
const char *const setdir_iptables = "sudo mkdir /etc/iptables";
const char *const setperms_iptables = "sudo chmod 600 /etc/iptables/iptables.rules";

/* command for setting zsh as default shell for root and user */
char zsh_set_default[100] = "sudo chsh -s /usr/bin/zsh ";

/* commands for installing oh-my-zsh, zsh-autosuggestions and zsh-syntax-highlighting */
const char *const omz_install = "su andy -c 'sh -c \"$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)\"'";
const char *const zsh_autosug = "su andy -c 'git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions'";
const char *const zsh_syntax_color = "su andy -c 'git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting'";

/* prints license info */
void print_license_info(void)
{
        printf("Linux Config Wizard  Copyright (C) 2025  Andrew Kushyk\n\
This program comes with ABSOLUTELY NO WARRANTY; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\n");
} /* print_license_info */

static void remove_newline(char *str) {
        while (*str != '\0') {
                if (*str == '\n')
                        *str = '\0';
                str++;
        }
}

/* takes user's name for setting up shell */
void read_username(void) {
        printf("Please enter the name of your user: ");
        fgets(username, 50, stdin);
        remove_newline(username);
} /* read_username */

/* sets up iptables rules */
int iptables_setup(void)
{
        if (system("sudo cp ../configs/iptables.rules /etc/iptables") != 0) {
            perror("Error: cannot move iptables.rules file\n");
            return 1;
        }
        
        return 0;
} /* iptables_setup */

/* sets up zsh config */
int zsh_setup(void)
{
        char command[100] = "";
        strcat(command, "sudo cp ../configs/.zshrc ");
        strcat(command, home_dir);
        strcat(command, username);
        
        if (system(command) != 0) {
            fprintf(stderr, "Error: cannot copy .zshrc to /home/%s", username);
            return 1;
        }
        
        return 0;
} /* zsh_setup */

/* sets up vim config */
int vim_setup(void) {
        char command[100] = "";
        strcat(command, "sudo cp ../configs/.vimrc ");
        strcat(command, home_dir);
        strcat(command, username);
        
        if (system(command) != 0) {
            fprintf(stderr, "Error: cannot copy .zshrc to /home/%s", username);
            return 1;
        }
        
        return 0;
} /* vim_setup */

static char *set_command(const char *last_part) {
        char *tmp_command = (char *) malloc(sizeof(char) * 200);
        if (tmp_command != NULL) {
                tmp_command[0] = '\0';
                strcat(tmp_command, "sudo ln -s ");
                strcat(tmp_command, home_dir);
                strcat(tmp_command, username);
                strcat(tmp_command, last_part);
        }
        
        return tmp_command;
} /* set_command */

/* sets up root cfg files */
int root_setup(void)
{
        char *command;
        
        command = set_command("/.oh-my-zsh /root/.oh-my-zsh");
        if (command == NULL) {
            perror("Error: failed to allocate memory for command\n");
            return 1;
        }
        if (system(command) != 0) {
                perror("Error: failed to create symbolic link to .oh-my-zsh!\n");
                free(command);
                return 1;
        }
        free(command);
        
        command = set_command("/.zshrc /root/.zshrc");
        if (command == NULL) {
            perror("Error: failed to allocate memory for command\n");
            return 1;
        }
        if (system(command) != 0) {
                perror("Error: failed to create symbolic link to .zshrc!\n");
                free(command);
                return 1;
        }
        free(command);
        
        command = set_command("/.vimrc /root/.vimrc");
        if (command == NULL) {
            perror("Error: failed to allocate memory for command\n");
            return 1;
        }
        if (system(command) != 0) {
                perror("Error: failed to create symbolic link to .vimrc!\n");
                free(command);
                return 1;
        }
        free(command);
        
        return 0;
} /* root_setup */
