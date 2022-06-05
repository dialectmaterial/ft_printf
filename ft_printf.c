/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:23:13 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/12/13 13:15:59 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatlookup(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_printun(va_arg(args, unsigned long), print_len);
	else if (format == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long), print_len);
	else if (format == 'x' || format == 'X')
		print_len += ft_printhex(va_arg(args, long long), print_len, format);
	else if (format == '%')
		print_len += ft_printperc();
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	va_start(args, format);
	i = 0;
	print_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			print_len += formatlookup(args, *(format + 1));
			format++;
		}
		else
		{
			write(1, format, 1);
			print_len++;
		}
		format++;
	}
	va_end(args);
	return (print_len);
}
