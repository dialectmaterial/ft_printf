/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 12:33:42 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/12/13 13:39:48 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printnbr(long i);
int	ft_printhex(unsigned int n, int print_len, const char format);
int	ft_printptr(unsigned long n, int print_len);
int	ft_printun(unsigned int n, int print_len);
int	ft_printperc(void);

#endif
