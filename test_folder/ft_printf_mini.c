#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

static int	print_str(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_print_char((int)*s);
		count++;
		s++;
	}
	return (count);
}

//

static int	print_digits(long nbr, int base)
{
	int		count;
	char	*symbols;

	//
	count = 0;
	symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (print_digits(-nbr, base) + 1);
	}
	else if (nbr < base)
	{
		return (ft_print_char(symbols[nbr]));
	}
	else
	{
		count = print_digits(nbr / base, base);
		return (count + print_digits(nbr % base, base));
	}
}

//

static int	ft_printformat(char specifier, va_list ap)
{
	int	count;

	//
	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digits((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += print_digits((long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

//

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_printformat(*(++format), ap);
		// why do  we pass the arg pointer ??
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int count;
	count = ft_printf("%d", INT_MAX);
	ft_printf(" the number os bytes written %d\n ", count);
	count = ft_printf("%x\n", 42);
	ft_printf("n is %d\n", count);
}