/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_rt_dat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 05:50:50 by moson             #+#    #+#             */
/*   Updated: 2024/04/23 05:50:51 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minirt.h"

void	del_rt_dat(t_rt_dat rt)
{
	int	cnt;

	ft_free((void **)&rt.my_mlx);
	del_ambient(&rt.amb);
	del_camera(&rt.cam);
	del_lst(&rt.lit_list);
	del_lst(&rt.obj_list);
	cnt = -1;
	while (++cnt < WIN_Y)
	{
		ft_free((void **)&rt.ray_buf[cnt]);
		ft_free((void **)&rt.col_buf[cnt]);
	}
	ft_free((void **)&rt.ray_buf);
	ft_free((void **)&rt.col_buf);
}
