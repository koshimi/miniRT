/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_keyup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:16:18 by moson             #+#    #+#             */
/*   Updated: 2024/04/04 09:16:19 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

int	mlx_event_keyup(int keycode, void *param)
{
	t_mlx	*my_mlx;

	my_mlx = param;
	if (keycode == 53)
	{
		mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
		mlx_event_destroy(NULL);
	}
	return (0);
}
