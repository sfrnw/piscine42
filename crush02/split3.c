/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:16:36 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/06 18:46:34 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARTS 13
#define PART_DIGITS 3

char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strcpy(char *dest, char *src);
unsigned long long	string_to_ull(const char *str);
void				ull_to_string(unsigned long long num, char *str);
void				split_number_100(unsigned long long number,
						unsigned long long *values, int *count);
void				create_1d_array(char result[PARTS][40][21],
						int result_counts[], char new_array[]);
void				initialize_arrays(char parts[PARTS][PART_DIGITS + 1],
						char result[PARTS][40][21], int result_counts[PARTS]);
char				*process_large_number(const char *very_large_number);
void				fill_leading_zeros(char parts[PARTS][PART_DIGITS + 1],
						int leading_zeros);
void				copy_and_pad_part(char *part, const char *full_string,
						int start, int to_copy);
void				split_to_parts(const char *full_string,
						char parts[PARTS][PART_DIGITS + 1]);
void				create_large_number_string(char *result, int zeros);
void				process_split_values(unsigned long long *split_values,
						int split_count, char result[][21], int *result_count);
void				create_large_numbers(char parts[PARTS][PART_DIGITS + 1],
						char result[PARTS][40][21], int result_counts[PARTS]);

void	create_1d_array(char result[PARTS][40][21], int result_counts[],
			char new_array[])
{
	int	i;
	int	j;
	int	new_array_size;

	new_array_size = 0;
	i = 0;
	while (i < PARTS)
	{
		j = 0;
		while (j < result_counts[i])
		{
			ft_strcpy(new_array + new_array_size, result[i][j]);
			new_array_size += strlen(result[i][j]);
			new_array[new_array_size++] = ' ';
			j++;
		}
		if (i < PARTS - 1 && result_counts[i + 1] > 0)
			new_array[new_array_size++] = ' ';
		i++;
	}
	if (new_array_size > 0)
		new_array_size--;
	new_array[new_array_size] = ' ';
	new_array[new_array_size + 1] = '\0';
}

void	initialize_arrays(char parts[PARTS][PART_DIGITS + 1],
			char result[PARTS][40][21], int result_counts[PARTS])
{
	int	i;
	int	j;

	i = 0;
	while (i < PARTS)
	{
		parts[i][0] = '\0';
		result_counts[i] = 0;
		j = 0;
		while (j < 40)
		{
			result[i][j][0] = '\0';
			j++;
		}
		i++;
	}
}

char	*process_large_number(const char *very_large_number)
{
	char		parts[PARTS][PART_DIGITS + 1];
	char		result[PARTS][40][21];
	int			result_counts[PARTS];
	static char	new_array[1000];

	if (very_large_number[0] == '0' && very_large_number[1] == '\0')
		return ("0 ");
	else
	{
		initialize_arrays(parts, result, result_counts);
		split_to_parts(very_large_number, parts);
		create_large_numbers(parts, result, result_counts);
		create_1d_array(result, result_counts, new_array);
		return (new_array);
	}
}

void	create_large_numbers(char parts[PARTS][PART_DIGITS + 1],
			char result[PARTS][40][21], int result_counts[PARTS])
{
	int					i;
	unsigned long long	number;
	unsigned long long	split_values[4];
	int					split_count;
	char				large_num_str[40];

	i = -1;
	while (++i < PARTS)
	{
		number = string_to_ull(parts[i]);
		if (number > 0)
		{
			split_count = 0;
			split_number_100(number, split_values, &split_count);
			process_split_values(split_values, split_count,
				result[i], &result_counts[i]);
			if (i < PARTS - 1)
			{
				create_large_number_string(large_num_str,
					((PARTS - i - 1) * 3));
				ft_strcpy(result[i][result_counts[i]], large_num_str);
				result_counts[i]++;
			}
		}
	}
}

int	main(void)
{
	const char	*very_large_number;
	char		*result;

	very_large_number = "123456789123456789123456789123456789";
	result = process_large_number(very_large_number);
	printf("Very large number: %s\n\n", very_large_number);
	printf("Processed result:\n%s\n", result);
	return (0);
}
