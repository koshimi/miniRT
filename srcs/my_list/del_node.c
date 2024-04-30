/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:56:51 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 03:56:52 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

static void	*get_del_func(unsigned int o_type)
{
	if (o_type == OTYPE_CYLINDER)
		return (del_cylinder);
	else if (o_type == OTYPE_LIGHT)
		return (del_light);
	else if (o_type == OTYPE_PLANE)
		return (del_plane);
	else if (o_type == OTYPE_SPHERE)
		return (del_sphere);
	else
		exit(1);
}

void	del_node(t_node **node_ptr)
{
	t_node	*node;
	void	(*del_item)(void *);

	node = *node_ptr;
	del_item = get_del_func(node->o_type);
	del_item(&node->item);
	free(node);
	*node_ptr = NULL;
}
