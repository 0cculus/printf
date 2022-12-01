/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:43:25 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/22 16:35:47 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strconvert(const char *src)
{
	if (src)
	{
		ft_putstr_fd((char *)src, 1);
		return (ft_strlen(src));
	}
	ft_putstr_fd("(null)", 1);
	return (ft_strlen("(null)"));
}

int	ft_chrconvert(const char c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_unsignedconvert(const unsigned int n, const char convert)
{
	int		res_len;
	char	*res;

	res_len = 0;
	if (convert == 'x' || convert == 'X')
	{
		res = ft_tohex((unsigned long)n);
		if (convert == 'X')
				res = ft_toupper(res);
	}
	else
		res = ft_utoa(n);
	if (res)
	{
		res_len = ft_strlen(res);
		ft_putstr_fd(res, 1);
		free(res);
	}
	return (res_len);
}

int	ft_nbconvert(const int n)
{
	int		res_len;
	char	*res;

	res = ft_itoa(n);
	if (!res)
		return (0);
	res_len = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (res_len);
}

int	ft_ptrconvert(const uintptr_t p)
{
	int			res_len;
	char		*res;

	res = "0x";
	res_len = 1;
	ft_putstr_fd(res, 1);
	if (p)
	{
		res = ft_tohex(p);
		res_len = ft_strlen(res);
		ft_putstr_fd(res, 1);
		free(res);
		return (res_len + 2);
	}
	ft_putstr_fd("0", 1);
	return (ft_strlen(res) + 1);
}
