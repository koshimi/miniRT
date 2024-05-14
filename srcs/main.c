/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:53:17 by moson             #+#    #+#             */
/*   Updated: 2024/05/14 21:22:43 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

// void	chklk(void)
// {
// 	system("leaks miniRT");
// 	return ;
// }

int	rt_main(t_rt_dat rt)
{
	mlx_rt_init(rt.my_mlx);
	mlx_draw_black_screen(rt.my_mlx);
	cast_ray_simple(&rt);
	rt_draw_col_buf(&rt);
	mlx_put_image_to_window(\
		rt.my_mlx->mlx, rt.my_mlx->mlx_win, rt.my_mlx->img.img, 0, 0);
	mlx_hook(rt.my_mlx->mlx_win, 17, 0, mlx_event_destroy, NULL);
	mlx_hook(rt.my_mlx->mlx_win, 2, 0, mlx_event_keydown, &rt);
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
	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	rt = new_rt_dat(argv[1], &table);
	ret = rt_main(rt);
	del_rt_dat(rt);
	return (ret);
}
