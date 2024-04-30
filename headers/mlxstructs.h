/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstructs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moson <moson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:49:10 by moson             #+#    #+#             */
/*   Updated: 2024/03/31 02:49:14 by moson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXSTRUCTS_H
# define MLXSTRUCTS_H

//	mlx structs

struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mlx {
	void			*mlx;
	void			*mlx_win;
	struct s_img	img;
};

//	Typedefs

typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;

#endif
