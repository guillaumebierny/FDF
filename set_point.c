/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:32:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/14 03:43:57 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	set_right_value(t_coor *point, int x, int y, char *z)
{
	char			**arg;
	unsigned int	new_color;

	arg = ft_split(z, ',');
	new_color = 0;
	if (arg[1])
		new_color = ft_atoi_base(arg[1], "0123456789ABCDEF");
	point->x = x;
	point->y = -y;
	point->z = -ft_atoi(arg[0]);
	point->exist = 1;
	if (!arg[1])
		point->color = 0xFFFFFF;
	else
		point->color = new_color;
}

void	set_point(t_coor *point, t_index ind, char **z, t_image *image)
{
	int	vertical;

	vertical = -1;
	while (++vertical < ind.x)
	{
		set_right_value(&point[vertical], vertical, ind.y, z[vertical]);
		if (-point[vertical].z < image->lowest_z)
			image->lowest_z = -point[vertical].z;
		if (-point[vertical].z > image->bigest_z)
			image->bigest_z = -point[vertical].z;
	}
	point[ind.x].exist = 0;
}

void	set_same_value(t_coor ***dest,
	t_coor **source, int x, int y)
{
	int	vertical;

	vertical = 0;
	while (vertical < x)
	{
		(*dest)[y][vertical].x = source[y][vertical].x;
		(*dest)[y][vertical].y = source[y][vertical].y;
		(*dest)[y][vertical].z = source[y][vertical].z;
		(*dest)[y][vertical].color = source[y][vertical].color;
		(*dest)[y][vertical].exist = source[y][vertical].exist;
		vertical++;
	}
	(*dest)[y][x].exist = source[y][x].exist;
}
