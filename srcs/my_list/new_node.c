/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:56:45 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 03:56:46 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_node	*new_node(void *item, unsigned int o_type)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (node == NULL)
		return (NULL);
	node->item = item;
	node->o_type = o_type;
	node->next = NULL;
	return (node);
}
