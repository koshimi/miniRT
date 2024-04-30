/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:40:37 by moson             #+#    #+#             */
/*   Updated: 2023/03/28 23:40:38 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;
	int		count;

	size = ft_strlen(s1) + 1;
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		res[count] = s1[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}
