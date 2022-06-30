/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:17:18 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:46:17 by gbierny          ###   ########.fr       */
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
