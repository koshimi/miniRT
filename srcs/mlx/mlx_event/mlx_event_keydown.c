/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_keydown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:39:27 by moson             #+#    #+#             */
/*   Updated: 2024/05/08 22:39:28 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

int	mlx_event_keydown(int keycode, void *param)
{
	t_rt_dat	*rt;

	rt = param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(rt->my_mlx->mlx, rt->my_mlx->mlx_win);
		mlx_event_destroy(NULL);
	}
	else if (keycode == KEY_SPC)
	{
		mlx_mouse_show();
		rt->is_cam_mode = 0;
		rt->is_updated = 2;
	}
	return (0);
}
