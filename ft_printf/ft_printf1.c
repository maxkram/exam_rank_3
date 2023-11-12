#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	// size = ft_printf("%s\n", "toto");
	printf("%d\n", ft_printf("%s\n", "toto"));
	// size = printf("%s\n", "toto");
	printf("%d\n", printf("%s\n", "toto"));
	// size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", ft_printf("Magic %s is %d\n", "number", 42));
	// size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", printf("Magic %s is %d\n", "number", 42));
	// size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", ft_printf("Hexadecimal for %d is %x\n", 42, 42));
	// size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", printf("Hexadecimal for %d is %x\n", 42, 42));
	// size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX));
	// size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX));
	// size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", ft_printf("%d, %d\n", 0, -24));
	// size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", ft_printf("%d, %d\n", 0, -24));
	// printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}