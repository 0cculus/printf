/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:54:22 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/22 16:15:03 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# ifndef UNSIGNI_MAX
#  define UNSIGNI_MAX 4294967295
# endif
# ifndef HEX
#  define HEX "0123456789abcdef"
# endif

char	*ft_utoa(unsigned int n);
char	*ft_tohex(unsigned long n);
int		ft_nbconvert(const int n);
int		ft_chrconvert(const char c);
int		ft_printf(const char *s, ...);
int		ft_strconvert(const char *src);
int		ft_ptrconvert(const uintptr_t p);
int		ft_unsignedconvert(const unsigned int n, const char convert);

#endif
