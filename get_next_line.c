/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:01:46 by mvue              #+#    #+#             */
/*   Updated: 2021/12/21 19:07:29 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_extra_read(char *line_read)
{
	char	*extra_read;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line_read[++i] && line_read[i] != '\n')
		j++;
	if (!line_read[i])
	{
		free(line_read);
		return (NULL);
	}
	while (line_read[i])
		i++;
	extra_read = malloc(sizeof(char) * (i - j + 2));
	if (!extra_read)
	{
		free(line_read);
		return (NULL);
	}
	ft_strlcpy(extra_read, line_read + j + 1, i - j + 1);
	free(line_read);
	return (extra_read);
}

char	*ft_clean_line(char	*line_read)
{
	char	*clean_line;
	int		i;

	i = 0;
	if (!line_read[i])
		return (NULL);
	while (line_read[i] && line_read[i] != '\n')
		i++;
	clean_line = malloc(sizeof(char) * (i + 2));
	if (!clean_line)
		return (NULL);
	if (line_read[i] == '\n')
		ft_strlcpy(clean_line, line_read, i + 2);
	else
		ft_strlcpy(clean_line, line_read, i + 1);
	return (clean_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line_read;
	char		*clean_line;
	static char	*extra_read = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
		bytes_read = 1;
	while (!ft_strchr(extra_read, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		extra_read = ft_strjoin(extra_read, buff);
	}
	line_read = extra_read;
	if (!line_read)
		return (NULL);
	clean_line = ft_clean_line(line_read);
	extra_read = ft_get_extra_read(line_read);
	return (clean_line);
}
