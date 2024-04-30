/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:13:48 by moson             #+#    #+#             */
/*   Updated: 2023/03/28 22:13:49 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size * count);
	if (res != NULL)
	{
		i = 0;
		while (i < size * count)
		{
			((unsigned char *)res)[i] = (unsigned char)0;
			i++;
		}
	}
	return (res);
}
