/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:32:12 by moson             #+#    #+#             */
/*   Updated: 2024/04/06 14:32:13 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	set_cam_forward(t_o_info *info, t_vector3_double v)
{
	info->tr.forward[AXIS_Z] = v3d_norm(v);
	if (is_axis_v3d(info->tr.forward[AXIS_Z]) == 'y')
		info->tr.forward[AXIS_X] = v3d_norm(v3d_cross \
			(v3d(0.0, 0.0, 1.0), info->tr.forward[AXIS_Z]));
	else
		info->tr.forward[AXIS_X] = v3d_norm(v3d_cross \
			(v3d(0.0, 1.0, 0.0), info->tr.forward[AXIS_Z]));
	info->tr.forward[AXIS_Y] = v3d_norm(v3d_cross \
		(info->tr.forward[AXIS_Z], info->tr.forward[AXIS_X]));
}

static void	set_o_info(t_o_info *info, const t_camera_input *input)
{
	info->o_type = OTYPE_CAMERA;
	info->tr.position = input->position;
	if (is_null_v3d(input->forward))
	{
		ft_printf("Error\n");
		exit(1);
	}
	set_cam_forward(info, input->forward);
	info->tr.scale = v3d(1.0, 1.0, 1.0);
	info->color = rt_color(0, 0, 0, 0.0);
	return ;
}

t_o_cam	*new_camera(const t_camera_input *input)
{
	t_o_cam	*res;

	res = (t_o_cam *)malloc(sizeof(t_o_cam) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_CAMERA;
	set_o_info(&res->o_info, input);
	res->fov = input->fov;
	return (res);
}
