/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:38:26 by moson             #+#    #+#             */
/*   Updated: 2023/03/27 00:38:27 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	*ucs;
	size_t			cnt;

	res = 0x0;
	ucs = (unsigned char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if (ucs[cnt] == (unsigned char)c)
		{
			res = &ucs[cnt];
			break ;
		}
		cnt++;
	}
	return (res);
}
