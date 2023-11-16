/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:54 by snek              #+#    #+#             */
/*   Updated: 2023/11/16 23:35:05 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




int	ft_clstback(t_clist **node, char *data)
{
	t_clist	*new;
	t_clist	*tmp;
	int		i;

	new = malloc(sizeof(t_clist));
	if (!new)
		return (ft_clstclr(node, data));
	i = 0;
	while (data[i])
		i++;
	new->c = malloc(sizeof(char) * (i++ + 1));
	if (!new->c)
		return (ft_clstclr(node, data));
	while (--i != 0)
		new->c[i] = data[i];
	new->next = 0;
	if (!*node)
		*node = new;
	else
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

char	*ft_clstclr(t_clist *node, char *str)
{
	if (str)
		free(str);
	if (!node)
		return (0);
	if (node->next)
		ft_clstclr(node->next, 0);
	if (node->c)
		free(node->c);
	free(node);
	return (0);
}

char	*ft_lstsize(t_clist *node, int fd)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = 0;
	while (fds[fd][size])
		size++;
	while (node)
	{
		i = 0;
		while (node->c[i++])
			size++;
		node = node->next;
	}
	res = malloc((size + 1) * sizeof(char));
	return (res);
}

char	*ft_catlst(t_clist *node, int fd)
{
	t_clist	*tmp;
	char	*res;
	int	i;
	int	j;

	i = -1;
	while (fds[fd][++i] && fds[fd][i] != '\n' || fds[fd][i] != EOF)
		res[i] = fds[fd][i];
	tmp = node;
	while (node)
	{
		j = 0;
		while (node->c[j] || node->c[j] != '\n' || node->c[j] != EOF)
			res[i++] = node->c[j++];
		node = node->next;
	}
	res[i] = 0;
	ft_stockandclear()
	ft_clstclr(tmp);
	return (res);
}

t_clist	*extract(int fd)
{
	char	*buff;
	ssize_t	check;
	int		i;
	t_clist	*node;

	node = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		check = read(fd, buff, BUFFER_SIZE);
		i = -1;
		while (buff[++i])
			if (buff[i] == '\n' || buff[i] == EOF)
				check = 0;
		if (!ft_clstback(&node, buff))
			return (0);
	}
	return (node);
}

int	ft_checkbuffer(char **fds)
{
	size_t	i;

	i = 0;
	if (!*fds)
		return (0);
	while ((*fds)[i])
	{
		if ((*fds)[i] == '\n' || (*fds)[i] == EOF)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_clist	*base;
	t_clist	*new;
	ssize_t	check;
	static	char*	fds[1024];
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	check = 1;
	base = 0;
	if (ft_checkbuffer(&(fds[fd])))
	while (base == 0 || (check == 1 && new->c != '\n'))
	{

		check = read(fd, new->c, BUFFER_SIZE);
		if (check == 0)
			free(new);
		else
			ft_clstback(&base, new);
	}
	if (check == -1)
		return (ft_clstclr(base));
	ft_catlst(base, ft_clstsize(base));
}
