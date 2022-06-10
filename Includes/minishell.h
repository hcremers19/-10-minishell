/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:08 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/06 14:16:40 by hcremers         ###   ########.fr       */
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

# define BSN	"\n"
# define SCREEN "\x1b[33m\
* ************************************************************************ *\n\
*                                                                          *\n\
*                                                      :::      ::::::::   *\n\
*   MINI_SHEH                                        :+:      :+:    :+:   *\n\
*                                                  +:+ +:+         +:+     *\n\
*   By: acaillea, agoloube & hcremers            +#+  +:+       +#+        *\n\
*                                              +#+#+#+#+#+   +#+           *\n\
*   Created: 2022/04/11                             #+#    #+#             *\n\
*   Updated: ?                                     ###   ###########       *\n\
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
	int				infile;
	int				outfile;
	// char 			*cmd;
	char			**pars_tab;
	struct s_one	*next;
	struct s_all	*all;
};

/*-----	Environnement-------------------*/

struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
};

/****************************************************/
/*		TOAO GLOBAL VARIABLE						*/
/****************************************************/

t_data	d;

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/

/*---	Init.c -------------------------*/
int		init_data(char **env, t_data *d);

/*--	Prompt.c -----------------------*/
char	*prompt(void);
// void print_dir(void);

/*--	Pars.c -------------------------*/
int 	pars_len(char const *s, int i);
int		pars_count(char const *s);
char	**ft_pars_word(char const *s, char **tab, int nb);
char	**ft_pars_line(char const *str);
t_one	*ft_pars(char const *s);

/*--	Pars_end.c ---------------------*/
int		loop_check_env(t_one *cmd);
int		init_cmds(void);

/*--	Pars_env_var.c -----------------*/
char	*env_or_not_env(char *str);
char	*check_env_var(char *str);
char	*join_mat(char **tab);

/*--	Pars_utils.c -------------------*/
int		nb_spec_char(char **tab, int c, int len);
char	**copy_line_tab(char **tab, int i);
// int		nb_pipe(char **tab);

/*--	Signal.c -----------------------*/
void	ft_signal(void);
void	handler(int sig);

/*--	Builtins.c ---------------------*/
void	ft_exit(void);
void	ft_unset(t_env *env_list, char *name);
void	ft_export(t_env *env_list, t_env *tmp_list, char *name);
void	tmp_var(t_env *tmp_list, char *name, char *content);
void	ft_env(t_env *env_list);
void	ft_cd(char *path);
void	ft_pwd(void);
void	ft_echo(char *str, int n);

/*---	Enviro.c -----------------------*/
t_env	*create_env(char **env);
char	*keep_end(char *str);
char	*keep_strt(char *str);

/*---	Ft_free.c ----------------------*/
void	ft_free_tab(char **tab);
void	ft_free_lst(t_env *env_list);

/*---	Ft_error.c ---------------------*/
int		ft_free_exit(int e);
int		ft_basic_exit(void);
int		ft_pre_malloc_error(int e);

/*--	Execpipe.c ---------------------*/
// int 	execpipe(t_data *d, char **env);

// /*--	Pipe.c -------------------------*/
// int 	ft_pipe(char **tab, t_data *d, char **env);
// void	here_doc(char *limiter, int nb);
// void	child_process(char *tab, char **envp);
// int 	open_file(char *tab, int i);
// void	parent_process(char **argv, char **envp, int *fd);

/*--	Pipe_utils.c -------------------*/
// char	*get_cmd_path(char *cmd, char **envp);
// void	ft_exec(char **argv, char **envp);
// char	**ft_split(char const *s, char c);

// /*--	Pipe_utils2.c ------------------*/
// void 	usage(void);
// int 	get_next_line(char **line);

/*---	Tab_utils.c --------------------*/
int		len_tab(char **tab);
int		len_tab_string(char **tab);
char	**cpy_tab(char **in, int nb_line);

/*---	Lst_env.c -----------------------*/
void	ft_env_lstadd_front(t_env **lst, t_env *new);
void	ft_env_lstdelone(t_env *lst, void (*del)(void*));
void	ft_env_lstadd_back(t_env **lst, t_env *new);
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