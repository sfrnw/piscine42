/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:49:11 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 14:49:51 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	separator_check(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*str)
	{
		if (!separator_check(*str, charset) && !inside_word)
		{
			inside_word = 1;
			count++;
		}
		else if (separator_check(*str, charset))
			inside_word = 0;
		str++;
	}
	return (count);
}

char	*get_next_word(char **str, char *charset)
{
	int		length;
	char	*word;
	int		i;

	length = 0;
	while ((*str)[length] && !separator_check((*str)[length], charset))
		length++;
	word = malloc(length + 1);
	if (!word)
		return ((void *)0);
	i = 0;
	while (i < length)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[length] = '\0';
	*str = *str + length;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**result;
	int		i;

	words = count_words(str, charset);
	result = malloc(8 * (words + 1));
	if (!result)
		return ((void *)0);
	i = 0;
	while (i < words)
	{
		while (*str && separator_check(*str, charset))
			str++;
		result[i] = get_next_word(&str, charset);
		if (!result[i])
			return ((void *)0);
		i++;
	}
	result[words] = ((void *)0);
	return (result);
}

// int	main()
// {
// 	char *str1 = "Hello,world,this,is,a,test";
// 	char *charset1 = ",";
// 	char *str2 = "   This   is   another   test   ";
// 	char *charset2 = " ";
// 	char *str3 = "NoSeparatorsHere";
// 	char *charset3 = ",";
// 	char *str4 = "";
// 	char *charset4 = ",";
// 	char **result;
// 	int i;

// 	printf("Test 1:\n");
// 	result = ft_split(str1, charset1);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != ((void *)0))
// 		{
// 			printf("%s\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	printf("\nTest 2:\n");
// 	result = ft_split(str2, charset2);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != ((void *)0))
// 		{
// 			printf("%s\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	printf("\nTest 3:\n");
// 	result = ft_split(str3, charset3);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != ((void *)0))
// 		{
// 			printf("%s\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	printf("\nTest 4 (empty string):\n");
// 	result = ft_split(str4, charset4);
// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != ((void *)0))
// 		{
// 			printf("%s\n", result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	return 0;
// }
