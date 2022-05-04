/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:08 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/04 17:11:57 by hcremers         ###   ########.fr       */
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
};

/*-----	All commandes datas-------------*/

struct s_all
{
	int				nb_cmd;
	char			**tab_cmd;
	struct s_one	*first;
};

/*-----	One Commande--------------------*/

struct s_one
{
	char			*cmd;
	char			*arg;
	char			**tab_cmd;
	struct s_one	*next;
	struct s_all	*all;
};

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/
int		init(t_data	*d);
char	*prompt(void);

char	**ft_pars(char *str, t_data *d);
char	**ft_split(char const *s, char c);

size_t	ft_strcpy(char *dst, const char *src);

void	ft_env(t_list *env_list);
void	ft_cd(char *path);
void	ft_pwd(void);
void	ft_echo(char *str, int n);

t_list	*get_env(char **env);

#endif