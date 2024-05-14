/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:46:30 by moson             #+#    #+#             */
/*   Updated: 2024/05/14 21:21:13 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"
#include "../headers/minirt_bonus.h"

// void	chklk(void)
// {
// 	system("leaks miniRT");
// 	return ;
// }

int	rt_main_bonus(t_rt_dat rt)
{
	mlx_rt_init(rt.my_mlx);
	mlx_draw_black_screen(rt.my_mlx);
	cast_ray_simple(&rt);
	rt_draw_col_buf(&rt);
	mlx_put_image_to_window(\
		rt.my_mlx->mlx, rt.my_mlx->mlx_win, rt.my_mlx->img.img, 0, 0);
	mlx_mouse_hide();
	mlx_mouse_move(rt.my_mlx->mlx_win, WIN_X, WIN_Y);
	mlx_mouse_get_pos(rt.my_mlx->mlx_win, &rt.mouse_pos.x, &rt.mouse_pos.y);
	mlx_hook(rt.my_mlx->mlx_win, 17, 0, mlx_event_destroy, NULL);
	mlx_hook(rt.my_mlx->mlx_win, 2, 0, mlx_event_keydown_bonus, &rt);
	mlx_hook(rt.my_mlx->mlx_win, 6, 0, mlx_event_mouse_move_bonus, &rt);
	mlx_loop_hook(rt.my_mlx->mlx, mlx_event_update, &rt);
	mlx_loop(rt.my_mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt_dat	rt;
	int			ret;
	int			table;

	table = 0;
	table |= BONUS_FLAG;
	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	rt = new_rt_dat(argv[1], &table);
	ret = rt_main_bonus(rt);
	del_rt_dat(rt);
	return (ret);
}
