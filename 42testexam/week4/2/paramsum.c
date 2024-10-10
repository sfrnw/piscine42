/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:18:01 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 18:23:48 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	char digit;
	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write (1,&digit,1);
}

int main(int argc, char **argv)
{
	int i;
	i = 0;
	if (argc == 1)
		write(1,"0",1);
	else 
	{
		while (argv[i])
			i++;
		i--;
		ft_putnbr(i);
	}
	write(1,"\n",1);
	return 0;
}