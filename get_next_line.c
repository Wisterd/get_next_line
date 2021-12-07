/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:05:31 by mvue              #+#    #+#             */
/*   Updated: 2021/12/07 15:50:41 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next_line(int fd)
{
	int			ret;
	int			deb;
	int			fin;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	ret = 1;
	deb = 0;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", ret);
		buf[ret] = '\0';
		fin = deb;
		while (buf[fin] && buf[fin] != '\n')
			fin++;
		//printf(" deb = %d\n fin = %d\n", deb, fin);
		tmp = ft_substr(buf, deb, fin + 1);
		ft_putstr(tmp);
		//if (buf[fin] == '\n')
		//	ft_putstr("new line ");
	}
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
	get_next_line(fd);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}