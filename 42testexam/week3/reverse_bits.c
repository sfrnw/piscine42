/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:16:05 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/03 17:16:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char reverse_bits (char b)
{
	char r = 0;
	char char_length = 8;
	while (char_length--)
	{
		r = (r * 2) + ( b & 1);
		b = b / 2;
	}
	return (r);
}