/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:44:09 by moson             #+#    #+#             */
/*   Updated: 2024/05/06 17:44:10 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

//	NON-thread safe
void	cast_ray_simple(t_rt_dat *rt)
{
	int		x;
	int		y;
	double	unit_dist;

	unit_dist = get_ray_unit_dist(rt->cam->o_info.tr.forward[AXIS_Z], WIN_X, rt->cam->fov);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			if (x % DOWNSCLX == 0 && y % DOWNSCLY == 0)
				rt->col_buf[y][x] = apply_phong_shading(rt, x, y, unit_dist);
		}
	}
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			if (x % DOWNSCLX != 0 || y % DOWNSCLY != 0)
				rt->col_buf[y][x] = rt->col_buf[y - y % DOWNSCLY][x - x % DOWNSCLX];
	}
	return ;
}


void	cast_ray(t_rt_dat *rt)
{
	int		x;
	int		y;
	double	unit_dist;

	unit_dist = get_ray_unit_dist(rt->cam->o_info.tr.forward[AXIS_Z], WIN_X, rt->cam->fov);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			rt->col_buf[y][x] = apply_phong_shading(rt, x, y, unit_dist);
	}
	return ;
}

void	rt_draw_col_buf(t_rt_dat *rt)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
			mlx_draw_pixel(rt->my_mlx, vector2_int(x, y), rt->col_buf[y][x]);
	}
}
