/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:46:07 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 17:51:28 by asafrono         ###   ########.fr       */
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

int     *ft_range(int start, int end)
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
		return (NULL);
	while (i < size)
	{
		range[i] = start;
		start = start + step;
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
    int *range = ft_range(start, end);
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