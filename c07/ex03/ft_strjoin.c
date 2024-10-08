/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:48:46 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/08 12:11:26 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_length(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total = total + ft_strlen(strs[i]);
		if (i < size - 1)
			total = total + ft_strlen(sep);
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	i = -1;
	if (size == 0)
	{
		result = malloc(1);
		if (result)
			*result = '\0';
		return (result);
	}
	result = malloc(total_length(size, strs, sep) + 1);
	if (!result)
		return ((void *)0);
	while (++i < size)
	{
		ft_strcpy(result, strs[i]);
		result = result + ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(result, sep);
			result = result + ft_strlen(sep);
		}
	}
	return (result - total_length(size, strs, sep));
}
// int main()
// {
//     // Example 1: Normal case
//     char *strs1[] = {"Hello", "world", "of", "programming"};
//     char *result1 = ft_strjoin(4, strs1, " ");
//     printf("Example 1: %s\n", result1);
//     free(result1);

//     // Example 2: Empty separator
//     char *strs2[] = {"Concatenate", "these", "words"};
//     char *result2 = ft_strjoin(3, strs2, "");
//     printf("Example 2: %s\n", result2);
//     free(result2);

//     // Example 3: Single string
//     char *strs3[] = {"Lonely"};
//     char *result3 = ft_strjoin(1, strs3, "---");
//     printf("Example 3: %s\n", result3);
//     free(result3);

//     // Example 4: Empty array (size 0)
//     char **strs4 = NULL;
//     char *result4 = ft_strjoin(0, strs4, "...");
//     printf("Example 4: '%s'\n", result4);
//     free(result4);

//     // Example 5: Long separator
//     char *strs5[] = {"One", "Two", "Three"};
//     char *result5 = ft_strjoin(3, strs5, " <-> ");
//     printf("Example 5: %s\n", result5);
//     free(result5);

//     return 0;
// }