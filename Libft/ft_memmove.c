/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:02 by moson             #+#    #+#             */
/*   Updated: 2023/03/24 13:50:04 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				order;
	unsigned char	*src_start;
	unsigned char	*dst_start;
	size_t			cnt;

	if (dst == NULL && src == NULL)
		return (NULL);
	src_start = (unsigned char *)src;
	dst_start = (unsigned char *)dst;
	order = 1;
	if (src_start < dst_start)
	{
		src_start = src_start + len - 1;
		dst_start = dst_start + len - 1;
		order = -1;
	}
	cnt = 0;
	while (cnt != len)
	{
		*(dst_start + order * cnt) = \
		*(src_start + order * cnt);
		cnt++;
	}
	return (dst);
}
