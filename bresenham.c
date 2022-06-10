/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 07:43:53 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 17:12:36 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int framing(int little_var, int big_var)
{
    if (big_var >= little_var)
        return ((big_var - little_var) / 2);
    else
        return (-(little_var - big_var) / 2);
}

void get_right_incrementation(int *x_incr, int *y_incr, t_coordonnees point1, t_coordonnees point2)
{
    if (point1.x < point2.x)
        *x_incr = 1;
    else
        *x_incr = -1;
    if (point1.y < point2.y)
        *y_incr = 1;
    else
        *y_incr = -1;
}

void    red_case(t_bres_v *bres, unsigned int *color, double spacing, double i)
{
	if (bres->r1 == bres->r2)
		*color += bres->r1 << 16;
	if (bres->r1 < bres->r2)
		*color += (bres->r1 << 16) + (((unsigned int)(((double)(bres->r2 - bres->r1) / spacing) * i)) << 16);
	if (bres->r1 > bres->r2)
		*color += (bres->r1 << 16) - (((unsigned int)(((double)(bres->r1 - bres->r2) / spacing) * i)) << 16);
}

void    green_case(t_bres_v *bres, unsigned int *color, double spacing, double i)
{
	if (bres->g1 == bres->g2)
		*color += bres->g1 << 8;
	if (bres->g1 < bres->g2)
		*color += (bres->g1 << 8) + (((unsigned int)(((double)(bres->g2 - bres->g1) / spacing) * i)) << 8);
	if (bres->g1 > bres->g2)
		*color += (bres->g1 << 8) - (((unsigned int)(((double)(bres->g1 - bres->g2) / spacing) * i)) << 8);
}

void   blue_case(t_bres_v *bres, unsigned int *color, double spacing, double i)
{
	if (bres->b1 == bres->b2)
		*color += bres->b1;
	if (bres->b1 < bres->b2)
		*color += bres->b1 + (unsigned int)(((double)(bres->b2 - bres->b1) / spacing) * i);
	if (bres->b1 > bres->b2)
		*color += bres->b1 - (unsigned int)(((double)(bres->b1 - bres->b2) / spacing) * i);
}

unsigned int    degraded_for_line(t_bres_v *bres, double i, double spacing)
{
	unsigned int color;

	color = 0;
	if (bres->color_point1 == bres->color_point2)
		return (bres->color_point1);
	red_case(bres, &color, spacing, i);
	green_case(bres, &color, spacing, i);
	blue_case(bres, &color, spacing, i);
    return (color);
}

void    bresenham_dx_bigger(t_bres_v *bres, t_image *image, int framing_w, int framing_h)
{
    if (bres->Dx >= bres->Dy)
    {
        
        while (bres->i < bres->Dx)
        {
            my_mlx_pixel_put(image, bres->x1 + framing_w + image->t_horizontal, bres->y1 + framing_h + image->t_vertical, degraded_for_line(bres, (double)bres->i, (double)bres->Dx));
            bres->x1 += bres->x_incr;
			bres->ex -= bres->dy;
            if (bres->ex < 0)
            {
                bres->ex += bres->dx;
                bres->y1 += bres->y_incr;
            }
            bres->i++;
        }
    }
}

void    bresenham_dy_bigger(t_bres_v *bres, t_image *image, int framing_w, int framing_h)
{
    if (bres->Dx < bres->Dy)
    {
        bres->i = 0;
        while (bres->i < bres->Dy)
        {
            my_mlx_pixel_put(image, bres->x1 + framing_w + image->t_horizontal, bres->y1 + framing_h + image->t_vertical, degraded_for_line(bres, (double)bres->i, (double)bres->Dy));
            bres->ey -= bres->dx;
            bres->y1 += bres->y_incr;
            if (bres->ey < 0)
            { 
				bres->x1 += bres->x_incr;
				bres->ey += bres->dy;
            }
            bres->i++;
        }
    }
}

void    bresenham_algo(t_coordonnees p[4], t_all_struct *as, t_index ind)
{
    int framing_w;
    int framing_h;
    t_bres_v bres;
    
    bres = initialyse_t_bres_v(p[0], p[1], as->image);
    if (as->image->switch_color == 1)
    {
        bres.color_point1 = as->image->color;
        bres.color_point2 = as->image->color;
    }
    if (as->image->switch_color == 2)
    {
        get_color_by_z(&bres.color_point1, p[2], as); 
        get_color_by_z(&bres.color_point2, p[3], as);
    }
    bres.r1 = (get_right_r(bres.color_point1));
    bres.g1 = (get_right_g(bres.color_point1));
    bres.b1 = get_right_b(bres.color_point1);
    bres.r2 = (get_right_r(bres.color_point2));
    bres.g2 = (get_right_g(bres.color_point2));
    bres.b2 = get_right_b(bres.color_point2);
    // printf("color point1 et 2 : %X | %X\n", bres.color_point1, bres.color_point2);
    // printf("r1r2 g1 g2...: %X | %X | %X | %X | %X | %X\n", bres.r1, bres.r2, bres.g1, bres.g2, bres.b1, bres.b2);
    framing_w = framing(as->image->width, WIDTH) - as->image->minest_x;
    framing_h = framing(as->image->height, HEIGHT) - as->image->higher;
    bresenham_dx_bigger(&bres, as->image, framing_w, framing_h);
    bresenham_dy_bigger(&bres, as->image, framing_w, framing_h);
}

void    make_bresenham(t_coordonnees **point, t_all_struct *as)
{
    t_index ind;
    t_coordonnees p[4];
    ind.y = 0;
    while (point[ind.y][0].exist)
    {
        ind.x = 0;
        while (point[ind.y][ind.x].exist)
        {
            
            if (point[ind.y][ind.x + 1].exist)
            {
                p[0] = point[ind.y][ind.x];
                p[1] = point[ind.y][ind.x + 1];
                p[2] = (*as->p3d)[ind.y][ind.x];
                p[3] = (*as->p3d)[ind.y][ind.x + 1];
                bresenham_algo(p, as, ind);
            }
            if (point[ind.y + 1][0].exist)
            {
                p[0] = point[ind.y][ind.x];
                p[1] = point[ind.y + 1][ind.x];
                p[2] = (*as->p3d)[ind.y][ind.x];
                p[3] = (*as->p3d)[ind.y + 1][ind.x];
                bresenham_algo(p, as, ind);
            }
            ind.x++;
        }
        ind.y++;
    }
}
