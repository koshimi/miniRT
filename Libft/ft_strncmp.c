/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:36:32 by moson             #+#    #+#             */
/*   Updated: 2023/03/27 00:36:34 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	count = 0;
	while (us1[count] != '\0' && count < n)
	{
		if (us1[count] != us2[count])
			return ((int)(us1[count] - us2[count]));
		count++;
	}
	if (count == n)
		return (0);
	if (us2[count] != '\0')
		return ((-1) * us2[count]);
	return (0);
}
