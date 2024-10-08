/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:15:24 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 10:24:13 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void wdmatch(char *s1, char *s2)
{
	int length;
	int i;
	int j;

	length = 0;
	i = 0;
	j = 0;
	while  (s1[length])
		length++;
	while (s2[j] && i < length)
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (i == length)
		write (1, s1, length);
}
int main (int argc, char **argv)
{	
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write (1, "\n", 1);
	return (0);
}