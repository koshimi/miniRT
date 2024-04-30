/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:57:55 by moson             #+#    #+#             */
/*   Updated: 2023/05/29 04:57:57 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	dec_to_hex_string(unsigned long long data, char *str, char *base)
{
	int	idx;

	idx = 0;
	if (data / 16 == 0)
	{
		str[idx] = base[data % 16];
		return (0);
	}
	else
	{
		idx = 1 + dec_to_hex_string(data / 16, str, base);
		str[idx] = base[data % 16];
		return (idx);
	}
}

int	uint_to_string(unsigned int data, char *str)
{
	int		idx;

	idx = 0;
	if (data / 10 == 0)
	{
		str[idx] = "0123456789"[data % 10];
		return (0);
	}
	else
	{
		idx = 1 + uint_to_string(data / 10, str);
		str[idx] = "0123456789"[data % 10];
		return (idx);
	}
}
