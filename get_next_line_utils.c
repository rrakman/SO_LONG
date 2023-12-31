/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:49:27 by rrakman           #+#    #+#             */
/*   Updated: 2023/02/23 11:52:30 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free (s1);
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*mem;

	i = 0;
	mem = malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!mem || !s1)
		return (0);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*send_join(char *s1, char *s2)
{
	if (!s1)
	{
		s1 = ft_strdup("");
		return (ft_strjoin(s1, s2));
	}
	else
		return (ft_strjoin(s1, s2));
}
