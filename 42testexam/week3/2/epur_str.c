/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:42:52 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 11:58:36 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

void epur_str (char *str)
{
	int i;
	int space_flag;

	i = 0;
	space_flag = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (space_flag == 0)
			{
				ft_putchar(' ');
				space_flag = 1;
			}
		}
		else 
		{
			ft_putchar(str[i]);
			space_flag = 0;
		}
		i++;
	}

	
}

int main (int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	ft_putchar('\n');
	return (0);
}