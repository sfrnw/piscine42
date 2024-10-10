/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:48 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 17:45:11 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base (const char *str, int str_base)
{
	int sign;
	long long result; 
	int i;
	int digit;
	sign = 1;
	result = 0;
	i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i]<= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i]<= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i]<= 'Z')
			digit = str[i] - 'A' + 10;
		else 
			break;
		if (digit >= str_base)
			break;
		result = result*str_base + digit;
		i++;
	}
	return(result*sign);
}

int main()
{
    // Test cases
    printf("Base 10: 123 = %d\n", ft_atoi_base("123", 10));
    printf("Base 2: 1010 = %d\n", ft_atoi_base("1010", 2));
    printf("Base 16: FF = %d\n", ft_atoi_base("FF", 16));
    printf("Base 8: 70 = %d\n", ft_atoi_base("70", 8));
    printf("Negative Base 10: -42 = %d\n", ft_atoi_base("-42", 10));
    printf("Mixed case Base 16: 1Ab = %d\n", ft_atoi_base("1Ab", 16));
    printf("Invalid input Base 10: 12X34 = %d\n", ft_atoi_base("12X34", 10));
    printf("Base 4: 123 = %d\n", ft_atoi_base("123", 4));

    return 0;
}