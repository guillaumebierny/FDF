/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:46:59 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 04:47:59 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	reset_image(t_image *image, unsigned int color)
{
	int	y;
	int	x;

	y = 1;
	while (y < HEIGHT)
	{
		x = 1;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}

int	reset_dimension(int kc, t_all_struct *as)
{
	if (kc != 256)
		return (1);
	as->image->zoom = as->image->first_zoom;
	as->image->hauteur = 1;
	as->image->t_vertical = 0;
	as->image->t_horizontal = 0;
	as->image->switch_color = 0;
	as->angle_x = as->first_anglex;
	as->angle_y = as->first_angley;
	as->angle_z = as->first_anglez;
	as->persistance = 0;
	return (0);
}

void	persistance(int kc, t_all_struct *as)
{
	if (kc == 1)
		as->persistance = 1;
	if (kc == 3)
		as->persistance = 0;
}

int	change_projection(int kc, t_all_struct *as)
{
	if (kc == 35)
	{
		if (as->top)
			as->top = 0;
		else
			as->top = 1;
		return (0);
	}
	return (1);
}
