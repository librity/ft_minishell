/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/06 15:29:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char			**_envp = (char *[]){
	"SHELL=/bin/bash",
	"SESSION_MANAGER=local/dev1:@/tmp/.ICE-unix/2561,unix/dev1:/tmp/.ICE-unix/2561",
	"WINDOWID=6291460",
	"QT_ACCESSIBILITY=1",
	"COLORTERM=truecolor",
	"XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg",
	"SSH_AGENT_LAUNCHER=gnome-keyring",
	"NVM_INC=/home/lgeniole/.nvm/versions/node/v16.17.0/include/node",
	"XDG_MENU_PREFIX=gnome-",
	"TERM_PROGRAM_VERSION=3.2a",
	"GNOME_DESKTOP_SESSION_ID=this-is-deprecated",
	"TMUX=/tmp/tmux-1000/default,10995,0",
	"MANDATORY_PATH=/usr/share/gconf/ubuntu.mandatory.path",
	"LC_ADDRESS=en_CA.UTF-8",
	"GNOME_SHELL_SESSION_MODE=ubuntu",
	"LC_NAME=en_CA.UTF-8",
	"SSH_AUTH_SOCK=/run/user/1000/keyring/ssh",
	"RBENV_HOOK_PATH=/home/lgeniole/.rbenv/rbenv.d:/usr/lib/rbenv/rbenv.d:/usr/local/etc/rbenv.d:/etc/rbenv.d:/usr/lib/rbenv/hooks",
	"XMODIFIERS=@im=ibus",
	"DESKTOP_SESSION=ubuntu",
	"LC_MONETARY=en_CA.UTF-8",
	"RBENV_SHELL=bash",
	"EDITOR=nano",
	"GTK_MODULES=gail:atk-bridge",
	"PWD=/home/lgeniole/code/ft/minishell",
	"XDG_SESSION_DESKTOP=ubuntu",
	"LOGNAME=lgeniole",
	"XDG_SESSION_TYPE=x11",
	"GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1",
	"SYSTEMD_EXEC_PID=2585",
	"XAUTHORITY=/run/user/1000/gdm/Xauthority",
	"GJS_DEBUG_TOPICS=JS ERROR;JS LOG",
	"WINDOWPATH=2",
	"c=foo",
	"HOME=/home/lgeniole",
	"b=2",
	"USERNAME=lgeniole",
	"a=",
	"IM_CONFIG_PHASE=1",
	"LC_PAPER=en_CA.UTF-8",
	"LANG=en_US.UTF-8",
	"LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:",
	"XDG_CURRENT_DESKTOP=ubuntu:GNOME",
	"INVOCATION_ID=0a8fc8b228e742e4b4ad56802e1ffb5b",
	"MANAGERPID=2330",
	"foo=bar",
	"ALACRITTY_SOCKET=/run/user/1000/Alacritty-:1-4739.sock",
	"GJS_DEBUG_OUTPUT=stderr",
	"NVM_DIR=/home/lgeniole/.nvm",
	"LESSCLOSE=/usr/bin/lesspipe %s %s",
	"XDG_SESSION_CLASS=user",
	"TERM=screen-256color",
	"LC_IDENTIFICATION=en_CA.UTF-8",
	"DEFAULTS_PATH=/usr/share/gconf/ubuntu.default.path",
	"LESSOPEN=| /usr/bin/lesspipe %s",
	"USER=lgeniole",
	"TMUX_PANE=%1",
	"VISUAL=nano",
	"DISPLAY=:1",
	"SHLVL=2",
	"NVM_CD_FLAGS=",
	"LC_TELEPHONE=en_CA.UTF-8",
	"QT_IM_MODULE=ibus",
	"LC_MEASUREMENT=en_CA.UTF-8",
	"PAPERSIZE=letter",
	"XDG_RUNTIME_DIR=/run/user/1000",
	"LC_TIME=en_CA.UTF-8",
	"JOURNAL_STREAM=8:41009",
	"XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop",
	"PATH=/home/lgeniole/.local/bin:/home/lgeniole/.rbenv/shims:/home/lgeniole/.rbenv/versions/2.7.1/bin:/usr/lib/rbenv/libexec:/home/lgeniole/.nvm/versions/node/v16.17.0/bin:/home/lgeniole/.rsvm/current/cargo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/usr/local/go/bin:/home/lgeniole/code/go/bin",
	"ALACRITTY_LOG=/tmp/Alacritty-4739.log",
	"GDMSESSION=ubuntu",
	"DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus",
	"NVM_BIN=/home/lgeniole/.nvm/versions/node/v16.17.0/bin",
	"RBENV_ROOT=/home/lgeniole/.rbenv",
	"GIO_LAUNCHED_DESKTOP_FILE_PID=4739",
	"GIO_LAUNCHED_DESKTOP_FILE=/usr/share/applications/Alacritty.desktop",
	"LC_NUMERIC=en_CA.UTF-8",
	"OLDPWD=/home/lgeniole/code/ft",
	"GOPATH=/home/lgeniole/code/go",
	"TERM_PROGRAM=tmux",
	"_=/usr/bin/env",
	NULL};
t_hash_table	*_envht;
char			*_str;
char			**_strarr;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(envp_tst)
{
	c()->envp = _envp;
	mu_check(true == initialize_envht());

	_strarr = envht_to_envp();
	mu_check(ft_strarr_len(_envp) == ft_strarr_len(_strarr));
	assert_strarr_equivalent(_envp, _strarr);

	ft_free_strarr(_strarr);
	ht_destroy(&(c()->envht));
}

MU_TEST_SUITE(envp_to_envht_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(envp_tst);
}

int	main(int argc, char **argv, char **envp)
{
	MU_DIVIDER;
	MU_RUN_SUITE(envp_to_envht_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
