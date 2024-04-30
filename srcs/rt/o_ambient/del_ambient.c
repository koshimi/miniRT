/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:03:24 by moson             #+#    #+#             */
/*   Updated: 2024/04/06 14:03:26 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_ambient(t_o_amb **ptr)
{
	t_o_amb	*ambient;

	ambient = *ptr;
	if (ambient != NULL)
		free(ambient);
	*ptr = NULL;
	return ;
}
