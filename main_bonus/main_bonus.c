/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 06:26:37 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/10 06:27:12 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	main(int argc, char **argv)
{
	t_image			image;
	t_mlx_vars		mlx_vars;
	t_coordonnees	**point[3];
	t_all_struct	as;

	if (argc == 1)
		return (error_message("vous n'avez pas rentre de fichier"));
	if (argc > 2)
		return (error_message("vous avez trop d'arguments"));
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
	push_updated_image(&as);
	mlx_hook(as.mlx_vars->win_mlx, 2, 1L << 0, all_key_case, &as);
	mlx_loop(as.mlx_vars->mlx);
	return (0);
}