/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:32 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/02 11:47:10 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(4 * size);
	if (*range == ((void *)0))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
// int main()
// {
//     int *range;
//     int size;
//     int min = 5;
//     int max = 10;
//     size = ft_ultimate_range(&range, min, max);
//     if (size == -1)
//     {
//         printf("Memory allocation failed\n");
//         return (1);
//     }
//     if (size == 0)
//     {
//         printf("Range is empty (min >= max)\n");
//         return (0);
//     }
//     printf("Size of range: %d\n", size);
//     printf("\n");
//     return (0);
// }