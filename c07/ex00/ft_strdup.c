/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:47:55 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/02 11:20:23 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (src[length])
		length++;
	dup = (char *)malloc(length + 1);
	if (dup == ((void *)0))
		return ((void *)0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	*original;
// 	char	*duplicate;

// 	original = "Hello, World!";
// 	duplicate = ft_strdup(original);
// 	if (duplicate != NULL)
// 	{
// 		printf("Original string: %s\n", original);
// 		printf("Duplicated string: %s\n", duplicate);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
