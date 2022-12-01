/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:04:54 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/08 13:49:42 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbword(const char *s, const char c)
{
	size_t	i;
	size_t	nb;
	size_t	is_sep;

	is_sep = 1;
	nb = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			is_sep = 1;
		else if (s[i] != c && is_sep)
		{
			is_sep = 0;
			nb++;
		}
		i++;
	}
	return (nb);
}

static void	*ft_freeall(char **src)
{
	int	i;

	i = 0;
	printf("start\n");
	printf("%p \n", src);
	while (src && !src[i])
	{
		printf("%d\n", i);
		free(src[i++]);
	}
	return (0);
}

static char	*ft_expl(char **r, const char *s, size_t current, size_t len)
{
	size_t	i;
	char	*res;

	res = ft_calloc(sizeof(char), len - current + 1);
	if (!res)
		return (ft_freeall(r));
	i = 0;
	while (current < len)
		res[i++] = s[current++];
	return (res);
}

static char	**ft_fsplit(char **res, const char *s, const char c)
{
	size_t	i;
	size_t	j;
	long	start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			res[j] = ft_expl(res, s, start, i);
			if (!res[j++])
			{
				free(res);
				return (0);
			}
			start = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	len;

	if (!s)
		return (0);
	len = ft_nbword(s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
	{
		free(res);
		return (0);
	}
	return (ft_fsplit(res, s, c));
}
