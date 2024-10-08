#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	unsigned char divisor = 128;

	while (divisor > 0)
	{
		bit = (octet/divisor) + '0';
		write(1, &bit, 1);
		octet = octet % divisor;
		divisor = divisor / 2;
	}
}