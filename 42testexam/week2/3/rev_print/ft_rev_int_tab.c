/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:07:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/09/20 09:30:11 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	t;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		t = tab[start];
		tab[start] = tab [end];
		tab[end] = t;
		start++;
		end--;
	}
}
