#include <unistd.h>
#include <stdarg.h>

void ft_str_null(char *str, int *leng)
{
    if (str == NULL)
        str = "(null)";
    while (*str)
        *leng += write(1, str++, 1);
}

void hex_digit(long long int nbr, int base, int *leng)
{
    if (nbr < 0)
    {
        nbr *= -1;
        *leng += write(1, "-", 1);
    }
    if (nbr >= base)
        hex_digit((nbr / base), base, leng);
    *leng += write(1, &"0123456789abcdef"[nbr % base], 1);
}

int ft_printf(const char *str, ...)
{
    int leng = 0;

    va_list pointer;
    va_start(pointer, str);

    while (*str)
    {
        if ((*str == '%') && *(str + 1))
        {
            str++;
            if (*str == 's')
                ft_str_null(va_arg(pointer, char *), &leng);
            else if (*str == 'd')
                hex_digit((long long int)va_arg(pointer, unsigned int), 10, &leng);
            else if (*str == 'x')
                hex_digit((long long int)va_arg(pointer, unsigned int), 16, &leng);
        }
        else
            leng += write(1, str, 1);
        str++;
    }
    va_end(pointer);
    return (leng);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf("%s\n", "toto");
// 	ft_printf("Magic %s is %d\n", "number", 42);
// 	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// 	return(0);
// }

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}