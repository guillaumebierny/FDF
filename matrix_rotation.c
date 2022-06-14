/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:48:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	rx(int keycode, t_as *as, int incrementation_angle)
{
	if (keycode == 7)
		as->angle_x += incrementation_angle;
	if (keycode == 8)
		as->angle_x -= incrementation_angle;
	if (as->angle_x >= 360 || as->angle_x <= -360)
		as->angle_x = 0;
}

void	ry(int keycode, t_as *as, int incrementation_angle)
{
	if (keycode == 16)
		as->angle_y += incrementation_angle;
	if (keycode == 32)
		as->angle_y -= incrementation_angle;
	if (as->angle_y >= 360 || as->angle_y <= -360)
		as->angle_y = 0;
}

void	rz(int keycode, t_as *as, int incrementation_angle)
{
	if (keycode == 6)
		as->angle_z += incrementation_angle;
	if (keycode == 9)
		as->angle_z -= incrementation_angle;
	if (as->angle_z >= 360 || as->angle_z <= -360)
		as->angle_z = 0;
}

void	rotation_on_axe(int keycode, t_as *as)
{
	int	x;
	int	y;
	int	incrementation_angle;

	y = 0;
	incrementation_angle = -10;
	rx(keycode, as, incrementation_angle);
	ry(keycode, as, incrementation_angle);
	rz(keycode, as, incrementation_angle);
}
