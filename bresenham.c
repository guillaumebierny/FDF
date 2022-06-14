/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 07:43:53 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 04:03:10 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	get_right_incrementation(int *x_incr, int *y_incr,
	t_coor point1, t_coor point2)
{
	if (point1.x < point2.x)
		*x_incr = 1;
	else
		*x_incr = -1;
	if (point1.y < point2.y)
		*y_incr = 1;
	else
		*y_incr = -1;
}

void	bresenham_dx_bigger(t_bres_v *bres, t_image *image,
	int framing_w, int framing_h)
{
	if (bres->end_dx >= bres->end_dy)
	{
		while (bres->i < bres->end_dx)
		{
			my_mlx_pixel_put(image, bres->x1 + framing_w + image->t_horizontal,
				bres->y1 + framing_h + image->t_vertical,
				degraded_for_line(bres, (double)bres->i,
					(double)bres->end_dx));
			bres->x1 += bres->x_incr;
			bres->ex -= bres->dy;
			if (bres->ex < 0)
			{
				bres->ex += bres->dx;
				bres->y1 += bres->y_incr;
			}
			bres->i++;
		}
	}
}

void	bresenham_dy_bigger(t_bres_v *bres, t_image *image,
	int framing_w, int framing_h)
{
	if (bres->end_dx < bres->end_dy)
	{
		bres->i = 0;
		while (bres->i < bres->end_dy)
		{
			my_mlx_pixel_put(image, bres->x1 + framing_w
				+ image->t_horizontal, bres->y1 + framing_h + image->t_vertical,
				degraded_for_line(bres, (double)bres->i, (double)bres->end_dy));
			bres->ey -= bres->dx;
			bres->y1 += bres->y_incr;
			if (bres->ey < 0)
			{
				bres->x1 += bres->x_incr;
				bres->ey += bres->dy;
			}
			bres->i++;
		}
	}
}

void	bresenham_algo(t_coor p[4], t_as *as, t_index ind)
{
	int			framing_w;
	int			framing_h;
	t_bres_v	bres;

	bres = initialyse_t_bres_v(p[0], p[1], as->image);
	if (as->image->switch_color == 1)
	{
		bres.color_point1 = as->image->color;
		bres.color_point2 = as->image->color;
	}
	if (as->image->switch_color == 2)
	{
		get_color_by_z(&bres.color_point1, p[2], as);
		get_color_by_z(&bres.color_point2, p[3], as);
	}
	bres.r1 = (get_right_r(bres.color_point1));
	bres.g1 = (get_right_g(bres.color_point1));
	bres.b1 = get_right_b(bres.color_point1);
	bres.r2 = (get_right_r(bres.color_point2));
	bres.g2 = (get_right_g(bres.color_point2));
	bres.b2 = get_right_b(bres.color_point2);
	framing_w = framing(as->image->width, WIDTH) - as->image->minest_x;
	framing_h = framing(as->image->height, HEIGHT) - as->image->higher;
	bresenham_dx_bigger(&bres, as->image, framing_w, framing_h);
	bresenham_dy_bigger(&bres, as->image, framing_w, framing_h);
}

void	make_bresenham(t_coor **point, t_as *as)
{
	t_index			ind;
	t_coor			p[4];

	ind.y = 0;
	ind.x = 0;
	lil_loop_bresenham(ind, p, point, as);
}
