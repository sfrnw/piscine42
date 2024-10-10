/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:26:09 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 18:44:49 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char is_space(char c)
{
	if (c == ' ' || c == '\t')
		return(1);
	else 
		return (0);
}
char to_upper (char c)
{
	if (c>='a' && c<='z')
		c = c - 32;
	return (c);
}
char to_lower (char c)
{
	if (c>='A' && c<='Z')
		c = c + 32;
	return (c);
}
int is_letter (char c)
{
	if ((c>='A' && c<='Z') || (c>='a' && c<='z'))
		return (1);
	else 
		return (0);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	j = 0;
	i = 0;
	int new_word;
	new_word = 1;
	if (argc > 1)
	{
		while (i<argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!is_space(argv[i][j]))
				{	
					if (new_word)
						argv[i][j] = to_upper(argv[i][j]);
					else 
						argv[i][j] = to_lower(argv[i][j]);
					new_word = 0;
				}
				else 
					new_word = 1;
				write(1, &argv[i][j],1);
				j++;			
			}
			if (i < argc - 1)
                write(1, "\n", 1);
			i++;
		}
	}
	else 
		write(1,"\n",1);
	return 0;
}