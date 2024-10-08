#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void last_world(char *str)
{
	int i;
	int start;

	i = 0;
	while (str[i])
		i++;
	
	i--;
	while (i >= 0 && (str[i]== ' ' || str[i] == '\t'))
	{
		i--;
	}
	if (i < 0)
		return;
	
	start = i;
	while (start >=0 && str[start] != ' ' && str[i] != '\t')
	{
		start--;		
	}
	
	start++;
	while (start <= i)
	{
		ft_putchar(str[start]);
		start++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
		last_world(argv[1]);
	ft_putchar('\n');
	return (0);
}