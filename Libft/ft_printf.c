/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:29:08 by moson             #+#    #+#             */
/*   Updated: 2023/05/21 19:29:09 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int		write_total(int total_bytes, const void *buf, size_t len);
int		write_char_total(int total_bytes, char c);
int		write_string_total(int total_bytes, const void *buf);
int		write_addr_total(int total_bytes, unsigned long long data, char option);
int		write_int_total(int total_bytes, unsigned int data, char option);

static char	is_option(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' \
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	else
		return (0);
}

static int	ft_printf_options(va_list *vl, int total_bytes, char option)
{
	void	*va_addr;

	if (option == 's' || option == 'p')
		va_addr = va_arg(*vl, void *);
	if (option == 'c')
		return (write_char_total(total_bytes, (char)va_arg(*vl, int)));
	else if (option == 's')
		return (write_string_total(total_bytes, va_addr));
	else if (option == 'p')
		return (write_addr_total \
		(total_bytes, (unsigned long long)va_addr, option));
	else if (option == 'd' || option == 'i' || option == 'u')
		return (write_int_total \
		(total_bytes, (unsigned int)va_arg(*vl, unsigned int), option));
	else if (option == 'x' || option == 'X')
		return (write_addr_total \
		(total_bytes, va_arg(*vl, unsigned int), option));
	else if (option == '%')
		return (write_total(total_bytes, &option, 1));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	int		cnt;
	char	option;
	int		total_bytes;

	total_bytes = 0;
	va_start(vl, str);
	cnt = 0;
	while (str[cnt] != '\0' && total_bytes != -1)
	{
		if (str[cnt] == '%')
		{
			option = is_option(str[cnt + 1]);
			total_bytes = ft_printf_options(&vl, total_bytes, option);
			cnt++;
		}
		else
			total_bytes = write_total(total_bytes, &str[cnt], 1);
		cnt++;
	}
	va_end(vl);
	return (total_bytes);
}
