/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:24:55 by moson             #+#    #+#             */
/*   Updated: 2023/03/24 21:25:01 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	srcsize;

	count = 0;
	srcsize = 0;
	while (count + 1 < dstsize)
	{
		if (src[count] != '\0')
		{
			srcsize++;
			dst[count] = src[count];
		}
		else
			break ;
		count++;
	}
	if (dstsize != 0)
		dst[count] = '\0';
	while (src[count] != '\0')
	{
		count++;
		srcsize++;
	}
	return (srcsize);
}
