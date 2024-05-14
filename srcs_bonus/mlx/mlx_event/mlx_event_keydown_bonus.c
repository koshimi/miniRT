/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_keydown_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:46:59 by moson             #+#    #+#             */
/*   Updated: 2024/05/10 23:47:00 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"
#include "../../../headers/minirt_bonus.h"

static void	key_wasdqe(int keycode, t_rt_dat *rt, t_transform *tr)
{
	if (keycode == KEY_W && rt->is_cam_mode)
		tr->position = v3d_add(tr->position, tr->forward[AXIS_Z]);
	else if (keycode == KEY_S && rt->is_cam_mode)
		tr->position = v3d_sub(tr->position, tr->forward[AXIS_Z]);
	else if (keycode == KEY_A && rt->is_cam_mode)
		tr->position = v3d_add(tr->position, tr->forward[AXIS_X]);
	else if (keycode == KEY_D && rt->is_cam_mode)
		tr->position = v3d_sub(tr->position, tr->forward[AXIS_X]);
	else if (keycode == KEY_E && rt->is_cam_mode)
		tr->position = v3d_add(tr->position, tr->forward[AXIS_Y]);
	else if (keycode == KEY_Q && rt->is_cam_mode)
		tr->position = v3d_sub(tr->position, tr->forward[AXIS_Y]);
	rt->is_updated = 1;
}

static void	key_1234(int keycode, t_rt_dat *rt, t_transform *tr)
{
	(void)tr;
	if (keycode == KEY_1)
	{
		rt->light_enable[0] = 1;
		rt->light_enable[1] = 1;
		rt->light_enable[2] = 1;
		rt->is_updated = 1;
	}
	else if (keycode == KEY_2)
	{
		rt->light_enable[0] = !(rt->light_enable[0]);
		rt->is_updated = 1;
	}
	else if (keycode == KEY_3)
	{
		rt->light_enable[1] = !(rt->light_enable[1]);
		rt->is_updated = 1;
	}
	else if (keycode == KEY_4)
	{
		rt->light_enable[2] = !(rt->light_enable[2]);
		rt->is_updated = 1;
	}
}

static void	key_backquote(int keycode, t_rt_dat *rt, t_transform *tr)
{
	(void)keycode;
	(void)tr;
	if (rt->is_cam_mode == 1)
	{
		mlx_mouse_show();
		rt->is_cam_mode = 0;
	}
	else
	{
		mlx_mouse_hide();
		rt->is_cam_mode = 1;
		mlx_mouse_move(rt->my_mlx->mlx_win, WIN_X / 2, WIN_Y / 2);
		mlx_mouse_get_pos(\
			rt->my_mlx->mlx_win, &rt->mouse_pos.x, &rt->mouse_pos.y);
	}
}

int	mlx_event_keydown_bonus(int keycode, void *param)
{
	t_rt_dat	*rt;
	t_transform	*tr;

	rt = param;
	tr = &rt->cam->o_info.tr;
	if (rt->is_updated != 0)
		return (0);
	mlx_event_keydown(keycode, param);
	if ((0 <= keycode && keycode <= 2) || (12 <= keycode && keycode <= 14))
		key_wasdqe(keycode, rt, tr);
	else if (18 <= keycode && keycode <= 21)
		key_1234(keycode, rt, tr);
	else if (keycode == KEY_BACKQUOTE)
		key_backquote(keycode, rt, tr);
	return (0);
}
