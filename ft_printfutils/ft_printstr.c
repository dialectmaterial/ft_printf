/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:19:33 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/12/13 13:16:11 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printperc(void)
{
	write(1, "%", 1);
	return (1);
}
