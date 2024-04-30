/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:35:27 by moson             #+#    #+#             */
/*   Updated: 2023/03/24 21:35:29 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dest_len;
	size_t	src_len;

	count = 0;
	dest_len = 0;
	while (dst[count] != '\0')
	{
		count++;
		dest_len++;
	}
	src_len = 0;
	while (count + 1 < dstsize && src[src_len] != '\0')
	{
		dst[count] = src[src_len];
		count++;
		src_len++;
	}
	dst[count] = '\0';
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len < dstsize)
		return (dest_len + src_len);
	else
		return (dstsize + src_len);
}
