/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:59:27 by moson             #+#    #+#             */
/*   Updated: 2023/03/21 08:59:29 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (cnt != n)
	{
		*((unsigned char *)dst + cnt) = *((unsigned char *)src + cnt);
		cnt++;
	}
	return (dst);
}
