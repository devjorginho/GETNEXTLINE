/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:16:51 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/05 23:27:55 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	readbytes = 1;
	while (!has_new_line(line))
	{
		if (*buffer == '\0')
			readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
			return (line);
		line = copy_to_line(line, buffer);
		move_and_finish(buffer);
	}
	return (line);
}
//int main()
//{
//	int fd = open("test.txt", O_RDONLY);
//	char *str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	char *str2 = get_next_line(fd);
//	printf("%s", str2);
//	free(str2);
//	char *str3 = get_next_line(fd);
//	printf("%s", str3);
//	free(str3);
//	char *str4 = get_next_line(fd);
//	printf("%s", str4);
//	free(str4);
//}