/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 06:22:23 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:46:35 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dest;

	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return ;
	dest = image->address + (image->line_length
			* y + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	get_coordinates(int x, int y, int z, t_coor *p)
{
	int		x_previous;
	int		y_previous;

	x_previous = (double)x;
	y_previous = (double)y;
	(*p).x = (int)(((sqrt(2.0) / 2.0) * ((x_previous - y_previous))));
	(*p).y = (int)(((sqrt(2.0 / 3.0) * (double)z)
				- ((1.0 / sqrt(6.0))) * (x_previous + y_previous)) + 0.5);
	(*p).exist = 1;
}

void	gather_struct(t_as *as, t_coor ***p3d
		, t_coor ***p3drotated, t_coor ***p2d)
{
	as->p3d = p3d;
	as->p2d = p2d;
	as->p3drotated = p3drotated;
}

void	make_the_zoom_and_h(int kc, t_as *as)
{
	double	z_and_h;
	double	zoom;
	int		x;
	int		y;

	zoom = as->image->zoom;
	z_and_h = as->image->hauteur * zoom;
	y = 0;
	while ((*as->p3drotated)[y][0].exist)
	{
		x = 0;
		while ((*as->p3drotated)[y][x].exist)
		{
			(*as->p3drotated)[y][x].x = (int)((((*as->p3d)[y][x].x) * zoom));
			(*as->p3drotated)[y][x].y = (int)((((*as->p3d)[y][x].y) * zoom));
			(*as->p3drotated)[y][x].z = (int)((((*as->p3d)[y][x].z) * z_and_h));
			x++;
		}
		y++;
	}
}

void	lil_loop_bresenham(t_index ind, t_coor p[4],
	t_coor **point, t_as *as)
{
	while (point[ind.y][0].exist)
	{
		ind.x = 0;
		while (point[ind.y][ind.x].exist)
		{
			if (point[ind.y][ind.x + 1].exist)
			{
				p[0] = point[ind.y][ind.x];
				p[1] = point[ind.y][ind.x + 1];
				p[2] = (*as->p3d)[ind.y][ind.x];
				p[3] = (*as->p3d)[ind.y][ind.x + 1];
				bresenham_algo(p, as, ind);
			}
			if (point[ind.y + 1][0].exist)
			{
				p[0] = point[ind.y][ind.x];
				p[1] = point[ind.y + 1][ind.x];
				p[2] = (*as->p3d)[ind.y][ind.x];
				p[3] = (*as->p3d)[ind.y + 1][ind.x];
				bresenham_algo(p, as, ind);
			}
			ind.x++;
		}
		ind.y++;
	}
}
