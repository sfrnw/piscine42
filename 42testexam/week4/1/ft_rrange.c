/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:13:40 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 15:02:04 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putnbr(int n)
{
	char digit;
	if (n < 0)
	{
		write(1,"-",1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write (1,&digit,1);
}

int     *ft_rrange(int start, int end)
{
	int *range;
	int size;
	int i;
	int step;
	i = 0;
	size = start - end;

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
		return (NULL);
	while (i < size)
	{
		range[i] = end;
		end = end - step;
		i++;
	}
	return (range);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <start> <end>\n", argv[0]);
        return 1;
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int *range = ft_rrange(start, end);
    int size = (start > end) ? (start - end + 1) : (end - start + 1);

    for (int i = 0; i < size; i++)
    {
        ft_putnbr(range[i]);
        write(1, " ", 1);  // Add a space between numbers
    }
    write(1, "\n", 1);  // Add a newline at the end

    free(range);  // Don't forget to free the allocated memory
    return 0;
}


// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.