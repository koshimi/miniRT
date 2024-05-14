/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:06:44 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/14 13:59:12 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parse.h"

void	parse_coordinate(char **str, t_vector3_double *pos)
{
	pos->x = ft_atod(str, ",");
	clip_double(-MAX_WORLD_SIZE, MAX_WORLD_SIZE, &pos->x);
	pos->y = ft_atod(str, ",");
	clip_double(-MAX_WORLD_SIZE, MAX_WORLD_SIZE, &pos->y);
	pos->z = ft_atod(str, " \t");
	clip_double(-MAX_WORLD_SIZE, MAX_WORLD_SIZE, &pos->z);
	next_info(str);
}

void	seperate_color(char **str, int *color, char *symbol)
{
	int	result;
	int	sign;

	if (!ft_isdigit(**str) && **str != '-')
		parse_error();
	sign = 1;
	result = 0;
	if (**str == '-' || **str == '+')
		if (*(*str)++ == '-')
			sign = -sign;
	while (**str && ft_isdigit(**str))
		result = result * 10 + *(*str)++ - '0';
	if (!check_symbol(**str, symbol))
		parse_error();
	if (**str)
		++*str;
	*color = result * sign;
	clip_int(0, 255, color);
}

void	parse_color(char **str, t_rt_color *color)
{
	seperate_color(str, &color->r, ",");
	seperate_color(str, &color->g, ",");
	seperate_color(str, &color->b, "\t \n");
	next_info(str);
	while (**str && check_symbol(**str, "\t \n"))
		++*str;
}

void	parse_forward(char **str, t_vector3_double *forward)
{
	forward->x = ft_atod(str, ",");
	clip_double(-1.0, 1.0, &forward->x);
	forward->y = ft_atod(str, ",");
	clip_double(-1.0, 1.0, &forward->y);
	forward->z = ft_atod(str, "\t ");
	clip_double(-1.0, 1.0, &forward->z);
	next_info(str);
}

double	ft_atod(char **str, char *symbol)
{
	double	sign;
	double	ret;
	int		decimal;

	init_variable(&sign, &ret, &decimal, str);
	if (!ft_isdigit(**str) && **str != '-')
		parse_error();
	while (**str && ft_isdigit(**str))
		ret = ret * 10 + (*(*str)++ - '0');
	if (check_symbol(**str, symbol))
	{
		++*str;
		return (ret * sign);
	}
	if (**str == '.')
		++*str;
	while (**str && ft_isdigit(**str))
	{
		ret = ret * 10 + (*(*str)++ - '0');
		++decimal;
	}
	if (**str)
		++*str;
	return (ret * pow(10.0, -decimal) * sign);
}
