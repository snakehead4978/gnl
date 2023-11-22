/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:35:07 by snek              #+#    #+#             */
/*   Updated: 2023/11/21 19:47:43 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_clist
{
	char			*c;
	struct s_clist	*next;
}					t_clist;

char				*get_next_line(int fd);
char				*ft_stcpy(char *str, char *a, int n, int check);
int					ft_stlenchec(char *a, ssize_t *check, int ck);
char				*ft_stcat(char *a, char *b);
char				*ft_freegnl(char *a, char *b);

#endif