/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toutou_D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:34:43 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 07:31:04 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	projection(t_coordonnees point3_d, t_coordonnees *point, t_image *image)
{
	int	x_previous;
	int	y_previous;

	(*point).x = point3_d.x;
	(*point).y = point3_d.y;
}

void	converse_to_d(t_coordonnees **point_3d, t_coordonnees ***point_2d,
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
