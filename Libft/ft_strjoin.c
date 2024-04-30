/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:23:21 by moson             #+#    #+#             */
/*   Updated: 2023/03/29 05:23:22 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*res;

	res_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * res_len);
	if (res != NULL)
	{
		res[0] = '\0';
		ft_strlcat(res, s1, (size_t)(-1));
		ft_strlcat(res, s2, (size_t)(-1));
	}
	return (res);
}
