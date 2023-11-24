/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:55:01 by jla-chon          #+#    #+#             */
/*   Updated: 2023/11/23 17:00:21 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char *s;
	int fd = open("fsoares/1char.txt", O_RDONLY);
	s = get_next_line(fd);
	s = get_next_line(fd);
	s = get_next_line(fd);
	s = get_next_line(fd);
	s = get_next_line(fd);
	s = get_next_line(fd);
	return (0);
}
