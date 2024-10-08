/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:48:12 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 16:52:08 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strdup (char *src)
{
	char *dup;
	int length;
	int i;

	length = 0;
	i = 0;

	while (src[length])
		length++;
	dup = (char *)malloc(length+1);
	if (dup == NULL)
		return (NULL);
	while (src[i])
	{
		dup[i]=src[i];
		i++;
	}
	dup[i]='\0';
	return(dup);
}