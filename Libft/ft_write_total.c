/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_total.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:21:32 by moson             #+#    #+#             */
/*   Updated: 2023/05/29 03:21:33 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	dec_to_hex_string(unsigned long long data, char *str, char *base);
int	uint_to_string(unsigned int data, char *str);

int	write_total(int total_bytes, const void *buf, size_t len)
{
	int	write_ret;

	write_ret = write(1, buf, len);
	if (write_ret == -1)
		return (-1);
	else
		return (write_ret + total_bytes);
}

int	write_char_total(int total_bytes, char c)
{	
	int	write_ret;

	write_ret = write(1, &c, 1);
	if (write_ret == -1)
		return (-1);
	else
		return (write_ret + total_bytes);
}

int	write_string_total(int total_bytes, const void *buf)
{
	size_t	len;

	if (buf == 0x0)
		return (write_total(total_bytes, "(null)", 6));
	else
	{
		len = ft_strlen((char *)buf);
		return (write_total(total_bytes, buf, len));
	}
}

int	write_addr_total(int total_bytes, unsigned long long data, char option)
{
	char	str[19];

	str[0] = '0';
	str[1] = 'x';
	if (option == 'X')
		str[dec_to_hex_string(data, &str[2], "0123456789ABCDEF") + 3] = '\0';
	else
		str[dec_to_hex_string(data, &str[2], "0123456789abcdef") + 3] = '\0';
	return (write_string_total(total_bytes, &str[!(option == 'p') * 2]));
}

int	write_int_total(int total_bytes, unsigned int data, char option)
{
	char	str[12];

	str[0] = '-';
	if (option == 'u' || !((data >> 31) & 1))
		str[uint_to_string(data, &str[0]) + 1] = '\0';
	else
	{
		if ((data >> 31) & 1)
			data = ~data + 1;
		str[uint_to_string(data, &str[1]) + 2] = '\0';
	}
	return (write_string_total(total_bytes, &str));
}
