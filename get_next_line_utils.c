/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:57 by snek              #+#    #+#             */
/*   Updated: 2023/11/22 15:57:55 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stcpy(char *str, char *a, int n, int check)
{
	char	*new;
	int		i;

	if (check)
	{
		i = -1;
		new = malloc(sizeof(char) * (n + 1));
		if (!new)
			return (0);
		while (++i < n)
			new[i] = str[i];
		new[i] = 0;
		return (new);
	}
	i = ft_stlenchec(str, 0, 1);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
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
		if (!a)
			return (ft_freegnl(b, 0));
		a[0] = 0;
	}
	new = malloc(sizeof(char) * (ft_stlenchec(a, 0, 1) + ft_stlenchec(b, 0, 1)
				+ 1));
	if (!new)
		return (ft_freegnl(a, b));
	i = -1;
	j = 0;
	while (a[++i])
		new[i] = a[i];
	while (b[j])
		new[i++] = b[j++];
	new[i] = 0;
	free(a);
	free(b);
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

char	*ft_freegnl(char *a, char *b)
{
	free(a);
	if (b)
		free(b);
	return (0);
}
