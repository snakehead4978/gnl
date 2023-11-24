/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:57 by snek              #+#    #+#             */
/*   Updated: 2023/11/24 17:23:43 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

extern int fl;

char	*ft_stcpy(char *str, char *a, int n, int check)
{
	char	*new;
	int		i;

	if (check)
	{
		i = -1;
		new = malloc(sizeof(char) * (n + 1));
		// if (fl++ == 2274)
		// 	printf("MALLOCCPY1\n");
		if (!new)
			return (0);
		while (++i < n)
			new[i] = str[i];
		new[i] = 0;
		return (new);
	}
	i = ft_stlenchec(str, 0, 1);
	new = malloc(sizeof(char) * (i + 1));
	// if (fl++ == 2274)
	// 	printf("MALLOCCPY2\n");
	if (!new)
		return (ft_freegnl(&a, 0));
	new[i] = 0;
	while (i-- > 0)
		new[i] = str[i];
	return (ft_stcat(a, new));
}

char	*ft_stcat(char *a, char *b)
{
	int		i;
	int		j;
	char	*new;

	if (!a)
	{
		a = malloc(sizeof(char) * 1);
		// if (fl++ == 2274)
		// 	printf("MALLOCCAT1\n");
		if (!a)
			return (ft_freegnl(&b, 0));
		a[0] = 0;
	}
	new = malloc(sizeof(char) * (ft_stlenchec(a, 0, 1) + ft_stlenchec(b, 0, 1)
				+ 1));
	// if (fl++ == 2274)	
	// 	printf("MALLOCCAT2\n");
	if (!new)
		return (ft_freegnl(&a, b));
	i = -1;
	j = 0;
	while (a[++i])
		new[i] = a[i];
	while (b[j])
		new[i++] = b[j++];
	new[i] = 0;
	ft_freegnl(&a, b);
	return (new);
}

int	ft_stlenchec(char *a, ssize_t *check, int ck)
{
	int	i;

	if (ck)
	{
		i = 0;
		while (a[i])
			i++;
		return (i);
	}
	while (*a)
	{
		if (*a == '\n')
			*check = 0;
		a++;
	}
	return (0);
}

char	*ft_freegnl(char **a, char *b)
{
	// printf("%s freed\n", *a);
	free(*a);
	*a = 0;
	if (b)
	{
		// printf("%s freed\n", b);
		free(b);
		b = 0;
	}
	return (0);
}

char	*ft_freemlc(char **a, char *b)
{
	// printf("%s freed\n", *a);
	free(*a);
	*a = 0;
	if (b)
	{
		// printf("%s freed\n", b);
		free(b);
		b = 0;
	}
	return (0);
}