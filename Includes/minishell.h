/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:08 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 21:36:00 by acaillea         ###   ########.fr       */
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
*   Updated: 2022/07/01                          ###      ###              *\n\
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
	int				s_ex;
	int				c_s;
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

/*--	Builtin_launcher.c -------------*/
int		ft_unset_launcher(t_one *cmd);
int		ft_env_launcher(t_one *cmd);
int		ft_pwd_launcher(t_one *cmd);

/*--	Builtins.c ---------------------*/
void	ft_unset(char *name);
void	ft_env(void);
void	ft_pwd(void);
int		ft_export(char *name);
int		tmp_var(char *name, char *content);

/*---	Env_utils.c --------------------*/
int		ft_strlcmp(const char *s1, const char *s2);

/*---	Enviro.c -----------------------*/
int		create_env(char **env);
char	*keep_end(char *str);
char	*keep_strt(char *str);

/*--	Execpipe.c ---------------------*/
int		execpipe(void);
int		check_builtin(t_one *cmd);
int		builtin_cmds_env(t_one *cmd);
int		builtin_cmds(t_one *cmd);

/*---	Exit.c -------------------------*/
void	init_exit(void);
void	loop_exit(void);
void	global_exit(void);

/*--	Ft_Cd.c ------------------------*/
int		ch_pwd_env(char *varname, char *wd);
int		ft_cd(char *path);

/*--	Ft_echo.c ----------------------*/
void	write_w_quotes(char *str);
void	ft_echo(char **pars_tab);

/*--	Ft_exit.c ----------------------*/
void	ft_exit(t_one *cmd);

/*---	Ft_free.c ----------------------*/
void	ft_free_tab(char **tab);
void	ft_free_lst(t_env *env_list);
void	*ft_free_cmd_lst(t_one *cmd);
char	*ft_free_fct_tab(char **tab, char *tmp);
int		ft_free_two(char *s1, char *s2);

/*---	Init.c -------------------------*/
int		init_data(char **env, t_data *g_d);
void	init_data_bis(t_data *g_d);
void	init_sreen(void);

/*---	Lst_env.c ----------------------*/
void	ft_env_lstadd_front(t_env **lst, t_env *new);
void	ft_env_lstdelone(t_env *lst, void (*del)(void*));
void	ft_env_lstadd_back(t_env **lst, t_env *new);

/*---	Lst_env1.c ---------------------*/
t_env	*ft_env_lstnew(char *name, char *content);
t_env	*ft_env_lstlast(t_env *lst);
t_env	*ft_env_lststr(t_env *lst, char *name);

/*--	Pars_end.c ---------------------*/
int		init_cmds(void);
int		get_level(t_one *cmd, int i);
int		check_dollar(t_one *cmd);
char	*loop_check_dollar(char	*str, int pos);
void	init_cmds_values(t_one *cmd, int i);

/*--	Pars_dollar.c ------------------*/
int		env_or_not_env(char *str, t_env *list);
char	*check_env_var_bis(char *str, char **tmp_tab, char *tmp, int t);
char	*check_env_var(char *str);
char	*replace_env_var(char *str, t_env *list);
char	*replace_lst_stat(char *str, int pos);

/*--	Pars_Tmp_Env_Var.c -------------*/
int		check_tmp_env(t_one *cmd);

/*--	Pars_utils.c -------------------*/
char	**copy_line_tab(char **tab, int i);

/*--	Pars_init.c --------------------*/
int		pars_len(char const *s, int i);
int		pars_count(char const *s);
char	**ft_pars_word(char const *s, char **tab, int nb);
char	**ft_pars_line(char const *str);

/*--	Pars.c -------------------------*/
t_one	*ft_pars(char *s);
t_one	*ft_pars_loop(t_one *tmp, int *j);

/*--	Pipe_utils.c -------------------*/
char	**get_path(void);
void	close_pipe(int fd[2]);
void	ft_free(char **paths, char **cmd);
void	perror_cnf(char *str, char *cmd, int fd);
void	ft_end_process(char *cmd_p, char **path, t_one *cmd_str);

/*--	Pipe_utils2.c ------------------*/
int		no_path(char **paths, t_one *cmd, int to_ex);
char	*find_cmd_path(char **paths, t_one *cmd);
void	ft_redirection(int fd_in, int fd_out, int simple, int first);
void	multi_pipe(int next_fd[2], int pre_fd[2], t_one *cmd);
void	clean_mat_and_exit(char **paths);

/*--	Pipe.c -------------------------*/
void	process(t_one *cmd, int to_exec);
void	child_process(t_one *cmd, int next_fd[2], int pre_fd[2]);
void	ft_pipe_2(t_one *cmd, int tmp, int next_fd[2]);
void	ft_pipe(int pre_fd[2], t_one *cmd);

/*--	Signal.c -----------------------*/
void	ft_signal(void);
void	handler(int sig);

/*---	Tab_utils.c --------------------*/
int		len_tab(char **tab);
int		len_tab_string(char **tab);
char	**cpy_tab(char **in, int nb_line);
char	*join_mat(char **tab);

/*---	Utils.c ------------------------*/
size_t	ft_strcpy(char *dst, const char *src);
int		loop_while(char *str, int j);
int		check_c_in(char *str, char c);
int		count_c_in(char *str, char c);

/*---	Utils_1.c ----------------------*/
int		only_space(char *s);
char	*ft_strcat(char *dest, char *src);

#endif