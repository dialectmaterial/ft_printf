/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printnbr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:19:37 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/12/13 15:17:35 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printnbr(long i)
{
	int	counter;

	counter = 0;
	if (i < 0)
	{
		counter += ft_printchar('-');
		i *= -1;
	}
	if (i > 9)
		counter += ft_printnbr(i / 10);
	i = i % 10 + '0';
	counter += ft_printchar(i);
	return (counter);
}

int	ft_printun(unsigned int n, int print_len)
{
	if (n < 0)
		return (-1);
	if (n > 9)
		print_len += ft_printnbr(n / 10);
	n = n % 10 + '0';
	print_len += ft_printchar(n);
	return (print_len);
}

int	ft_printhex(unsigned int n, int print_len, const char format)
{
	char	*base;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		print_len += ft_printhex(n / 16, print_len, format);
	n = n % 16;
	print_len += ft_printchar(base[n]);
	return (print_len);
}

int	ft_printpointer(unsigned long n, int print_len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		print_len += ft_printpointer(n / 16, print_len);
	n = n % 16;
	print_len += ft_printchar(base[n]);
	return (print_len);
}

int	ft_printptr(unsigned long n, int print_len)
{
	write(1, "0x", 2);
	return (ft_printpointer(n, print_len) + 2);
}
