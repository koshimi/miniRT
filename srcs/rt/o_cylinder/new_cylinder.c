/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:17:43 by moson             #+#    #+#             */
/*   Updated: 2024/04/17 17:17:44 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static void	set_o_info(t_o_info *info, const t_cylinder_input *input)
{
	info->o_type = OTYPE_CYLINDER;
	info->tr.position = input->position;
	if (is_null_vector3(input->forward))
	{
		//	TODO: error detected
		ft_printf("ERROR DETECT: Cylinder orientation vector is 0\n");
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
	info->color = input->color;
	return ;
}

t_o_cyl	*new_cylinder(const t_cylinder_input *input)
{
	t_o_cyl	*res;

	res = (t_o_cyl *)malloc(sizeof(t_o_cyl) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_CYLINDER;
	set_o_info(&res->o_info, input);
	res->radius = input->diameter / 2.0;
	res->height = input->height;
	return (res);
}
