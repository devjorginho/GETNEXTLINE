/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:31:04 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/03 18:45:08 by jde-carv         ###   ########.fr       */
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

int	hasnewline(char *saved)
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

	if (!s1 || !s2)
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

char	*readandsave(int fd, char *saved)
{
	char	*buffer;
	int		readbytes;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (!has_newline(saved) && readbytes > 0)
	{
		if (!readbytes)
		{
			free (buffer);
			free (saved);
			return (NULL);
		}
		buffer[readbytes] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free (buffer);
	return (saved);
}
