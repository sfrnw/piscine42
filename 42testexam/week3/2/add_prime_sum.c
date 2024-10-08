/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:20:12 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 11:41:27 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr( n / 10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}
int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int is_prime (int n)
{
	int i;
	i = 2;
	while (i < n)
	{
		if (!(n % i))
			return (0);
		i++;
	}
	return(1);
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	int num;
	num = ft_atoi(argv[1]);
	if (num <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}	
	int sum;
	int j;
	j = 2;
	sum = 0;
	while (j <= num)
	{
		if (is_prime(j))
			sum = sum + j;
		j++; 
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}