/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:59:09 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 13:08:57 by asafrono         ###   ########.fr       */
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

int is_prime(int n)
{
	int i;
	i = 2;
	
	if (n<2)
		return(0);
	while (i*i <= n)
	{
		if (!(n%i))
			return(0);
		i++;
	}
	return(1);
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
	int sum;
	int num;
	int x;
	sum = 0;
	x = 2;

	num = ft_atoi(argv[1]);
	if ((argc != 2) || (num<=0))
	{
		write(1,"0\n",2);
		return(0);
	}
	while (x <= num)
	{
		if (is_prime(x))
			sum = sum + x;
		x++;
	}
	ft_putnbr(sum);
	write (1, "\n",1);
	return(0);
}