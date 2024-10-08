/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:15:31 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/06 18:46:36 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARTS 13
#define PART_DIGITS 3

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned long long	string_to_ull(const char *str)
{
	unsigned long long	result;
	int					i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		i++;
	}
	return (result);
}

void	ull_to_string(unsigned long long num, char *str)
{
	char	rev[21];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (num > 0)
	{
		rev[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (i > 0)
	{
		str[j++] = rev[--i];
	}
	str[j] = '\0';
}

void	split_number_100(unsigned long long number,
		unsigned long long *values, int *count)
{
	unsigned int	tens;
	unsigned int	ones;
	unsigned int	hundreds;

	if (number < 20)
		values[(*count)++] = number;
	else if (number >= 20 && number <= 99)
	{
		tens = (number / 10) * 10;
		ones = number % 10;
		values[(*count)++] = tens;
		if (ones > 0)
			values[(*count)++] = ones;
	}
	else if (number >= 100 && number <= 999)
	{
		hundreds = number / 100;
		values[(*count)++] = hundreds;
		values[(*count)++] = 100;
		number = number % 100;
		if (number > 0)
			split_number_100(number, values, count);
	}
}
