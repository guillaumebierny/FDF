/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:01:49 by gbierny           #+#    #+#             */
/*   Updated: 2022/07/20 19:05:50 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	dup_tab_point_utils(int *x, int *y, t_coor **source)
{
	while (source[(*y)][0].exist)
		(*y)++;
	while (source[0][(*x)].exist)
		(*x)++;
}
