/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:55:01 by jla-chon          #+#    #+#             */
/*   Updated: 2023/11/22 15:45:33 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int next_read_error = 0;

#define test_gnl(fd, expected) res = test_gnl_func(fd, expected, _title) && res;

int main(void)
{
	int fd = open("fsoares/1char.txt", O_RDONLY);
	char *a;
	a = get_next_line(fd);
	free(a);
	a = get_next_line(fd);
	free(a);
	// // /* 1 */ test_gnl(fd, "aaaaaaaaaa\n");
	// // /* 2 */ test_gnl(fd, "bbbbbbbbbb\n");
	// // set the next read call to return -1
	// close(fd);
	// a = get_next_line(fd);
	// free(a);
	// // /* 3 */ test_gnl(fd, NULL);

	// fd = open("read_error.txt", O_RDONLY);
	// a = get_next_line(fd);
	// free(a);
	// a = get_next_line(fd);
	// free(a);
	// a = get_next_line(fd);
	// free(a);
	// a = get_next_line(fd);
	// free(a);
	// a = get_next_line(fd);
	// free(a);
	// // /* 4 */ test_gnl(fd, "aaaaaaaaaa\n");
	// // /* 5 */ test_gnl(fd, "bbbbbbbbbb\n");
	// // /* 6 */ test_gnl(fd, "cccccccccc\n");
	// // /* 7 */ test_gnl(fd, "dddddddddd\n");
	// // /* 8 */ test_gnl(fd, NULL);
	return (0);
}
