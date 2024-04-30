/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:57:37 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 03:57:38 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

void	del_lst(t_lst **lst_ptr)
{
	t_lst	*lst;
	t_node	*node;
	t_node	*next;

	lst = *lst_ptr;
	node = lst->head;
	while (node != NULL)
	{
		next = node->next;
		del_node(&node);
		lst->size--;
		node = next;
	}
	ft_free((void **)lst_ptr);
}
