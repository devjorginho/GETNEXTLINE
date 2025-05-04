/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:20:22 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/04 22:31:45 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h> 

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	move_and_finish(char *buffer);
int		has_new_line(char *s);
char	*copy_to_line(char	*line, char *buffer);


#endif