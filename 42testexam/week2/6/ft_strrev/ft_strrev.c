#include <unistd.h>

char *ft_strrev(char *str)
{
	int length;
	int start;
	int end;
	char temp;
	
	start = 0;
	length = 0;
	
	while (str[length])
		length++;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
