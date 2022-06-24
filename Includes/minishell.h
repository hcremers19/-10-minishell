/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:08 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/24 12:07:27 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/****************************************************/
/*		INCLUDES 									*/
/****************************************************/

# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "../Sources/libft/libft.h"

// # include "../wraloc/wraloc.h"///////// !!!!!!!

/****************************************************/
/*		DEFINES										*/
/****************************************************/

/*--	Variables-----------------------*/

# define MINI_PRPT "\033[0;31m.minishell >> \033[0;39m"
# define SCREEN "\x1b[33m\
* ************************************************************************ *\n\
*                                                                          *\n\
*                                                      :::    :::::::      *\n\
*   MINI_SHEH                                       :+:+:   :+:    :+:     *\n\
*                                                +:+ +:+   +:+    +:+      *\n\
*   By: acaillea & hcremers                         +#+     +#+#+#+        *\n\
*                                                  +#+        +#+          *\n\
*   Created: 2022/04/11                           #+#       #+#            *\n\
*   Updated:                                     ###      ###              *\n\
*                                                                          *\n\
* ************************************************************************ *\n\
\033[0;39m"

/****************************************************/
/*		STRUCT										*/
/****************************************************/

/*----- Typedef-------------------------*/

typedef struct s_data	t_data;
typedef struct s_all	t_all;
typedef struct s_one	t_one;
typedef struct s_env	t_env;

/*----- All datas-----------------------*/

struct s_data
{
	int				pid;
	int				s_free;
	int				s_err;
	int				error_code;
	int				error_code_tmp;
	struct s_all	*all;
	struct termios	old;
	struct termios	new;
	char			**env_tab;
	struct s_env	*env_list;
	struct s_env	*tmp_list;
};

/*-----	All commandes datas-------------*/

struct s_all
{
	int				nb_cmd;
	int				c_s;
	char			**init_tab;
	struct s_one	*first;
};

/*-----	One Commande--------------------*/

struct s_one
{
	int				pos;
	int				level;
	int				infile;
	int				outfile;
	char			*cmd;
	char			**pars_tab;
	struct s_one	*next;
};

/*-----	Environnement-------------------*/

struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
};

/****************************************************/
/*		THE ONE AND ONLY 							*/
/*		GLOBAL VARIABLE								*/
/*		 -> Global_Datas							*/
/****************************************************/

t_data					g_d;

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/

/*---	Init.c -------------------------*/
int		init_data(char **env, t_data *g_d);
void	init_data_bis(t_data *g_d);
void	init_sreen(void);

/*--	Pars.c -------------------------*/
int		pars_len(char const *s, int i);
int		pars_count(char const *s);
char	**ft_pars_word(char const *s, char **tab, int nb);
char	**ft_pars_line(char const *str);
t_one	*ft_pars(char *s);

/*--	Pars_end.c ---------------------*/
int		init_cmds(void);
int		get_level(t_one *cmd, int i);
void	init_cmds_values(t_one *cmd, int i);

/*--	Pars_env_var.c -----------------*/
int		loop_check_env(t_one *cmd);
char	*env_or_not_env(char *str);
char	*check_env_var(char *str);
char	*join_mat(char **tab);

/*--	Check_Tmp_Env_Var.c ------------*/
int		check_tmp_env(t_one *cmd);

/*--	Pars_dols_int.c ----------------*/
int		check_lst_stat(t_one *cmd);
char	*replace_lst_stat(char *str, int pos);

/*--	Pars_utils.c -------------------*/
int		nb_spec_char(char **tab, int c, int len);
char	**copy_line_tab(char **tab, int i);
// int		nb_pipe(char **tab);

/*--	Signal.c -----------------------*/
void	ft_signal(void);
void	handler(int sig);

/*--	Builtins.c ---------------------*/
void	ft_unset(char *name);
void	ft_export(char *name);
void	tmp_var(char *name, char *content);
void	ft_env(void);
int		ft_cd(char *path);
void	ft_pwd(void);
void	ft_echo(char **pars_tab);

/*--	Ft_Cd.c ------------------------*/
int		ch_oldpwd_env(void);
int		ch_pwd_env(void);
int		ft_cd(char *path);

/*--	Ft_echo.c ----------------------*/
void	write_w_quotes(char *str);
void	ft_echo(char **pars_tab);

/*--	Ft_exit.c ----------------------*/
void	ft_exit(t_one *cmd);

/*---	Enviro.c -----------------------*/
int		create_env(char **env);
char	*keep_end(char *str);
char	*keep_strt(char *str);

/*---	Ft_free.c ----------------------*/
void	ft_free_tab(char **tab);
void	ft_free_lst(t_env *env_list);
void	ft_free_cmd_lst(t_one *cmd);

/*---	Exit.c -------------------------*/
void	init_exit(void);
void	loop_exit(void);
void	global_exit(void);

/*--	Execpipe.c ---------------------*/
int		execpipe(void);
int		check_builtin(t_one *cmd);
int		builtin_cmds_env(t_one *cmd);
int		builtin_cmds(t_one *cmd);

/*--	Pipe.c -------------------------*/
void	process(char *envp[], char **all_cmd, t_one *cmd, int to_exec);
void	child_process(t_all *all, t_one *cmd, int next_fd[2], int pre_fd[2]);
void	pipe_rec_2(t_all *all, t_one *cmd, int tmp, int next_fd[2]);
void	pipe_rec(t_all *all, char **envp, int pre_fd[2], t_one *cmd);

/*--	Pipe_utils.c -------------------*/
char	**get_path(void);
void	close_pipe(int fd[2]);
void	ft_free(char **paths, char **cmd);
void	perror_cnf(char *str, char *cmd, int fd);
void	ft_end_process(char *cmd_p, char **cmd, char **path, t_one *cmd_str);

/*--	Pipe_utils2.c ------------------*/
int		no_path(char **paths, char **all_cmd, t_one *cmd, int to_ex);
char	*find_cmd_path(char **paths, t_one *cmd, char **all_cmd);
void	ft_redirection(int fd_in, int fd_out, int simple, int first);
void	multi_pipe(t_all *all, int next_fd[2], int pre_fd[2], t_one *cmd);
void	clean_mat_and_exit(char **paths);
////////////////////////////////////////////////////////////////////

/*---	Tab_utils.c --------------------*/
int		len_tab(char **tab);
int		len_tab_string(char **tab);
char	**cpy_tab(char **in, int nb_line);

/*---	Lst_env.c -----------------------*/
void	ft_env_lstadd_front(t_env **lst, t_env *new);
void	ft_env_lstdelone(t_env *lst, void (*del)(void*));
void	ft_env_lstadd_back(t_env **lst, t_env *new);
void	ft_env_lstfreenull(t_env *env_list);

/*---	Lst_env1.c ----------------------*/
t_env	*ft_env_lstnew(char *name, char *content);
t_env	*ft_env_lstlast(t_env *lst);
t_env	*ft_env_lststr(t_env *lst, char *name);

/*---	Utils.c ------------------------*/
size_t	ft_strcpy(char *dst, const char *src);
int		check_c_in(char *str, char c);
int		count_c_in(char *str, char c);
int		only_space(char *s);
char	*ft_strcat(char *dest, char *src);

#endif