/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:21:45 by moson             #+#    #+#             */
/*   Updated: 2024/03/31 10:21:47 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	mlx_draw_pixel(t_mlx *my_mlx, t_vector2_int v, t_rt_color col)
{
	char	*dst;

	if ((v.x < 0) || (WIN_X <= v.x) \
		|| (v.y < 0) || (WIN_Y <= v.y))
		return ;
	dst = my_mlx->img.addr + (v.y * my_mlx->img.line_length \
		+ v.x * (my_mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = mlx_rt_color_to_uint(col);
	return ;
}

void	mlx_draw_black_screen(t_mlx *my_mlx)
{
	t_rt_color		col;
	t_vector2_int	v;

	v.y = 0;
	while (v.y < WIN_Y)
	{
		v.x = 0;
		while (v.x < WIN_X)
		{
			col = rt_color(0, 0, 0, 0.0);
			mlx_draw_pixel(my_mlx, v, col);
			(v.x)++;
		}
		(v.y)++;
	}
	return ;
}
