/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:22:10 by moson             #+#    #+#             */
/*   Updated: 2024/03/31 10:22:12 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	mlx_rt_init(t_mlx *my_mlx)
{
	void	**mlx_ptr;
	t_img	*img_ptr;

	mlx_ptr = &(my_mlx->mlx);
	img_ptr = &(my_mlx->img);
	*mlx_ptr = mlx_init();
	if (*mlx_ptr == NULL)
		exit(1);
	my_mlx->mlx_win = mlx_new_window(*mlx_ptr, WIN_X, WIN_Y, WIN_NAME);
	if (my_mlx->mlx_win == NULL)
		exit(1);
	img_ptr->img = mlx_new_image(*mlx_ptr, WIN_X, WIN_Y);
	if (img_ptr->img == NULL)
		exit(1);
	img_ptr->addr = mlx_get_data_addr \
		(img_ptr->img, &img_ptr->bits_per_pixel, \
		&img_ptr->line_length, &img_ptr->endian);
	return ;
}
