/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:37:38 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/03 17:08:33 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	size_t			s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return (0);
	res = ft_calloc(s_len + 1, sizeof(char));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
