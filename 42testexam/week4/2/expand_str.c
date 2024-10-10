/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:43:48 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 17:02:53 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int i;
	int word_printed;
	i = 0;

	if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    i = 0;
    word_printed = 0;

    while (argv[1][i] == ' ' || argv[1][i] == '\t')
        i++;

    while (argv[1][i])
    {
        if (argv[1][i] != ' ' && argv[1][i] != '\t')
        {
            write(1, &argv[1][i], 1);
            word_printed = 1;
        }
        else if (word_printed)
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i])
                write(1, "   ", 3);
            i--;
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}