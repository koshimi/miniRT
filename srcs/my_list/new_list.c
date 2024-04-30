/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:57:32 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 03:57:33 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_lst	*new_lst(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst) * 1);
	if (lst == NULL)
		return (NULL);
	lst->size = 0;
	lst->head = NULL;
	return (lst);
}
