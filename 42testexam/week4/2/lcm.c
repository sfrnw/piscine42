/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:54:02 by asafrono          #+#    #+#             */
/*   Updated: 2024/10/10 18:21:46 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int lcm(unsigned int a, unsigned int b)
{
	int x;
	int answer;
	x = 2;
	answer = 1;
	int hcd;
	hcd = 0;
;
	int i1 = a;
	int i2 = b;

	while (i2!=0)
	{
		hcd = i2;
		i2 = i1%i2;
		i1 = hcd;
	}
	
	
	if (a == 0 || b == 0)
		return (0);
	else 
	{
		while ( answer != (a*b/hcd) )
			answer++;
		return (answer);
	}
	
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <start> <end>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
	int result = lcm(a,b);
	printf("LCM of %u and %u is %u\n", a, b, result);
    
	return 0;
}