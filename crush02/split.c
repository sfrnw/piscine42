/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:29:38 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/06 18:46:37 by asafrono         ###   ########.fr       */
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
void				create_large_numbers(char parts[PARTS][PART_DIGITS + 1],
						char result[PARTS][40][21], int result_counts[PARTS]);

void	copy_and_pad_part(char *part, const char *full_string,
			int start, int to_copy)
{
	int	j;

	ft_strncpy(part, full_string + start, to_copy);
	part[to_copy] = '\0';
	if (to_copy < PART_DIGITS)
	{
		j = PART_DIGITS;
		while (j >= PART_DIGITS - to_copy)
		{
			part[j] = part[j - (PART_DIGITS - to_copy)];
			j--;
		}
		j = 0;
		while (j < PART_DIGITS - to_copy)
		{
			part[j] = '0';
			j++;
		}
	}
}

void	split_to_parts(const char *full_string,
		char parts[PARTS][PART_DIGITS + 1])
{
	int	parts_filled;
	int	leading_zeros;
	int	i;
	int	start;
	int	to_copy;

	parts_filled = (strlen(full_string) + PART_DIGITS - 1) / PART_DIGITS;
	leading_zeros = PARTS - parts_filled;
	i = PARTS - 1;
	start = strlen(full_string);
	while (i >= leading_zeros && start > 0)
	{
		if (start >= PART_DIGITS)
			to_copy = PART_DIGITS;
		else
			to_copy = start;
		start -= to_copy;
		copy_and_pad_part(parts[i], full_string, start, to_copy);
		i--;
	}
	i = leading_zeros - 1;
	while (--i >= 0)
		ft_strcpy(parts[i], "000");
}

void	create_large_number_string(char *result, int zeros)
{
	int	i;

	result[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		result[i] = '0';
		i++;
	}
	result[zeros + 1] = '\0';
}

void	process_split_values(unsigned long long *split_values, int split_count,
			char result[][21], int *result_count)
{
	int	j;

	j = 0;
	while (j < split_count)
	{
		ull_to_string(split_values[j], result[*result_count]);
		(*result_count)++;
		j++;
	}
}
