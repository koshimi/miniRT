/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:12:12 by moson             #+#    #+#             */
/*   Updated: 2023/03/31 15:12:13 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_len;
	size_t	cnt;

	s_len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (s_len + 1));
	if (res != NULL)
	{
		cnt = 0;
		while (cnt < s_len)
		{
			res[cnt] = (*f)((unsigned int)cnt, s[cnt]);
			cnt++;
		}
		res[cnt] = '\0';
	}
	return (res);
}
