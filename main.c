/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:39:53 by jde-carv          #+#    #+#             */
/*   Updated: 2025/05/04 02:35:03 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Abre o arquivo de teste
    fd = open("test.txt", O_RDONLY); // Substitua pelo nome do seu arquivo de teste
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Chama get_next_line uma vez para ver o que ela retorna
    line = get_next_line(fd);
    if (line)
    {
        printf("Linha retornada: %s\n", line); // Exibe o que foi lido
        free(line); // Libera a memória da linha
    }
    else
    {
        printf("Nenhuma linha retornada ou erro na leitura\n");
    }

    // Fecha o arquivo depois de terminar a leitura
    close(fd); 

    return (0);
}



