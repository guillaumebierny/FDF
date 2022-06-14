/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:26:55 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:52:12 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

t_bres_v	initialyse_t_bres_v(t_coor p1,
	t_coor p2, t_image *image)
{
	t_bres_v	bres_v;

	if (image->switch_color != 2)
	{
		bres_v.color_point1 = p1.color;
		bres_v.color_point2 = p2.color;
	}
	bres_v.x1 = (int)(p1.x);
	bres_v.y1 = (int)(p1.y);
	bres_v.ex = (int)(get_absolute((p2.x) - (p1.x)));
	bres_v.ey = (int)(get_absolute((p2.y) - (p1.y)));
	bres_v.i = 0;
	bres_v.dy = 2 * bres_v.ey;
	bres_v.dx = 2 * bres_v.ex;
	bres_v.end_dy = bres_v.ey;
	bres_v.end_dx = bres_v.ex;
	get_right_incrementation(&bres_v.x_incr, &bres_v.y_incr, p1, p2);
	return (bres_v);
}

t_image	initialyze_image(void)
{
	t_image	image;

	image.img = NULL;
	image.address = NULL;
	image.bits_per_pixel = 0;
	image.line_length = 0;
	image.endian = 0;
	image.color = 0;
	image.zoom = 1;
	image.first_zoom = 1;
	image.hauteur = 1;
	image.higher = 0;
	image.minest_x = 0;
	image.height = 0;
	image.t_vertical = 0;
	image.t_horizontal = 0;
	image.switch_color = 0;
	image.lowest_z = 2147483647;
	image.bigest_z = -2147483648;
	return (image);
}

t_mlx_vars	initialyze_mlx_vars(void)
{
	t_mlx_vars	mlx_vars;

	mlx_vars.mlx = NULL;
	mlx_vars.win_mlx = NULL;
	return (mlx_vars);
}

static void	initialyze_all_struct_second_part(t_as *as)
{
	as->first_anglez = as->angle_z;
	as->persistance = 0;
	as->incr_r = 0;
	as->incr_g = 0;
	as->incr_b = 0;
	as->top = 0;
	as->key = -1;
	as->w = 0;
	as->s = 0;
	as->d = 0;
	as->a = 0;
}

t_as	initialyze_all_struct(t_mlx_vars *mlx_vars)
{
	t_as	as;

	as.mlx_vars = mlx_vars;
	as.angle_x = 0;
	as.angle_y = 0;
	as.to_radian = (double)M_PI / 180.0;
	as.previous_height = 0;
	as.previous_higher = 0;
	as.interupteur_couleur = 0;
	as.angle_x = 0;
	as.angle_y = 0;
	as.angle_z = 0;
	as.first_anglex = as.angle_x;
	as.first_angley = as.angle_y;
	as.first_anglez = as.angle_z;
	as.persistance = 0;
	as.incr_r = 0;
	as.incr_g = 0;
	as.incr_b = 0;
	as.top = 0;
	as.key = -1;
	initialyze_all_struct_second_part(&as);
	return (as);
}
