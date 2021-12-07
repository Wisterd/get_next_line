/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvue <mvue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:01:34 by mvue              #+#    #+#             */
/*   Updated: 2021/12/06 13:42:02 by mvue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + sizeof(char));
	i = -1;
	j = 0;
	if (!s3)
		return (NULL);
	else
	{
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[j])
			s3[i++] = s2[j++];
		s3[i] = '\0';
		return (s3);
	}
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cp;
	int		i;

	len = ft_strlen(s1);
	cp = (char *)malloc(len + 1);
	i = 0;
	if (!cp)
		return (NULL);
	else
	{
		while (i < len + 1)
		{
			cp[i] = s1[i];
			i++;
		}
	}
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	lenstart;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	lenstart = ft_strlen(s + start);
	if (len > lenstart)
		len = lenstart;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[++i])
	{
		if (j < len && i >= start)
		{
			sub[j] = s[i];
			j++;
		}
	}
	sub[j] = '\0';
	return (sub);
}
