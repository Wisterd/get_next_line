/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:05:31 by mvue              #+#    #+#             */
/*   Updated: 2021/12/20 11:59:52 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char	*free_buff(char *buf)
{
	
}
*/

char	*ft_add_str(char *buf, char *full_str, int *flag, char **extra_read)
{
	size_t		i;
	char		*str_cpl;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (i == ft_strlen(buf))
	{
		str_cpl = ft_strdup(buf);
		full_str = ft_strjoin(full_str, str_cpl);
		if (*extra_read)
		{
			free(*extra_read);
			*extra_read = NULL;
		}
	}
	else
	{
		str_cpl = ft_substr(buf, 0, i + 1);
		*extra_read = ft_substr(buf, i + 1, ft_strlen(buf) - (i + 1));
		full_str = ft_strjoin(full_str, str_cpl);
		*flag = 1;
	}
	free(str_cpl);
	return (full_str);
}

char	*get_next_line(int fd)
{
	int					ret;
	static char			buf[BUFFER_SIZE + 1];
	static char			*extra_read = NULL;
	char				*full_str;
	int					flag;

	full_str = "";
	flag = 0;
	if (!extra_read)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	else
		full_str = ft_add_str(extra_read, full_str, &flag, &extra_read);
	while (flag == 0 && ret)
	{
		full_str = ft_add_str(buf, full_str, &flag, &extra_read);
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	if (!*full_str)
	{
		if (extra_read)
			free(extra_read);
		return(NULL);
	}
	return (full_str);
}

int	main(void)
{
	int	fd;
	char *res;

	res = "bonjour";
	fd = open("get_next_line.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	while(res)
	{
		res = get_next_line(fd);
		printf("%s", res);
	}
	free(res);
	if (close(fd) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}
