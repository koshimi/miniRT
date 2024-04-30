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

static void	set_o_info(t_o_info *info, const t_camera_input *input)
{
	info->o_type = OTYPE_CAMERA;
	info->tr.position = input->position;
	if (is_null_vector3(input->forward))
	{
		//	TODO: error detected
		ft_printf("ERROR DETECT: Camera orientation vector is 0\n");
		exit(1);
	}
	info->tr.forward[AXIS_Z] = vector3_normalized(input->forward);
	if (is_axis_vector3(info->tr.forward[AXIS_Z]) == 'y')
		info->tr.forward[AXIS_X] = vector3_normalized(vector3_cross \
			(vector3_double(0.0, 0.0, 1.0), info->tr.forward[AXIS_Z]));
	else
		info->tr.forward[AXIS_X] = vector3_normalized(vector3_cross \
			(vector3_double(0.0, 1.0, 0.0), info->tr.forward[AXIS_Z]));
	info->tr.forward[AXIS_Y] = vector3_normalized(vector3_cross \
		(info->tr.forward[AXIS_Z], info->tr.forward[AXIS_X]));
	info->tr.scale = vector3_double(1.0, 1.0, 1.0);
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
