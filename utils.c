/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 06:22:23 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 10:01:00 by gbierny          ###   ########.fr       */
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

void	get_coordinates(int x, int y, int z, t_coordonnees *p)
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

void	gather_struct(t_all_struct *as, t_coordonnees ***p3d
		, t_coordonnees ***p3drotated, t_coordonnees ***p2d)
{
	as->p3d = p3d;
	as->p2d = p2d;
	as->p3drotated = p3drotated;
}

int	cluse(int kc, t_mlx_vars *mlx)
{
	if (kc == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win_mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
