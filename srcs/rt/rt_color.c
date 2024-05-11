/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:44:39 by moson             #+#    #+#             */
/*   Updated: 2024/03/31 11:44:42 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_rt_color	rt_color_mult(t_rt_color col, double val)
{
	col.r *= val;
	col.g *= val;
	col.b *= val;
	if (col.r < 0)
		col.r = 0;
	else if (255 < col.r)
		col.r = 255;
	if (col.g < 0)
		col.g = 0;
	else if (255 < col.g)
		col.g = 255;
	if (col.b < 0)
		col.b = 0;
	else if (255 < col.b)
		col.b = 255;
	return (col);
}

t_rt_color	rt_color_add(t_rt_color col, t_vector3_int add)
{
	col.r += add.x;
	col.g += add.y;
	col.b += add.z;
	if (col.r < 0)
		col.r = 0;
	else if (255 < col.r)
		col.r = 255;
	if (col.g < 0)
		col.g = 0;
	else if (255 < col.g)
		col.g = 255;
	if (col.b < 0)
		col.b = 0;
	else if (255 < col.b)
		col.b = 255;
	return (col);
}

t_rt_color	rt_no_hit_color(void)
{
	return (rt_color(0, 0, 0, 0.0));
}

//	Error color = Magenta(255, 0, 255, 0.0);
t_rt_color	rt_color(int r, int g, int b, double a)
{
	t_rt_color	res;

	res.r = 255;
	res.g = 0;
	res.b = 255;
	res.a = 0.0;
	if (r < 0 || 255 < r)
		return (res);
	if (g < 0 || 255 < g)
		return (res);
	if (b < 0 || 255 < b)
		return (res);
	if (a < 0.0 || 1.0 < a)
		return (res);
	res.r = r;
	res.g = g;
	res.b = b;
	res.a = a;
	return (res);
}

unsigned int	mlx_rt_color_to_uint(t_rt_color color)
{
	unsigned int	res;

	if (0.99 < color.a)
		res = ((unsigned int)255) << 24;
	else if (color.a < 0.01)
		res = ((unsigned int)0) << 24;
	else
		res = ((unsigned int)(255.0 * color.a)) << 24;
	res += ((unsigned int)color.r) << 16;
	res += ((unsigned int)color.g) << 8;
	res += ((unsigned int)color.b);
	return (res);
}
