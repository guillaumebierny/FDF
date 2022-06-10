/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:44:54 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 15:17:50 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	cond_color(unsigned int color, t_all_struct *as)
{
	if (as->image->color == color && as->image->switch_color == 1)
		return (0);
	as->image->color = color;
	as->image->switch_color = 1;
	return (1);
}

void	change_color(int kc, t_all_struct *as)
{
	unsigned int	color_to_get;
	int				x;
	int				y;

	color_to_get = 0;
	if (kc != 11 && kc != 5 && kc != 15 && kc != 45)
		return ;
	if (kc == 45)
	{
		as->image->switch_color = 0;
		return ;
	}
	if (kc == 11 && cond_color(0xFF, as))
		return ;
	if (kc == 5 && cond_color(0xFF00, as))
		return ;
	if (kc == 15 && cond_color(0xFF0000, as))
		return ;
}

void	degrade_color_mode(int kc, t_all_struct *as)
{
	if (kc != 2)
		return ;
	as->image->switch_color = 2;
	printf("ON PASSE PAR LA!!!!\n");
	if (as->image->switch_color == 2)
	{
		as->incr_r = ((unsigned int)((double)0xFF / (double)(as->image->bigest_z
						- (double)as->image->lowest_z)));
		as->incr_g = ((unsigned int)((double)0xFF / (double)(as->image->bigest_z
						- as->image->lowest_z)));
		as->incr_b = (unsigned int)(0xFF / (double)(as->image->bigest_z
					- as->image->lowest_z));
	}
	// printf("%X | %X | %X\n", as->incr_r, as->incr_g, as->incr_b);
}
