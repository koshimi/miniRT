/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:52:57 by moson             #+#    #+#             */
/*   Updated: 2024/05/10 23:52:58 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

int	mlx_event_update(void *param)
{
	t_rt_dat	*rt;

	rt = param;
	if (rt->is_updated == 1)
	{
		cast_ray_simple(rt);
		rt_draw_col_buf(rt);
		mlx_put_image_to_window(rt->my_mlx->mlx, rt->my_mlx->mlx_win, rt->my_mlx->img.img, 0, 0);
		rt->is_updated = 0;
	}
	else if (rt->is_updated == 2)
	{
		cast_ray(rt);
		rt_draw_col_buf(rt);
		mlx_put_image_to_window(rt->my_mlx->mlx, rt->my_mlx->mlx_win, rt->my_mlx->img.img, 0, 0);
		rt->is_updated = 0;
	}

	// int	x;
	// int	y;

	// mlx_mouse_get_pos(rt->my_mlx->mlx_win, &x, &y);
	// ft_printf("%d, %d : forced move delta=(", x, y);
	// x = (WIN_X / 2 - x);
	// y = (WIN_Y / 2 - y);
	// ft_printf("%d, %d)\n", x, y);
	// mlx_mouse_move(rt->my_mlx->mlx_win, 0, 0);
	return (0);
}
