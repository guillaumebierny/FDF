/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:17:18 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:48:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	framing(int little_var, int big_var)
{
	if (big_var >= little_var)
		return ((big_var - little_var) / 2);
	else
		return (-(little_var - big_var) / 2);
}

unsigned int	degraded_for_line(t_bres_v *bres, double i, double spacing)
{
	unsigned int	color;

	color = 0;
	if (bres->color_point1 == bres->color_point2)
		return (bres->color_point1);
	red_case(bres, &color, spacing, i);
	green_case(bres, &color, spacing, i);
	blue_case(bres, &color, spacing, i);
	return (color);
}

void	red_case(t_bres_v *bres, unsigned int *color, double spacing, double i)
{
	if (bres->r1 == bres->r2)
		*color += bres->r1 << 16;
	if (bres->r1 < bres->r2)
		*color += (bres->r1 << 16) + (((unsigned int)
					(((double)(bres->r2 - bres->r1) / spacing) * i)) << 16);
	if (bres->r1 > bres->r2)
		*color += (bres->r1 << 16) - (((unsigned int)
					(((double)(bres->r1 - bres->r2) / spacing) * i)) << 16);
}

void	green_case(t_bres_v *bres, unsigned int *color,
	double spacing, double i)
{
	if (bres->g1 == bres->g2)
		*color += bres->g1 << 8;
	if (bres->g1 < bres->g2)
		*color += (bres->g1 << 8) + (((unsigned int)
					(((double)(bres->g2 - bres->g1) / spacing) * i)) << 8);
	if (bres->g1 > bres->g2)
		*color += (bres->g1 << 8) - (((unsigned int)
					(((double)(bres->g1 - bres->g2) / spacing) * i)) << 8);
}

void	blue_case(t_bres_v *bres, unsigned int *color,
	double spacing, double i)
{
	if (bres->b1 == bres->b2)
		*color += bres->b1;
	if (bres->b1 < bres->b2)
		*color += bres->b1 + (unsigned int)
			(((double)(bres->b2 - bres->b1) / spacing) * i);
	if (bres->b1 > bres->b2)
		*color += bres->b1 - (unsigned int)
			(((double)(bres->b1 - bres->b2) / spacing) * i);
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
