/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:31:37 by moson             #+#    #+#             */
/*   Updated: 2024/05/06 17:31:39 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

t_vector3_double	get_reflection_vector(\
					t_vector3_double l, t_vector3_double norm)
{
	t_vector3_double	lproj;
	double				lproj_len;

	lproj_len = v3d_dot(v3d_smult(l, -1), norm);
	lproj = v3d_smult(norm, lproj_len);
	return (v3d_add(l, v3d_smult(lproj, 2)));
}

t_node	*get_node(t_lst *obj_list, int idx)
{
	int		cnt;
	t_node	*node;

	if (obj_list->size <= idx)
	{
		ft_printf("Error\n");
		exit(1);
	}
	cnt = -1;
	node = obj_list->head;
	while (++cnt < idx)
		node = node->next;
	return (node);
}

t_o_info	*get_o_info(t_node *node)
{
	if (node->o_type == OTYPE_CAMERA)
		return (&((t_o_cam *)node->item)->o_info);
	else if (node->o_type == OTYPE_CYLINDER)
		return (&((t_o_cyl *)node->item)->o_info);
	else if (node->o_type == OTYPE_LIGHT)
		return (&((t_o_lit *)node->item)->o_info);
	else if (node->o_type == OTYPE_PLANE)
		return (&((t_o_pl *)node->item)->o_info);
	else if (node->o_type == OTYPE_SPHERE)
		return (&((t_o_sph *)node->item)->o_info);
	else
		exit(1);
}
