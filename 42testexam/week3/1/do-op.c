/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:52:56 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 17:10:58 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc == 4)
	{
		if (*argv[2] == '+')
			printf("%d", atoi(argv[1]) + atoi(argv[3]));
		if (*argv[2] == '-')
			printf("%d", atoi(argv[1]) - atoi(argv[3]));
		if (*argv[2] == '*')
			printf("%d", atoi(argv[1]) * atoi(argv[3]));
		if (*argv[2] == '/')
			printf("%d", atoi(argv[1]) / atoi(argv[3]));
		if (*argv[2] == '%')
			printf("%d", atoi(argv[1]) % atoi(argv[3]));
	}
	printf("\n");
	return (0);
}


