/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:05:31 by mvue              #+#    #+#             */
/*   Updated: 2021/12/05 23:45:17 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	get_next_line(int fd)
{
	int		read;
	char	buf(BUF_SIZE);

	ret = read(fd, buf, BUFSIZE);
}

int main(void)
{
	int	fd;

	fd = open("get_next_line.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}