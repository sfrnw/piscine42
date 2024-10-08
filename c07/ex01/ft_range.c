/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:14 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/02 11:20:25 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	diff;

	if (min >= max)
		return ((void *)0);
	diff = max - min;
	array = (int *)malloc(4 * diff);
	if (array == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < diff)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

// int	main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*result;
// 	int	i;
// 	int range;

// 	min = 5;
// 	max = 10;
// 	result = ft_range(min, max);
// 	if (result == NULL)
// 	{
// 		printf("Error: NULL pointer returned\n");
// 		return (1);
// 	}
// 	printf("Array elements: ");
// 	i = -1;
// 	range = max - min;
// 	while (++i < range)
// 		printf("%d ", result[i]);
// 	printf("\n");
// 	result = ft_range(max, min);
// 	if (result == NULL)
// 		printf("NULL pointer returned for min >= max, as expected\n");
// 	return (0);
// }