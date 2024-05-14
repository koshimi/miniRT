/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:03:43 by moson             #+#    #+#             */
/*   Updated: 2024/03/28 00:03:44 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTSTRUCTS_H
# define RTSTRUCTS_H

# include "../headers/mlxstructs.h"

//	enums

enum e_object_type {
	OTYPE_AMBIENT = 0,
	OTYPE_CAMERA = 1,
	OTYPE_LIGHT = 2,
	OTYPE_SPHERE = 3,
	OTYPE_PLANE = 4,
	OTYPE_CYLINDER = 5
};
enum e_axis {
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2
};

//	data types

struct s_vector2_int {
	int	x;
	int	y;
};
struct s_vector3_int {
	int	x;
	int	y;
	int	z;
};
struct s_vector3_double {
	double	x;
	double	y;
	double	z;
};
struct s_rt_color {
	int		r;
	int		g;
	int		b;
	double	a;
};
struct s_transform {
	struct s_vector3_double	position;
	struct s_vector3_double	forward[3];
	struct s_vector3_double	scale;
};
struct s_mat_3x3_double {
	double	a[3][3];
};
struct s_ray {
	struct s_vector3_double	origin;
	struct s_vector3_double	dir;
};
struct s_hit {
	int						is_hit;
	struct s_ray			ray;
	struct s_vector3_double	point;
	struct s_vector3_double	hit_normal;
	double					sqrmag;
	unsigned int			hit_idx;
};

//	*.rt input formats

struct s_ambient_lighting_input {
	double					ratio;
	struct s_rt_color		color;
};
struct s_camera_input {
	struct s_vector3_double	position;
	struct s_vector3_double	forward;
	int						fov;
};
struct s_light_input {
	struct s_vector3_double	position;
	double					ratio;
	struct s_rt_color		color;
};
struct s_sphere_input {
	struct s_vector3_double	position;
	double					diameter;
	struct s_rt_color		color;
};
struct s_plane_input {
	struct s_vector3_double	position;
	struct s_vector3_double	forward;
	struct s_rt_color		color;
};
struct s_cylinder_input {
	struct s_vector3_double	position;
	struct s_vector3_double	forward;
	double					diameter;
	double					height;
	struct s_rt_color		color;
};

//	object info structs

struct s_o_info {
	unsigned int		o_type;
	struct s_transform	tr;
	struct s_rt_color	color;
};

//	rtstructs

struct s_o_ambient {
	unsigned int	o_type;
	struct s_o_info	o_info;
	double			ratio;
};
struct s_o_camera {
	unsigned int	o_type;
	struct s_o_info	o_info;
	int				fov;
};
struct s_o_light {
	unsigned int	o_type;
	struct s_o_info	o_info;
	double			ratio;
};
struct s_o_sphere {
	unsigned int	o_type;
	struct s_o_info	o_info;
	double			radius;
};
struct s_o_plane {
	unsigned int	o_type;
	struct s_o_info	o_info;
};
struct s_o_cylinder {
	unsigned int	o_type;
	struct s_o_info	o_info;
	double			radius;
	double			height;
};

//	rt_data

struct s_node {
	void			*item;
	unsigned int	o_type;
	struct s_node	*next;
};
struct s_lst {
	int				size;
	struct s_node	*head;
};
struct s_rt_dat {
	struct s_mlx			*my_mlx;

	struct s_o_ambient		*amb;
	struct s_o_camera		*cam;

	struct s_lst			*lit_list;
	struct s_lst			*obj_list;

	struct s_ray			**ray_buf;
	struct s_rt_color		**col_buf;

	int						light_enable[3];
	int						is_cam_mode;
	int						is_updated;

	struct s_vector2_int	mouse_pos;
};

//	typedefs

//	x			[int]
//	y			[int]
typedef struct s_vector2_int				t_vector2_int;
//	x			[int]
//	y			[int]
//	z			[int]
typedef struct s_vector3_int				t_vector3_int;
//	x			[double]
//	y			[double]
//	z			[double]
typedef struct s_vector3_double				t_vector3_double;
//	r			[0, 255]
//	g			[0, 255]
//	b			[0, 255]
//	a			[0.0, 1.0]
typedef struct s_rt_color					t_rt_color;
//	position	[s_vector3_double]
//	forward		[s_vector3_double]
//	scale		[s_vector3_double]
typedef struct s_transform					t_transform;
//	a[3][3]		[double]
typedef struct s_mat_3x3_double				t_mat_3x3_double;
//	origin		[s_vector3_double]
//	dir			[s_vector3_double]
typedef struct s_ray						t_ray;
//	is_hit		[1(true), 0(false)]
//	ray			[s_ray]
//	point		[s_vector3_double]
//	hit_normal	[s_vector3_double]
//	sqrmag		[double]
//	hit_idx	[unsigned int]
typedef struct s_hit						t_hit;
//	ratio		[0.0, 1.0]
//	color		[0, 255]
typedef struct s_ambient_lighting_input		t_ambient_lighting_input;
//	position	[double]
//	forward		[-1.0, 1.0]:	normalized orientation vector
//	fov			[0, 180]
typedef struct s_camera_input				t_camera_input;
//	position	[double]
//	ratio		[0.0, 1.0]
//	color		[0, 255]
typedef struct s_light_input				t_light_input;
//	position	[double]
//	diameter	[0.0, INF]:	2 * radius
//	color		[0, 255]
typedef struct s_sphere_input				t_sphere_input;
//	position	[double]
//	forward		[-1.0, 1.0]:	normalized orientation vector
//	color		[0, 255]
typedef struct s_plane_input				t_plane_input;
//	position	[double]
//	forward		[-1.0, 1.0]:	normalized orientation vector
//	diameter	[0.0, INF]:	2 * radius
//	height		[0.0, INF]
//	color		[0, 255]
typedef struct s_cylinder_input				t_cylinder_input;

typedef struct s_o_info						t_o_info;

typedef struct s_o_ambient					t_o_amb;
typedef struct s_o_camera					t_o_cam;
typedef struct s_o_light					t_o_lit;
typedef struct s_o_sphere					t_o_sph;
typedef struct s_o_plane					t_o_pl;
typedef struct s_o_cylinder					t_o_cyl;

typedef struct s_node						t_node;
typedef struct s_lst						t_lst;
typedef struct s_rt_dat						t_rt_dat;

#endif
