/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 05:32:58 by moson             #+#    #+#             */
/*   Updated: 2024/03/31 05:32:59 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>	//	exit()
# include <math.h>

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include "../headers/rtstructs.h"
# include "../headers/mlxstructs.h"

# define WIN_X 640
# define WIN_Y 480

# define WIN_NAME "miniRT"
# define EPSILON 0.000001

/*						PROTOTYPES						*/

//	new_node.c

t_node				*new_node(void *item, unsigned int o_type);

//	del_node.c

void				del_node(t_node **node_ptr);

//	new_list.c

t_lst				*new_lst(void);

//	del_list.c

void				del_lst(t_lst **lst_ptr);

//	add_list.c

void				add_lst(t_lst *list, t_node	*node);

//	mlx_rt_utils.c

void				mlx_rt_init(t_mlx *my_mlx);

//	mlx_draw_utils.c

void				mlx_draw_pixel(t_mlx *my_mlx, \
					t_vector2_int v, t_rt_color col);
void				mlx_draw_black_screen(t_mlx *my_mlx);

//	new_rt_dat.c

t_rt_dat			new_rt_dat(char *filename);

//	del_rt_dat.c

void				del_rt_dat(t_rt_dat rt);

//	rt_color.c

unsigned int		mlx_rt_color_to_uint(t_rt_color color);
t_rt_color			rt_color(int r, int g, int b, double a);

//	types_utils.c

t_vector2_int		vector2_int(int x, int y);
t_vector3_int		vector3_int(int x, int y, int z);
t_vector3_double	vector3_double(double x, double y, double z);
t_transform			transform(void);
t_ray				ray(t_vector3_double origin, t_vector3_double dir);

//	types_vector3_double.c

double				vector3_sqrmagnitude(t_vector3_double v);
double				vector3_magnitude(t_vector3_double v);
t_vector3_double	vector3_normalized(t_vector3_double v);
int					is_null_vector3(t_vector3_double v);
char				is_axis_vector3(t_vector3_double v);

//	types_vector3_double_base_op.c

t_vector3_double	vector3_add(t_vector3_double a, t_vector3_double b);
t_vector3_double	vector3_sub(t_vector3_double a, t_vector3_double b);
t_vector3_double	vector3_smult(t_vector3_double v, double s);

//	types_vector3_double_product.c

double				vector3_dot(t_vector3_double a, t_vector3_double b);
t_vector3_double	vector3_cross(t_vector3_double a, t_vector3_double b);

//	types_mat_3x3_double.c
t_mat_3x3_double	mat_3x3_double( \
	t_vector3_double x, t_vector3_double y, t_vector3_double z);

//	new_ambient.c

t_o_amb				*new_ambient(const t_ambient_lighting_input *input);

//	del_ambient.c

void				del_ambient(t_o_amb **ptr);

//	new_camera.c

t_o_cam				*new_camera(const t_camera_input *input);

//	del_camera.c

void				del_camera(t_o_cam **ptr);

//	new_light.c

t_o_lit				*new_light(const t_light_input *input);

//	del_light.c

void				del_light(t_o_lit **ptr);

//	new_sphere.c

t_o_sph				*new_sphere(const t_sphere_input *input);

//	del_sphere.c

void				del_sphere(t_o_sph **ptr);

//	is_hit_sphere.c

t_hit				is_hit_sphere(t_ray ray_world, const t_o_sph *sph, unsigned int obj_idx);

//	new_plane.c

t_o_pl				*new_plane(const t_plane_input *input);

//	del_plane.c

void				del_plane(t_o_pl **ptr);

//	is_hit_plane.c

t_hit				is_hit_plane(t_ray ray_world, const t_o_pl *pl, unsigned int obj_idx);

//	new_cylinder.c

t_o_cyl				*new_cylinder(const t_cylinder_input *input);

//	del_cylinder.c

void				del_cylinder(t_o_cyl **ptr);

//	is_hit_cylinder.c

t_hit				is_hit_cylinder(t_ray ray_world, const t_o_cyl *cyl, unsigned int obj_idx);

//	linear_map.c

t_vector3_double	rt_linear_map( \
	const t_vector3_double v, const t_transform base);
t_vector3_double	rt_rlinear_map( \
	const t_vector3_double v, const t_transform base);
t_vector3_double	rt_wtol(t_vector3_double w, t_transform tr);
t_vector3_double	rt_ltow(t_vector3_double l, t_transform tr);

//	linear_get_inverse_3x3.c

double				get_cofactor(t_mat_3x3_double mat, int i, int j);
t_mat_3x3_double	mat_3x3_inverse(t_mat_3x3_double mat);

//	ray.c

double				get_ray_unit_dist(t_vector3_double cam_z, int win_x, int fov);
t_ray				get_local_ray(t_ray ray_world, t_transform local_tr);

//	ray_hit.c

t_hit				get_first_hit(t_rt_dat *rt, t_ray ray);

//	rotation.c

t_vector3_double	tr_rotate(const t_vector3_double *v, \
					char axis, double sin_x, double cos_x);

//	mlx_event_destroy.c

int					mlx_event_destroy(void *param);

//	mlx_event_keyup.c

int					mlx_event_keyup(int keycode, void *param);

/*						PROTOTYPES						*/
#endif
