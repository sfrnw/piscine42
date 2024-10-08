/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:33:56 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 12:50:56 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr( n / 10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		int x1;
		int x2;
		int result;

		x1 = atoi(argv[1]);
		x2 = atoi(argv[2]);

		int temp;
		while (x2 != 0)
		{
			temp = x2;
			x2 = x1 % x2;
			x1 = temp;
		}
		ft_putnbr(x1);
	}
	write(1,"\n",1);
	return(0);
}