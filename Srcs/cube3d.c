/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/03 20:14:35 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	check_args(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (ac < 2 || ac > 2)
	{
		ft_fprintf(stderr, "%s\033[031mINVALID NUMBER OF ARGS ! YOU MUST PASS ",
			GLOBAL_ERR_MSG);
		ft_fprintf(stderr, "A SINGLE .cub file\n\033[0m");
		exit(EXIT_FAILURE);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_fprintf(stderr,
				"%s\033[031mINVALID NUMBER OF ARGS ! YOU MUST PASS ",
				GLOBAL_ERR_MSG);
			ft_fprintf(stderr, "THE PATH OF A VALID *.cub file\n\033[0m");
			exit(EXIT_FAILURE);
		}
		close(fd);
	}
}

int	main(int ac, char **av)
{
	t_params	var;

	check_args(ac, av);
	ft_bzero(&var, sizeof(t_params));
	init_minilibx(&var);
	parsing_graphics(av[1], &var);
	found_map_dimensions(av[1], &var);
	init_map(&var);
	set_sprites_map(&var);
	parsing_map(av[1], &var);
	check_map(&var);
	init_map_tiles(&var);
	parsing_sprites(av[1], &var);
	set_texture_image_to_null(&var);
	get_xpm_and_addr(&var);
	init_main_image(&var);
	init_var(&var);
	init_calc(&var);
	set_sprites_distance(&var);
	var.zbuffer = init_zbuffer(&var, var.zbuffer);
	var.zdoor = init_zbuffer(&var, var.zdoor);
	get_mouse_pos(&var);
	cube3d_cycle(&var);
	return (EXIT_SUCCESS);
}
