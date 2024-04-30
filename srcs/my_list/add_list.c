/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:23:20 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 05:23:21 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	add_lst(t_lst *list, t_node	*node)
{
	t_node	*last;

	if (node == NULL)
	{
		ft_printf("add_lst(): node is NULL\n");
		exit(1);
	}
	if (list->head == NULL)
		list->head = node;
	else
	{
		last = list->head;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
	}
	list->size++;
}
