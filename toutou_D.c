/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toutou_D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:34:43 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:48:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	projection(t_coor point3_d, t_coor *point, t_image *image)
{
	int	x_previous;
	int	y_previous;

	(*point).x = point3_d.x;
	(*point).y = point3_d.y;
}

void	converse_to_d(t_coor **point_3d, t_coor ***point_2d,
	t_image *image, int type_of_conv)
{
	int	x;
	int	y;

	y = 0;
	while (point_3d[y][0].exist)
	{
		x = 0;
		while (point_3d[y][x].exist)
		{
			if (!type_of_conv)
				get_coordinates(point_3d[y][x].x, point_3d[y][x].y,
					point_3d[y][x].z, &(*point_2d)[y][x]);
			else
				projection(point_3d[y][x], &(*point_2d)[y][x], image);
			x++;
		}
		y++;
	}
}

void	resize_the_image(t_image image, t_as *as)
{
	int	correct;

	correct = 0;
	while (!correct)
	{
		make_the_zoom_and_h(0, as);
		rotation(0, as);
		converse_to_d(*as->p3drotated, &(*as->p2d), &image, 0);
		correct = get_dimension_to_project(*as->p2d, as->image);
	}
	as->image->first_zoom = as->image->zoom;
	as->image->img = mlx_new_image(as->mlx_vars->mlx, WIDTH, HEIGHT);
	as->image->address = mlx_get_data_addr(as->image->img,
			&as->image->bits_per_pixel,
			&as->image->line_length, &as->image->endian);
}
