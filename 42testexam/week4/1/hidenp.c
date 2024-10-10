/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:02:54 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 15:21:51 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	char *s1;
	char *s2;
	int i;
	int j;
	int answer;

	if (argc == 3)
	{
		i = 0;
		s1 = argv[1];
		s2 = argv[2];
		while (s2[i])
		{	
			j = 0;
			while (s1[j]&&s1[j]==s2[i+j])
			{
				j++;
			}
			i++;
		}
		if (s1[j]=='\0')
			write(1,"1",1);
		else 
			write(1,"0",1);
	}
	write(1,"\n",1);
	return(0);
}