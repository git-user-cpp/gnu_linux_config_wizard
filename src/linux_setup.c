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
char username[100];
char home_dir[100] = "/home/";

/* command for installing essentials */
const char *const install_software = "sudo pacman -Sy firefox clang zsh git zed gimp mpv spectacle";

/* commands for setting up iptables directory */
const char *const clear_iptables = "sudo rm -rf /etc/iptables";
const char *const setdir_iptables = "sudo mkdir /etc/iptables";
const char *const setperms_iptables = "sudo chmod 600 /etc/iptables/iptables.rules";

/* command for setting zsh as default shell for root and user */
char zsh_set_default[100] = "sudo chsh -s /usr/bin/zsh ";

/* commands for installing oh-my-zsh, zsh-autosuggestions and zsh-syntax-highlighting */
const char *const omz_install = "sh -c \"$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)\"";
const char *const zsh_autosug = "git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions";
const char *const zsh_syntax_color = "git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting";
const char *const enter_root = "sudo su";
const char *const enter_root_dir = "cd /root";
const char *const set_up_root_zsh = "";

/* prints license info */
void print_license_info(void)
{
        printf("Linux Config Wizard  Copyright (C) 2025  Andrew Kushyk\n\
This program comes with ABSOLUTELY NO WARRANTY; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions; for details see https://www.gnu.org/licenses/gpl-3.0.html/\n\n");
} /* print_license_info */

/* takes user's name for setting up shell */
void read_username(void) {
        printf("Please enter the name of your user: ");
        fgets(username, 100, stdin);
} /* read_username */

/* sets up iptables rules */
int iptables_setup(void)
{
        FILE *rules_reader = NULL;
        FILE *rules_writer = NULL;
        char buffer[100];
        
        if ((rules_reader = fopen("../configs/iptables_cfg.txt", "r")) == NULL) {
                perror("Error: cannot open iptable config to write it in system folder...\n");
                return 1;
        }
        if ((rules_writer = fopen("/etc/iptables/iptables.rules", "w+")) == NULL) {
                perror("Error: cannot create /etc/iptables/iptables.rules for storing the rules\n");
                fclose(rules_reader);
                return 1;
        }
        
        while (fgets(buffer, sizeof(buffer), rules_reader) != NULL) {
                if (fputs(buffer, rules_writer) == EOF) {
                        perror("Error: failed to write to iptables rules file");
                        fclose(rules_writer);
                        fclose(rules_reader);
                        return 1;
                }
        }
        
        if (fclose(rules_writer) == EOF) {
                perror("Error: failed to close iptables rules file");
                return 1;
        }
        
        if (fclose(rules_reader) == EOF) {
                perror("Error: failed to close iptable config file");
                return 1;
        }
        
        return 0;
} /* iptables_setup */

/* sets up zsh config */
int zsh_setup(void)
{
        FILE *config_reader = NULL;
        FILE *config_writer = NULL;
        char buffer[100];
        
        char *path;
        path = strcat(home_dir, username);
        
        if ((config_reader = fopen("../configs/zsh_cfg.txt", "r")) == NULL) {
                perror("Error: cannot open zsh config to write it in system folder...\n");
                return 1;
        }
        if ((config_writer = fopen(strcat(path, "/.zshrc"), "w+")) == NULL) {
                perror("Error: cannot create/write /home/username/.zshrc for storing the configuration\n");
                fclose(config_reader);
                return 1;
        }
        
        while (fgets(buffer, sizeof(buffer), config_reader) != NULL) {
                if (fputs(buffer, config_writer) == EOF) {
                        perror("Error: failed to write to .zshrc file");
                        fclose(config_writer);
                        fclose(config_reader);
                        return 1;
                }
        }
        
        if (fclose(config_writer) == EOF) {
                perror("Error: failed to close config file");
                fclose(config_reader);
                return 1;
        }
        
        if (fclose(config_reader) == EOF) {
                perror("Error: failed to close .zshrc file");
                return 1;
        }
        
        return 0;
} /* zsh_setup */

/* sets up vim config */
int vim_setup(void) {
    FILE *config_reader = NULL;
    FILE *config_writer = NULL;
    char buffer[100];
    
    char *path;
    path = strcat(home_dir, username);
    
    if ((config_reader = fopen("../configs/vim_cfg.txt", "r")) == NULL) {
            perror("Error: cannot open zsh config to write it in system folder...\n");
            return 1;
    }
    if ((config_writer = fopen(strcat(path, "/.vimrc"), "w+")) == NULL) {
            perror("Error: cannot create/write /home/username/.vimrc for storing the configuration\n");
            fclose(config_reader);
            return 1;
    }
    
    while (fgets(buffer, sizeof(buffer), config_reader) != NULL) {
            if (fputs(buffer, config_writer) == EOF) {
                    perror("Error: failed to write to .vimrc file");
                    fclose(config_writer);
                    fclose(config_reader);
                    return 1;
            }
    }
    
    if (fclose(config_writer) == EOF) {
            perror("Error: failed to close config file");
            fclose(config_reader);
            return 1;
    }
    
    if (fclose(config_reader) == EOF) {
            perror("Error: failed to close .vimrc file");
            return 1;
    }
    
    return 0;
}
