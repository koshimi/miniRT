/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rt_dat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:50:44 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 05:50:45 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

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
	if (rt->my_mlx == NULL || \
		rt->lit_list == NULL || \
		rt->obj_list == NULL)
		return (0);
	return (1);
}

t_rt_dat	new_rt_dat(char *filename)
{
	t_rt_dat	rt;

	if (init_rt_dat(&rt) == 0)
	{
		ft_printf("init_rt_dat() failed\n");
		exit(1);
	}
	/* TODO: INPUT(parsed) -> rtstructs */
	/* TEMP: init rt_dat like mandatory part */
	{
		t_ambient_lighting_input	input_amb;
		t_camera_input				input_cam;
		t_light_input				input_lit;
		t_sphere_input				input_sphere;
		t_plane_input				input_plane;
		t_cylinder_input			input_cylinder;

		void						*item;

		ft_printf("filename: %s\n", filename);	//	TODO: TEMP msg
		//	set *_input as parsed data
		{
			//	ambient
			input_amb.ratio = 0.2;
			input_amb.color = rt_color(255, 255, 255, 0.0);

			//	camera
			input_cam.position = vector3_double(-50.0, 0, 20);
			input_cam.forward = vector3_normalized(vector3_double(0.0, 0.0, 1.0));
			input_cam.fov = 70;

			//	light
			input_lit.position = vector3_double(-40.0, 50.0, 0.0);
			input_lit.ratio = 0.6;
			input_lit.color = rt_color(10, 0, 255, 0.0);
			
			//	sphere
			input_sphere.position = vector3_double(0.0, 0.0, 0.6);
			input_sphere.diameter = 12.6;
			input_sphere.color = rt_color(10, 0, 255, 0.0);

			//	plane
			input_plane.position = vector3_double(0.0, 0.0, -10.0);
			input_plane.forward = vector3_normalized(vector3_double(0.0, 1.0, 0.0));
			input_plane.color = rt_color(0, 0, 255, 0.0);

			//	cylinder
			input_cylinder.position = vector3_double(50.0, 0.0, 20.6);
			input_cylinder.forward = vector3_normalized(vector3_double(0.0, 0.0, 1.0));
			input_cylinder.diameter = 14.2;
			input_cylinder.height = 21.42;
			input_cylinder.color = rt_color(10, 0, 255, 0.0);
		}

		//	set rt as temp_*_input
		rt.amb = new_ambient(&input_amb);
		rt.cam = new_camera(&input_cam);
		item = (void *)new_light(&input_lit);
		if (item == NULL)
			exit(1);
		add_lst(rt.lit_list, new_node(item, OTYPE_LIGHT));
		item = (void *)new_sphere(&input_sphere);
		if (item == NULL)
			exit(1);
		add_lst(rt.obj_list, new_node(item, OTYPE_SPHERE));
		item = (void *)new_plane(&input_plane);
		if (item == NULL)
			exit(1);
		add_lst(rt.obj_list, new_node(item, OTYPE_PLANE));
		item = (void *)new_cylinder(&input_cylinder);
		if (item == NULL)
			exit(1);
		add_lst(rt.obj_list, new_node(item, OTYPE_CYLINDER));

		if (rt.amb == NULL || rt.cam == NULL)
			exit(1);
		if (rt.lit_list->size != 1)
			exit(1);
		if (rt.obj_list->size != 3)
			exit(1);
	}
	/* END */
	return (rt);
}
