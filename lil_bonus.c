/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:46:59 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:48:08 by gbierny          ###   ########.fr       */
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

void	reset_dimension(int kc, t_as *as)
{
	if (kc != CONTROL_LEFT)
		return ;
	as->image->zoom = as->image->first_zoom;
	as->image->hauteur = 1;
	as->image->t_vertical = 0;
	as->image->t_horizontal = 0;
	as->image->switch_color = 0;
	as->angle_x = as->first_anglex;
	as->angle_y = as->first_angley;
	as->angle_z = as->first_anglez;
	as->persistance = 0;
}

void	persistance(int kc, t_as *as)
{
	if (kc == KEY_Q)
		as->persistance = 1;
	if (kc == KEY_E)
		as->persistance = 0;
}

void	change_projection(int kc, t_as *as)
{
	if (kc == KEY_P)
		as->top = 1;
	if (kc == KEY_I)
		as->top = 0;
}
