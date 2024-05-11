/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_mouse_move_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 01:08:55 by moson             #+#    #+#             */
/*   Updated: 2024/05/11 01:08:56 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"
#include "../../../headers/minirt_bonus.h"

int	mlx_event_mouse_move_bonus(int x, int y, void *param)
{
	t_rt_dat	*rt;

	rt = param;
	if (!rt->is_cam_mode)
		return (0);
	mlx_mouse_get_pos(rt->my_mlx->mlx_win, &x, &y);
	x = x - rt->mouse_pos.x;
	y = y - rt->mouse_pos.y;
	mlx_mouse_move(rt->my_mlx->mlx_win, WIN_X / 2, WIN_Y / 2);
	mlx_mouse_get_pos(rt->my_mlx->mlx_win, &rt->mouse_pos.x, &rt->mouse_pos.y);
	if (y != 0)
		set_cam_forward(&rt->cam->o_info, tr_rotate(&rt->cam->o_info.tr.forward[AXIS_Z], 'x', sin(-y * MOUSE_SENSIVITY), cos(-y * MOUSE_SENSIVITY)));
	if (x != 0)
		set_cam_forward(&rt->cam->o_info, tr_rotate(&rt->cam->o_info.tr.forward[AXIS_Z], 'y', sin(-x * MOUSE_SENSIVITY), cos(-x * MOUSE_SENSIVITY)));
	rt->is_updated = 1;
	return (0);
}
