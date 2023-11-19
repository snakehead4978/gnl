/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:54 by snek              #+#    #+#             */
/*   Updated: 2023/11/19 17:35:06 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract(int fd)
{
	char	*buff;
	char	*new;
	ssize_t	check;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	new = malloc(sizeof(char) * 1);
	if (!new)
		return (ft_freegnl(buff, 0));
	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		check = read(fd, buff, BUFFER_SIZE);
		buff[check] = 0;
		ft_stlenchec(buff, &check, 0);
		new = ft_stcpy(buff, new, 0, 0);
		if (!new)
			return (ft_freegnl(buff, 0));
	}
	free(buff);
	if (check < 0)
		return (ft_freegnl(new, 0));
	return (new);
}

int	ft_checkbuffer(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == EOF)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnlstocker(char **str)
{
	int	i;
	char	*st;
	char	*ret;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != EOF)
		i++;
	ret = ft_stcpy(*str, 0, i, 1);
	if (!ret)
		return (0);
	st = ft_stcpy(*str + i, 0, ft_stlenchec(*str + i, 0, 1), 1);
	if (!st)
		return (ft_freegnl(ret, 0));
	free(*str);
	*str = st;
	return (ret);
}

char	*get_next_line(int fd)
{
	ssize_t	check;
	static	char*	fds[1024];
	char	*final;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (ft_checkbuffer(fds[fd]))
		return (ft_gnlstocker(&(fds[fd])));
	final = ft_extract(fd);
	if (!final)
		return (0);
	fds[fd] = ft_stcat(fds[fd], final);
	if (!(fds[fd]))
		return (final);
	return (ft_gnlstocker(&(fds[fd])));
}
