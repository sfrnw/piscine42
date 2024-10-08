
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_ulstr(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            ft_putchar(*str + 32);
        else if (*str >= 'a' && *str <= 'z')
            ft_putchar(*str - 32);
        else
            ft_putchar(*str);
        str++;
    }
}

int main (int argc, char **argv)
{
 if (argc == 2)
        ft_ulstr(argv[1]);
    ft_putchar('\n');
    return (0);
}
