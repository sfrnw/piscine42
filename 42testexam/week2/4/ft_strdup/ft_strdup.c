#include <stdlib.h>


#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		len;

	while (src[len])
		++len;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	return (s);
}