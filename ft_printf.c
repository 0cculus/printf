/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:41:21 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/22 16:41:34 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isconversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

static int	ft_convert(const char c, va_list *lst)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_chrconvert(va_arg(*lst, int));
	else if (c == 's')
		res = ft_strconvert(va_arg(*lst, char *));
	else if (c == '%')
		res = ft_chrconvert('%');
	else if (c == 'i' || c == 'd')
		res = ft_nbconvert(va_arg(*lst, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		res = ft_unsignedconvert(va_arg(*lst, unsigned int), c);
	else if (c == 'p')
		res = ft_ptrconvert(va_arg(*lst, uintptr_t));
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		nb;
	va_list	al;

	va_start(al, s);
	nb = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%' && ft_isconversion(s[i + 1]))
			nb += ft_convert(s[++i], &al);
		else
		{
			if (s[i] != '%')
			{
				write(1, &s[i], 1);
				nb++;
			}
		}
		i++;
	}
	va_end(al);
	return (nb);
}
