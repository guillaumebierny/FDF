/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:47:31 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 07:31:37 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	resize(int i, double *zoom)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (i * (*zoom) <= 400)
		*zoom += 1;
}

void	get_mins(t_coordonnees point, int *min_x, int *min_y, t_image *image)
{
	if (point.x < *min_x)
	{
		*min_x = point.x;
		image->minest_x = *min_x;
	}
	if (point.y < *min_y)
	{
		*min_y = point.y;
		image->higher = *min_y;
	}
}

void	get_maxs(t_coordonnees point, int *max_x, int *max_y)
{
	if (point.x > *max_x)
		*max_x = point.x;
	if (point.y > *max_y)
		*max_y = point.y;
}

void	get_width_and_height(t_image *image, t_coordonnees **point)
{
	int	min[2];
	int	max[2];
	int	x;
	int	y;

	min[0] = 2147483647;
	max[0] = -2147483648;
	min[1] = 2147483647;
	max[1] = -2147483648;
	x = 0;
	y = 0;
	while (point[y][x].exist)
	{
		while (point[y][x].exist)
		{
			get_mins(point[y][x], &min[0], &min[1], image);
			get_maxs(point[y][x], &max[0], &max[1]);
			x++;
		}
		y++;
		x = 0;
	}
	image->width = (get_absolute(max[0] - min[0]));
	image->height = (get_absolute(max[1] - min[1]));
}

int	get_dimension_to_project(t_coordonnees **point, t_image *image)
{
	get_width_and_height(image, point);
	if (image->width < 400)
	{
		resize(image->width / image->zoom, &image->zoom);
		return (0);
	}
	return (1);
}
