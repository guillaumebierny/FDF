/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:30:43 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/30 19:47:29 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	clise(int kc, t_as *as)
{
	if (kc == 53)
	{
		mlx_destroy_window(as->mlx_vars->mlx, as->mlx_vars->win_mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	wrong_number_case(int argc)
{
	if (argc == 1)
		error_message("vous n'avez pas rentre de fichier");
	if (argc > 2)
		error_message("vous avez trop d'arguments");
}

int	main(int argc, char **argv)
{
	t_image			image;
	t_mlx_vars		mlx_vars;
	t_coor			**point[3];
	t_as			as;

	wrong_number_case(argc);
	mlx_vars = initialyze_mlx_vars();
	image = initialyze_image();
	as = initialyze_all_struct(&mlx_vars);
	as.mlx_vars->mlx = mlx_init();
	as.mlx_vars->win_mlx = mlx_new_window(as.mlx_vars->mlx,
			WIDTH, HEIGHT, "window_of_my_game");
	as.image = &image;
	get_point(argv[1], as.image, &point[0]);
	dup_tab_point(point[0], &point[2]);
	dup_tab_point(point[0], &point[1]);
	gather_struct(&as, &point[0], &point[1], &point[2]);
	resize_the_image(image, &as);
	make_bresenham(*as.p2d, &as);
	mlx_put_image_to_window(as.mlx_vars->mlx, as.mlx_vars->win_mlx,
		as.image->img, 0, 0);
	mlx_hook(as.mlx_vars->win_mlx, 2, 1L << 0, clise, &as);
	mlx_loop(as.mlx_vars->mlx);
	return (0);
}
