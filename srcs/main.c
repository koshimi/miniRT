/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:53:17 by moson             #+#    #+#             */
/*   Updated: 2024/05/02 14:19:13 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	chklk(void)
{
	system("leaks miniRT");
	return ;
}

int	rt_main(t_rt_dat rt)
{
	mlx_rt_init(rt.my_mlx);
	mlx_draw_black_screen(rt.my_mlx);
	mlx_put_image_to_window(rt.my_mlx->mlx, rt.my_mlx->mlx_win, rt.my_mlx->img.img, 0, 0);
	mlx_hook(rt.my_mlx->mlx_win, 17, 0, mlx_event_destroy, NULL);
	mlx_hook(rt.my_mlx->mlx_win, 3, 0, mlx_event_keyup, rt.my_mlx);
	mlx_loop(rt.my_mlx->mlx);
	return (0);
}

/* TODO: TEMP CODES */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	testfunc(void)
{
	//	TEST 1
	
	// t_vector3_double	x;
	// t_vector3_double	y;
	// t_vector3_double	z;
	// x = vector3_double(1.0, 0, 0);
	// z = vector3_double(0, 0, 1.0);
	// y = vector3_cross(z, x);
	// printf("+y = (%lf, %lf, %lf)\n", y.x, y.y, y.z);
	// y = vector3_cross(x, z);
	// printf("-y = (%lf, %lf, %lf)\n", y.x, y.y, y.z);

	// TEST 2

	// t_camera_input	cam_input;
	// t_o_cam			*cam;
	// char			axis[3];
	// cam_input.forward = vector3_double(0, -1.0, 0);
	// cam = new_camera(&cam_input);
	// axis[0] = 'x';
	// axis[1] = 'y';
	// axis[2] = 'z';
	// for (int i = 0; i < 3; i++)
	// 	printf("cam.%c: <%lf, %lf, %lf>\n", axis[i], cam->o_info.tr.forward[i].x, cam->o_info.tr.forward[i].y, cam->o_info.tr.forward[i].z);
	// del_camera(&cam);

	//	TEST 3: Unit vector (normalized) magnitude test

	// srand(time(NULL));
	// for (int i = 0; i < 10000; i++)
	// {
	// 	t_vector3_double	v;
	// 	t_vector3_double	v_norm;
	// 	double				v_mag;
	// 	v = vector3_double(1.0 / (rand() % 30 + 1), 1.0 / (rand() % 30 + 1), 1.0 / (rand() % 30 + 1));
	// 	v_norm = vector3_normalized(v);
	// 	v_mag = vector3_magnitude(v_norm);
	// 	if (v_mag != 1.0)
	// 	{
	// 		printf("vector v   : \t<%lf, %lf, %lf>\n", v.x, v.y, v.z);
	// 		printf("normalized : \t<%lf, %lf, %lf>\n", v_norm.x, v_norm.y, v_norm.z);
	// 		printf("magnitude  : \t%lf\n\n", v_mag);
	// 	}
	// }

	//	TEST 4: get_matrix_cofactor

	// t_mat_3x3_double	mat1, mat2;
	// mat1.a[0][0] = 1;
	// mat1.a[0][1] = 2;
	// mat1.a[0][2] = -1;
	// mat1.a[1][0] = 2;
	// mat1.a[1][1] = 2;
	// mat1.a[1][2] = 5;
	// mat1.a[2][0] = 2;
	// mat1.a[2][1] = 3;
	// mat1.a[2][2] = -4;
	// printf("mat1: \n");
	// for (int i = 0; i < 3; i++)
	// 	printf("%lf\t%lf\t%lf\n", mat1.a[i][0], mat1.a[i][1], mat1.a[i][2]);
	// mat2 = mat_3x3_inverse(mat1);
	// printf("mat2: \n");
	// for (int i = 0; i < 3; i++)
	// 	printf("%lf\t%lf\t%lf\n", mat2.a[i][0], mat2.a[i][1], mat2.a[i][2]);


	//	TEST 5: ltow, wtol
	
	// t_transform			tr;
	// t_vector3_double	world;
	// t_vector3_double	local;
	// t_vector3_double	wtol;
	// t_vector3_double	ltow;
	// tr.position = vector3_double(1.0, -7.0, -1.0);
	// tr.forward[AXIS_X] = vector3_normalized(vector3_double(1.0, 0.0, 0.0));
	// tr.forward[AXIS_Y] = vector3_normalized(vector3_double(0.0, 0.0, 1.0));
	// tr.forward[AXIS_Z] = vector3_normalized(vector3_double(0.0, -1.0, 0.0));
	// tr.scale = vector3_double(2.0, 2.0, 2.0);
	// world = vector3_double(3.0, -13.0, 3.0);
	// local = vector3_double(1.0, 2.0, 3.0);
	// wtol = rt_wtol(world, tr);
	// ltow = rt_ltow(local, tr);
	// printf("tr.position = (%lf, %lf, %lf)\n", tr.position.x, tr.position.y, tr.position.z);
	// printf("tr.forward[X] = (%lf, %lf, %lf)\n", tr.forward[AXIS_X].x, tr.forward[AXIS_X].y, tr.forward[AXIS_X].z);
	// printf("tr.forward[Y] = (%lf, %lf, %lf)\n", tr.forward[AXIS_Y].x, tr.forward[AXIS_Y].y, tr.forward[AXIS_Y].z);
	// printf("tr.forward[Z] = (%lf, %lf, %lf)\n", tr.forward[AXIS_Z].x, tr.forward[AXIS_Z].y, tr.forward[AXIS_Z].z);
	// printf("tr.scale = (%lf, %lf, %lf)\n", tr.scale.x, tr.scale.y, tr.scale.z);
	// printf("wtol: world(%lf, %lf, %lf) = local(%lf, %lf, %lf)\n", world.x, world.y, world.z, wtol.x, wtol.y, wtol.z);
	// printf("ltow: local(%lf, %lf, %lf) = world(%lf, %lf, %lf)\n", local.x, local.y, local.z, ltow.x, ltow.y, ltow.z);
	// t_vector3_double	origin_world;
	// t_vector3_double	origin_local;
	// origin_world = vector3_double(0, 0, 0);
	// origin_local = rt_wtol(origin_world, tr);
	// printf("origin: world(%lf, %lf, %lf) = local(%lf, %lf, %lf)\n", origin_world.x, origin_world.y, origin_world.z, origin_local.x, origin_local.y, origin_local.z);

	//	TEST 6: get_ray_unit_dist

	// t_vector3_double	cam_z;
	// t_vector3_double	ray;
	// double				unit;
	// cam_z = vector3_double(0, 0, 1.0);
	// unit = get_ray_unit_dist(cam_z, WIN_X, 70);
	// printf("cam_z(%lf, %lf, %lf), unit: %lf\n", cam_z.x, cam_z.y, cam_z.z, unit);
	// ray.x = ((0 - (WIN_X / 2)) + 0.5) * unit;
	// ray.y = ((0 - (WIN_Y / 2)) + 0.5) * unit;
	// ray.z = cam_z.z;
	// printf("ray[0][0](%lf, %lf, %lf)\n", ray.x, ray.y, ray.z);
	// ray = vector3_normalized(ray);
	// printf("ray[0][0].normalized(%lf, %lf, %lf)\n", ray.x, ray.y, ray.z);

}

/* TODO: TEMP CODES */

int	main(void)
{
	t_rt_dat	rt;
	int			ret;

	// atexit(chklk);
	rt = new_rt_dat("tmp_file_name.rt");
	testfunc();
	
	// ret = rt_main(rt);
	ret = 0;

	del_rt_dat(rt);
	return (ret);
}
