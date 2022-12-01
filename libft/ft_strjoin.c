/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:33:39 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/04 10:08:13 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_addstr(char *dest, const char *src, size_t current_i)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[current_i + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!res)
		return (0);
	if ((!s1 || !s1_len) && (!s2 || !s2_len))
		return (res);
	if (!s1 || !s1_len)
		return (ft_addstr(res, s2, 0));
	else if (!s2 || !s2_len)
		return (ft_addstr(res, s1, 0));
	res = ft_addstr(res, s1, 0);
	res = ft_addstr(res, s2, s1_len);
	res[s1_len + s2_len] = '\0';
	return (res);
}
