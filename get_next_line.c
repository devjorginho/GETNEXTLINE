/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:30:58 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/04 02:25:15 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int	readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
		saved = ft_strjoin(saved, "");
	readbytes = 1;
	while (!has_new_line(saved) && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
			return (NULL);
		buffer[readbytes] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	line = pull_line(saved);
	saved = update_saved(saved);
	return (line);
}
