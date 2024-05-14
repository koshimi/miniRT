/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:02:47 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 10:41:44 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

void	check_misconfig(char *str)
{
	while (*str && *str != '\n')
	{
		if (!check_symbol(*str, "\t .,-+") && !ft_isdigit(*str))
			parse_error();
		++str;
	}
}

int	check_symbol(char c, char *symbol)
{
	if (c == 0)
		return (1);
	while (*symbol)
	{
		if (c == *symbol)
			return (1);
		++symbol;
	}
	return (0);
}

void	parse_error(void)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("misconfiguration in *.rt file", 1);
	exit(1);
}
