/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:20:19 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 12:32:56 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_find (char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i]==s2[j])
			i++;
		j++;
	}
	return (s1[i]=='\0');
}

int main (int argc, char **argv)
{
	char result;
	if (argc == 3)
	{
		result = ft_find(argv[1], argv[2])+'0';
		write (1,&result,1);
	}
	write (1,"\n",1);
	return (0);
}