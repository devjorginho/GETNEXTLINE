/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:31:04 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/04 02:27:11 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	has_new_line(char *saved)
{
	if (!saved)
		return (0);
	while (*saved)
	{
		if (*saved == '\n')
			return (1);
		saved++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*start;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	start = result;
	while (*s1)
		*start++ = *s1++;
	while (*s2)
		*start++ = *s2++;
	*start = '\0';
	return (result);
}

char	*pull_line(char *saved)
{
	char	*line;
	size_t	i;

	if (!saved || !*saved)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*update_saved(char *saved)
{
	int		i;
	int		j;
	char	*new_saved;

	i = 0;
	j = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free (saved);
		return (NULL);
	}
	new_saved = malloc(ft_strlen(saved) - i);
	if (!new_saved)
		return (NULL);
	i++;
	while (saved[i])
		new_saved[j++] = saved[i++];
	new_saved[j] = '\0';
	free (saved);
	return (new_saved);
}
