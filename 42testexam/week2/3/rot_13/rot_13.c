#include <unistd.h>

int main (int argc, char ** argv)
{
	int i;
	i = 0;
	char str;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			str = argv[1][i];
			if (((argv[1][i] >= 'A')&&(argv[1][i] <= 'Z'))||((argv[1][i] >= 'a')&&(argv[1][i] <= 'z')))
			{
				if (((argv[1][i] >= 'A')&&(argv[1][i] <= 'M'))||((argv[1][i] >= 'a')&&(argv[1][i] <= 'm')))
					str = str + 13;
				else
					str = str - 13;
			}
			write (1, &str, 1);
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}