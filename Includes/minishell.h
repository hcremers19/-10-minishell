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

# include "../Sources/Libft/libft.h"

/****************************************************/
/*		DEFINES										*/
/****************************************************/

/*--	Variables-----------------------*/

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

/*----- All datas-----------------------*/

struct s_data
{
	int				pid;
	int				s_free;
	struct s_all	*all;
	t_list			*env_list;
	t_list			*tmp_list;
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
	int				type;//0=RAS 1="" 2=""et$  3='' 4=$
	char			**pars_tab;
	struct s_one	*next;
	struct s_all	*all;
};

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/

/*---	Init.c -------------------------*/
t_data	*init_data(void);

/*--	Prompt.c -----------------------*/
char	*prompt(void);
// void print_dir(void);

/*--	Pars.c -------------------------*/
int 	pars_len(char const *s, int i);
int		pars_count(char const *s);
char	**ft_pars_word(char const *s, char **tab, int nb);
char	**ft_pars_line(char const *str);
t_one	*ft_pars(char const *s, t_data *d);

/*-------	Pars_end.c -----------------*/
int		init_cmds(t_data *d, int nb);
// char	*env_or_not_env(char *str, t_data *d);
// char	*join_mat(char **tab);

// static int	get_type(t_one *stru);
// static int	check_env_var(t_one *stru, t_data *d);

/*--	Pars_utils.c -------------------*/
int		nb_spec_char(char **tab, int c, int len);
int		len_tab(char **tab);
char	**copy_line_tab(char **tab, t_data *d, int i);

// char	**copy_tab(char **in);
// int		nb_pipe(char **tab);

/*--	Signal.c -----------------------*/
void	ft_signal(void);
void	handler(int sig);

/*--	Builtins.c ---------------------*/
void	ft_exit(void);
void	ft_unset(t_list *env_list, char *name);
void	ft_export(t_list *env_list, t_list *tmp_list, char *name);
void	tmp_var(t_list *tmp_list, char *name, char *content);
void	ft_env(t_list *env_list);
void	ft_cd(char *path);
void	ft_pwd(void);
void	ft_echo(char *str, int n);

/*---	Enviro.c -----------------------*/
t_list	*create_env(char **env);
char	*keep_end(char *str);
char	*keep_strt(char *str);

/*---	Utils.c ------------------------*/
size_t	ft_strcpy(char *dst, const char *src);
int		check_c_in(char *str, char c);
#endif