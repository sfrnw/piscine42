/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:01 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 16:39:04 by asafrono         ###   ########.fr       */
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


int main (int argc, char **argv)
{
	int i;
	int j;
	i = 1;

	if (argc > 1)
	{
		while (i<argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (is_letter(argv[i][j]) && (argv[i][j+1] == '\0' || (is_space(argv[i][j+1]))))
					argv[i][j] = to_upper (argv[i][j]);
				else if (is_letter(argv[i][j]))
					argv[i][j] = to_lower (argv[i][j]);
				write(1,&argv[i][j],1);
				j++;
			}
			if (i < argc - 1)
                write(1, "\n", 1);
			i++;
		}
	}
	write (1,"\n",1);
	return(0);
}