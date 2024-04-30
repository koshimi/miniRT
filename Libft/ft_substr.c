/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:13:50 by moson             #+#    #+#             */
/*   Updated: 2023/03/29 00:13:52 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*res;
	size_t	cnt;

	s_len = ft_strlen(s);
	if (start + len > s_len)
	{
		if (s_len + 1 > (size_t)start)
			len = s_len + 1 - (size_t)start;
		else
			len = 1;
	}
	else
		len = len + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	cnt = 0;
	while (cnt + 1 < len)
	{
		res[cnt] = s[(size_t)start + cnt];
		cnt++;
	}
	res[cnt] = '\0';
	return (res);
}
