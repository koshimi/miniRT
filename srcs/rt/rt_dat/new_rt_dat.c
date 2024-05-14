/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rt_dat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:50:44 by moson             #+#    #+#             */
/*   Updated: 2024/05/12 12:44:49 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"
#include "../../../headers/parse.h"

//	If error return 0
static int	alloc_rt_buffer(t_rt_dat *rt)
{
	int	cnt;

	cnt = -1;
	while (++cnt < WIN_Y)
	{
		rt->ray_buf[cnt] = (t_ray *)malloc(sizeof(t_ray) * WIN_X);
		rt->col_buf[cnt] = (t_rt_color *)malloc(sizeof(t_rt_color) * WIN_X);
		if (rt->ray_buf[cnt] == NULL || rt->col_buf[cnt] == NULL)
			return (0);
	}
	return (1);
}

//	If error return 0
static int	init_rt_dat(t_rt_dat *rt)
{
	rt->my_mlx = NULL;
	rt->amb = NULL;
	rt->cam = NULL;
	rt->lit_list = NULL;
	rt->obj_list = NULL;
	rt->my_mlx = (t_mlx *)malloc(sizeof(t_mlx) * 1);
	rt->lit_list = new_lst();
	rt->obj_list = new_lst();
	rt->ray_buf = (t_ray **)malloc(sizeof(t_ray *) * WIN_Y);
	rt->col_buf = (t_rt_color **)malloc(sizeof(t_rt_color *) * WIN_Y);
	rt->light_enable[0] = 1;
	rt->light_enable[1] = 1;
	rt->light_enable[2] = 1;
	if (rt->my_mlx == NULL || \
		rt->lit_list == NULL || \
		rt->obj_list == NULL || \
		rt->ray_buf == NULL || \
		rt->col_buf == NULL)
		return (0);
	if (alloc_rt_buffer(rt) == 0)
		return (0);
	rt->is_cam_mode = 1;
	rt->is_updated = 1;
	return (1);
}

static t_rt_dat	set_rt_dat(t_rt_dat rt, t_input *input)
{
	void	*item;

	rt.amb = new_ambient(&input->amb);
	rt.cam = new_camera(&input->cam);
	item = (void *)new_light(&input->lit);
	if (item == NULL)
		exit(1);
	add_lst(rt.lit_list, new_node(item, OTYPE_LIGHT));
	item = (void *)new_sphere(&input->sph);
	if (item == NULL)
		exit(1);
	add_lst(rt.obj_list, new_node(item, OTYPE_SPHERE));
	item = (void *)new_plane(&input->pl);
	if (item == NULL)
		exit(1);
	add_lst(rt.obj_list, new_node(item, OTYPE_PLANE));
	item = (void *)new_cylinder(&input->cyl);
	if (item == NULL)
		exit(1);
	add_lst(rt.obj_list, new_node(item, OTYPE_CYLINDER));
	if (rt.amb == NULL || rt.cam == NULL)
		exit(1);
	return (rt);
}

t_rt_dat	new_rt_dat(char *filename)
{
	t_rt_dat	rt;
	t_input		*input;

	if (init_rt_dat(&rt) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	input = parse(filename);
	rt = set_rt_dat(rt, input);
	free(input);
	return (rt);
}
