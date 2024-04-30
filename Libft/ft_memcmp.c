/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 03:31:23 by moson             #+#    #+#             */
/*   Updated: 2023/03/27 03:31:23 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	cnt = 0;
	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	while (cnt < n)
	{
		if (ucs1[cnt] != ucs2[cnt])
		{
			return (ucs1[cnt] - ucs2[cnt]);
			break ;
		}
		cnt++;
	}
	return (0);
}
