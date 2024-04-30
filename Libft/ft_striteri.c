/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:32:43 by moson             #+#    #+#             */
/*   Updated: 2023/03/31 15:32:46 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	s_len;
	size_t	cnt;

	s_len = ft_strlen(s);
	cnt = 0;
	while (cnt < s_len)
	{
		(*f)((unsigned int)cnt, &s[cnt]);
		cnt++;
	}
	return ;
}
