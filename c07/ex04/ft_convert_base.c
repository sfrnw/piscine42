/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:49:03 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 12:45:12 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		check_base(char *base);
int		get_index(char c, char *base);
int		ft_atoi_base(char *str, char *base);
int		get_converted_length(int nbr, int base_len);
char	*handle_zero(char *base_to);
void	convert_number(char *result, int num, char *base_to, int is_negative);

int	get_converted_length(int nbr, int base_len)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		length++;
	while (nbr)
	{
		nbr = nbr / base_len;
		length++;
	}
	return (length);
}

char	*handle_zero(char *base_to)
{
	char	*result;

	result = (char *)malloc(1 * 2);
	if (!result)
		return ((void *)0);
	result[0] = base_to[0];
	result[1] = '\0';
	return (result);
}

void	convert_number(char *result, int num, char *base_to, int is_negative)
{
	int				length;
	int				base_to_length;
	unsigned int	abs_num;

	if (is_negative)
	{
		abs_num = -num;
		result[0] = '-';
	}
	else
		abs_num = num;
	base_to_length = ft_strlen(base_to);
	length = get_converted_length(num, base_to_length);
	while (length > is_negative)
	{
		result[--length] = base_to[abs_num % base_to_length];
		abs_num = abs_num / base_to_length;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_to_length;
	int		length;
	char	*result;
	int		is_negative;

	if (!check_base(base_from) || !check_base(base_to))
		return ((void *)0);
	num = ft_atoi_base(nbr, base_from);
	base_to_length = ft_strlen(base_to);
	length = get_converted_length(num, base_to_length);
	result = (char *)malloc(8 * (length + 1));
	if (!result)
		return ((void *)0);
	result[length] = '\0';
	if (num == 0)
		return (handle_zero(base_to));
	is_negative = 0;
	if (num < 0)
		is_negative = 1;
	convert_number(result, num, base_to, is_negative);
	return (result);
}

// int main() {
//     char *result;

//     // Test 1: Decimal to Binary
//     printf("Test 1: Decimal to Binary\n");
//     result = ft_convert_base("42", "0123456789", "01");
//     printf("42 (base 10) = %s (base 2)\n", result);
//     free(result);

//     // Test 2: Binary to Hexadecimal
//     printf("\nTest 2: Binary to Hexadecimal\n");
//     result = ft_convert_base("101010", "01", "0123456789ABCDEF");
//     printf("101010 (base 2) = %s (base 16)\n", result);
//     free(result);

//     // Test 3: Hexadecimal to Decimal
//     printf("\nTest 3: Hexadecimal to Decimal\n");
//     result = ft_convert_base("2A", "0123456789ABCDEF", "0123456789");
//     printf("2A (base 16) = %s (base 10)\n", result);
//     free(result);

//     // Test 4: Negative number
//     printf("\nTest 4: Negative number\n");
//     result = ft_convert_base("-42", "0123456789", "01");
//     printf("-42 (base 10) = %s (base 2)\n", result);
//     free(result);

//     // Test 5: Zero
//     printf("\nTest 5: Zero\n");
//     result = ft_convert_base("0", "0123456789", "01");
//     printf("0 (base 10) = %s (base 2)\n", result);
//     free(result);

//     // Test 6: Large number
//     printf("\nTest 6: Large number\n");
//     result = ft_convert_base("1000000", "0123456789", "01");
//     printf("1000000 (base 10) = %s (base 2)\n", result);
//     free(result);

//     // Test 7: Invalid base
//     printf("\nTest 7: Invalid base\n");
//     result = ft_convert_base("42", "01234567899", "01");
//     if (result == NULL)
//         printf("Correctly returned NULL for invalid base\n");
//     else
//         free(result);

//     // Test 8: INT_MIN
//     printf("\nTest 8: INT_MIN\n");
//     result = ft_convert_base("-2147483648", "0123456789", "01");
//     printf("-2147483648 (base 10) = %s (base 2)\n", result);
//     free(result);

//     return 0;
// }
