/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:17:50 by moson             #+#    #+#             */
/*   Updated: 2024/04/17 17:17:52 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_cylinder(t_o_cyl **ptr)
{
	t_o_cyl	*cyl;

	cyl = *ptr;
	if (cyl != NULL)
		free(cyl);
	*ptr = NULL;
	return ;
}
