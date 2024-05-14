/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:25:39 by moson             #+#    #+#             */
/*   Updated: 2024/04/17 17:25:40 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

static void	set_o_info(t_o_info *info, const t_plane_input *input)
{
	info->o_type = OTYPE_PLANE;
	info->tr.position = input->position;
	if (is_null_v3d(input->forward))
	{
		ft_printf("Error\n");
		exit(1);
	}
	info->tr.forward[AXIS_Z] = v3d_norm(input->forward);
	if (is_axis_v3d(info->tr.forward[AXIS_Z]) == 'y')
		info->tr.forward[AXIS_X] = v3d_norm(v3d_cross \
			(v3d(0.0, 0.0, 1.0), info->tr.forward[AXIS_Z]));
	else
		info->tr.forward[AXIS_X] = v3d_norm(v3d_cross \
			(v3d(0.0, 1.0, 0.0), info->tr.forward[AXIS_Z]));
	info->tr.forward[AXIS_Y] = v3d_norm(v3d_cross \
		(info->tr.forward[AXIS_Z], info->tr.forward[AXIS_X]));
	info->tr.scale = v3d(1.0, 1.0, 1.0);
	info->color = input->color;
	return ;
}

t_o_pl	*new_plane(const t_plane_input *input)
{
	t_o_pl	*res;

	res = (t_o_pl *)malloc(sizeof(t_o_pl) * 1);
	if (res == NULL)
		return (NULL);
	res->o_type = OTYPE_PLANE;
	set_o_info(&res->o_info, input);
	return (res);
}
