/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:26:53 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/22 16:00:22 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned long n)
{
	int	size;

	size = 0;
	while (n > 15)
	{
		size++;
		n /= 16;
	}
	size++;
	return (size);
}

char	*ft_tohex(unsigned long n)
{
	char	*res;
	int		len;

	len = ft_counthex(n);
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (0);
	while (len--)
	{
		res[len] = HEX[n % 16];
		n /= 16;
	}
	return (res);
}

static int	ft_countudigit(unsigned int n)
{
	int	nb;

	nb = 0;
	while (n > 9)
	{
		nb++;
		n /= 10;
	}
	nb++;
	return (nb);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		nb;

	nb = ft_countudigit(n);
	res = ft_calloc(sizeof(char), nb + 1);
	if (!res)
		return (0);
	nb--;
	while (n > 9)
	{
		res[nb--] = n % 10 + '0';
		n /= 10;
	}
	res[nb] = n % 10 + '0';
	return (res);
	return (0);
}
