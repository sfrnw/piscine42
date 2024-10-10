#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int i;
	int space;
	space = 0;
	i = 0;

	if ((argc != 2) || (argv[1][0] == '\0'))
	{
		write(1,"\n",1);
		return(0);
	}
	else 
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			i++;
		}
		while (argv[1][i])
		{
			if ((argv[1][i] == ' ' || argv[1][i] == '\t'))	
			{ 
				if (space == 0)
				{
					write (1, " ", 1);
					space = 1;
				}
			}
			else 
			{
				write (1, &argv[1][i], 1);
				space = 0;
			}
			i++;
		}	
	}
	write(1,"\n",1);
	return (0);
}