/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:54:35 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/04 10:14:41 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int i;

	i = 128;
	while (octet >= 0 && i)
	{
		if (octet / i)
		{
			write(1,"1",1);
			octet = octet - i;
		}
		else
			write(1,"0",1);
		i = i / 2;
	}
}
