/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:12:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 12:19:48 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *range;
	int size;	
	int i;
	int step;

	i = 0;
	if (start >= end)
	{
		size = start - end + 1;
		step = -1;
	}
	else
	{
		size = end - start + 1;
		step = 1;
	}
	range = (int *)malloc(sizeof(int)*size);
	if (!range)
		return NULL;
	while (i < size)
	{
		range [i] = end;
		end = end + step;
		i++;
	}
	return (range);
}