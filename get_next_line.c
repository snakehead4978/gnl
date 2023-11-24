/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:54 by snek              #+#    #+#             */
/*   Updated: 2023/11/24 16:36:06 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fl = 1;

char	*ft_extract(int fd, char *buff, ssize_t check, char **str)
{
	char	*new;

	new = malloc(sizeof(char) * 1);
	// if (fl++ == 2274)
	// 	printf("MALLOCNEW\n");
	if (!new)
		return (ft_freegnl(str, 0));
	*new = 0;
	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (!check && !*new)
			return (ft_freegnl(&new, 0));
		buff[check] = 0;
		ft_stlenchec(buff, &check, 0);
		new = ft_stcpy(buff, new, 0, 0);
		if (!new)
			return (ft_freegnl(str, new));
	}
	if (check < 0)
		return (ft_freegnl(str, new));
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
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnlstocker(char **str)
{
	int		i;
	char	*st;
	char	*ret;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if ((*str)[i] == '\n')
		i++;
	ret = ft_stcpy(*str, 0, i, 1);
	if (!ret)
		return (ft_freegnl(str, 0));
	if (!((*str)[i]))
		st = 0;
	else
	{
		st = ft_stcpy(*str + i, 0, ft_stlenchec(*str + i, 0, 1), 1);
		if (!st)
			return (ft_freegnl(str, ret));
	}
	free(*str);
	*str = st;
	return (ret);
}

int	ft_checker(char **str, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (read(fd, 0, 0) != 0)
	{
		free(str[fd]);
		str[fd] = 0;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*fds[1024];
	char		*final;
	char		*buff;

	// fl = 1;
	if (!ft_checker(fds, fd))
		return (ft_freegnl(&(fds[fd]), 0));
	if (ft_checkbuffer(fds[fd]))
		return (ft_gnlstocker(&(fds[fd])));
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (fl++ == 2274)
	// 	printf("MALLOCBUFF\n");
	if (!buff)
		return (ft_freegnl(&(fds[fd]), 0));
	final = ft_extract(fd, buff, BUFFER_SIZE, &(fds[fd]));
	free(buff);
	// if (fl == 58)
	// 	printf("THE THING%s\n",final);
	if (!final)
	{
		if (fds[fd])
			return (ft_gnlstocker(&(fds[fd])));
		else
			return (0);
	}
	fds[fd] = ft_stcat(fds[fd], final);
	if (!(fds[fd]))
		return (ft_freegnl(&(fds[fd]), 0));
	return (ft_gnlstocker(&(fds[fd])));
}
