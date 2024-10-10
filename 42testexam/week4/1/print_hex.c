/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:30 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 16:04:58 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

int print_hex (int n)
{
	char hex[] = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1,&hex[n%16],1);
	return(0);
}

int main (int argc, char **argv)
{
	int x;
	x = 0;
	if (argc == 2)
	{
		x = ft_atoi(argv[1]);
		print_hex(x);
	}
	write(1,"\n",1);
	return(0);
}
