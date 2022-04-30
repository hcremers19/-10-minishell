/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:08 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/27 16:30:27 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/****************************************************/
/*		INCLUDES 									*/
/****************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
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


/*--	Errors--------------------------*/// si perror et strerror obligé : a jarter
# define MA_ER "Error : Cannot allocate memory"// si perror et strerror obligé : a jarter

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

// struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// };

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/
int		init(t_data	*d);
char	*prompt(void);

char	**ft_pars(char *str, t_data *d);
char	**ft_split(char const *s, char c);

size_t	ft_strcpy(char *dst, const char *src);

#endif