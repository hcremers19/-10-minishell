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
# include <readline/readline.h>
# include <readline/history.h>

# include "../Sources/Libft/libft.h"

/****************************************************/
/*		DEFINES										*/
/****************************************************/

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

typedef struct s_datas	t_datas;
//typedef struct s_cmd	t_cmd;

struct s_datas
{

};

/****************************************************/
/*		PROTOTYPES									*/
/****************************************************/
int		take_input(char *str);
void	init_screen(void);
char	*prompt(void);
char	**ft_split(char const *s, char c);

size_t	ft_strcpy(char *dst, const char *src);

#endif