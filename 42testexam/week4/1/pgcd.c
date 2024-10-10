/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:30:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 15:41:03 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	char digit;
	if (n < 0)
	{
		write(1,"-",1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write (1,&digit,1);
}

int ft_atoi (char *str)
{
	int sign;
	long result; 
	int i;
	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i]>= 9 && str[i]<=13))
		i++;
	while ((str[i] == '-')||(str[i]== '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i]<= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return(result*sign);
}

int main (int argc, char **argv)
{
	int i1;
	int i2;
	int x;
	int answer;
	answer = 1;
	x = 2;

	if (argc == 3)
	{
		i1 = atoi(argv[1]);
		i2 = atoi(argv[2]);
		while (i2!=0)
		{
			x = i2;
			i2 = i1%i2;
			i1 = x;
			
		}
		ft_putnbr(x);
	}
	write (1,"\n",1);
	return (0);

}