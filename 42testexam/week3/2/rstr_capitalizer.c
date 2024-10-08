/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:10:23 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 13:41:29 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char to_upper(char c)
{
	if (c >='a' && c <= 'z')
		return (c - 32);
	return (c);
}
char to_lower(char c)
{
	if (c >='A' && c <= 'Z')
		return (c + 32);
	return (c);
}
char is_space(char c)
{
	return(c == ' ' || c == '\t');
}
char is_letter (char c)
{
	return ((c >='A' && c <= 'Z')||(c >='a' && c <= 'z'));
}
void rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || is_space(str[i - 1]))
			if (is_letter(str[i] && !str[i+1]))
				str[i] = to_upper(str[i]);
			else
				str[i] = to_lower(str[i]);
		else if ((is_letter(str[i]) && is_space(str[i+1])) || !str[i+1])
			str[i] = to_upper(str[i]);
		else
			str[i] = to_lower(str[i]);
		write(1,&str[i],1);
		i++;
	}
}

int main (int argc, char **argv)
{
	int i;
	i = 0;

	if (argc == 1)
		write(1,"\n",1);
	else
	{
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1,"\n",1);
			i++;
		}
	}
	return (0);
}