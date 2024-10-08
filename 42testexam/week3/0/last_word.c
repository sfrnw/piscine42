/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:52:52 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 17:10:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}
void last_word (char *str)
{
	int i;
	int start;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
	{
		i--;
	}
	if (i < 0)
	 	return;
	start = i;
	while (start >= 0 && str[start] != ' ' && str[start] != '\t')
	{
		start--;
	}
	start++;
	while (start <= i)
	{
		ft_putchar(str[start]);
		start++;
	}
}
int main (int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}