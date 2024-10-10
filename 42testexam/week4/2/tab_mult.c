/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:45:34 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 19:03:39 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

void ft_putnbr(int n)
{
	char digit;
	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write (1,&digit,1);
}

int main (int argc, char **argv)
{
	int n;
	int i;
	i = 1;
	if (argc < 2)
		write(1,"\n",1);
	else
	{
		n = ft_atoi(argv[1]);
		while (i < 10)
		{
			ft_putnbr(i);	
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(n*i);	
			write(1, "\n", 1);		
			i++;		
		}
	}
	return(0);
}