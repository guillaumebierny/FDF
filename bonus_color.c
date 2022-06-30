/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:44:54 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:10:19 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	cond_color(unsigned int color, t_as *as)
{
	if (as->image->color == color && as->image->switch_color == 1)
		return (0);
	as->image->color = color;
	as->image->switch_color = 1;
	return (1);
}

void	change_color(int kc, t_as *as)
{
	unsigned int	color_to_get;
	int				x;
	int				y;

	color_to_get = 0;
	if (kc != KEY_B && kc != KEY_G && kc != KEY_R && kc != KEY_N)
		return ;
	if (kc == KEY_N)
	{
		as->image->switch_color = 0;
		return ;
	}
	if (kc == KEY_B && cond_color(0xFF, as))
		return ;
	if (kc == KEY_G && cond_color(0xFF00, as))
		return ;
	if (kc == KEY_R && cond_color(0xFF0000, as))
		return ;
}

void	degrade_color_mode(int kc, t_as *as)
{
	if (kc != KEY_H)
		return ;
	as->image->switch_color = 2;
	if (as->image->switch_color == 2)
	{
		as->incr_r = ((unsigned int)((double)0xFF / (double)(as->image->bigest_z
						- (double)as->image->lowest_z)));
		as->incr_g = ((unsigned int)((double)0xFF / (double)(as->image->bigest_z
						- as->image->lowest_z)));
		as->incr_b = (unsigned int)(0xFF / (double)(as->image->bigest_z
					- as->image->lowest_z));
	}
}
