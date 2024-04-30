/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 04:03:46 by moson             #+#    #+#             */
/*   Updated: 2023/03/27 04:03:47 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	haystack_len;
	size_t	needle_len;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len <= 0)
		return ((char *)haystack);
	cnt = 0;
	while (cnt + needle_len <= len && cnt + needle_len <= haystack_len)
	{
		if (ft_strncmp(&haystack[cnt], needle, needle_len) == 0)
			return (&((char *)haystack)[cnt]);
		cnt++;
	}
	return (NULL);
}
