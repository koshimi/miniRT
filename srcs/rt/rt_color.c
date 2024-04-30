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
