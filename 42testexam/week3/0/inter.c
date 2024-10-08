/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:18:29 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 15:48:52 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void solve (char *str1, char *str2)
{
	int i;
	int j;
	int ascii[256];
	int x;

	x = 0;
	while (ascii[x])
	{
		ascii[x] = 0;
		x++;
	}
	i = 0;
	while (str2[i])
	{
		ascii[str2[i]] = 1;
		i++;
	}
	i = 0;
	while (str1[i])
	{
		if (ascii[str1[i]] == 1)
		{
			write(1,&str1[i],1);
			ascii[str1[i]] = 2;
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 3)
		solve(argv[1], argv[2]);
	write (1,"\n",1);
	return (0);
}