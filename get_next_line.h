/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:35:07 by snek              #+#    #+#             */
/*   Updated: 2023/11/19 17:08:45 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>

# define BUFFER_SIZE 12

typedef struct s_clist
{
	char	*c;
	struct s_clist	*next;
}	t_clist;

char *get_next_line(int fd);
char	*ft_stcpy(char *str, char *a, int n, int check);
int	ft_stlenchec(char *a, ssize_t *check, int ck);
char	*ft_stcat(char *a, char *b);
char	*ft_freegnl(char *a, char *b);


#endif