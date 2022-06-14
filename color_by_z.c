/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_by_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:39:11 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:48:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

unsigned int	get_right_r(unsigned int color)
{
	color = color << 8;
	color = color >> 24;
	return (color);
}

unsigned int	get_right_g(unsigned int color)
{
	color = color << 16;
	color = color >> 24;
	return (color);
}

unsigned int	get_right_b(unsigned int color)
{
	color = color << 16;
	color = color >> 24;
	return (color);
}

void	get_color_by_z(unsigned int *color_point,
	t_coor p, t_as *as)
{
	*color_point = 0;
	*color_point += ((as->incr_r * (unsigned int)
				(-p.z - as->image->lowest_z)) << 16);
	*color_point += (0xFF << 8) - ((as->incr_g
				* (-p.z - as->image->lowest_z)) << 8);
	*color_point += 0xFF - as->incr_b
		* (-p.z - as->image->lowest_z);
}
