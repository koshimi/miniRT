/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhcho <chanhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:53:38 by chanhcho          #+#    #+#             */
/*   Updated: 2024/05/11 03:19:19 by chanhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "../../headers/minirt.h"

typedef struct s_input
{
	t_ambient_lighting_input	amb;
	t_camera_input				cam;
	t_light_input				lit;
	t_sphere_input				sph;
	t_plane_input				pl;
	t_cylinder_input			cyl;
}	t_input;

char	*parse_amb(char *str, int *table, t_input *input);
char	*parse_light(char *str, int *table, t_input *input);
char	*parse_camera(char *str, int *table, t_input *input);
char	*parse_plane(char *str, int *table, t_input *input);
char	*parse_sphere(char *str, int *table, t_input *input);
char	*parse_cylinder(char *str, int *table, t_input *input);
void	parse_coordinate(char **str, t_vector3_double *pos);
void	check_misconfig(char *str);
double	ft_atod(char **str, char *symbol);
void	clip_double(double min, double max, double *result);
void	seperate_color(char **str, int *color, char *symbol);
void	next_info(char **str);
void	parse_color(char **str, t_rt_color *color);
void	parse_forward(char **str, t_vector3_double *forward);
int		check_symbol(char c, char *symbol);
void	clip_int(int min, int max, int *color);
void	parse_error(void);
int		get_filesize(char *filename);
int		check_filename(char *filename);
void	check_misconfig(char *str);
double	ft_atod(char **str, char *symbol);
void	init_variable(double *sign, double *ret, int *decimal, char **str);
char	*is_identifier(char *str, int *table, t_input *input);
void	get_identifier(char *ret, char *str);
t_input	*parse(char *filename);

#endif