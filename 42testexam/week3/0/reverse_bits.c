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
