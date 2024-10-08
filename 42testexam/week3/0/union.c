/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:53:22 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 18:16:34 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{

	int ascii[256];
	int x;
	int i;
	int j;

	x = 0;
	while (x < 256)
	{
		ascii[x] = 0;
		x++;
	}
	if (argc == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (ascii[(char)argv[i][j]] == 0)
				{
					write(1, &argv[i][j], 1);
					ascii[(char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
