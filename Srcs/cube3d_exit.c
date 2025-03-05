/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/17 11:06:16 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	exit_on_error(t_params *var, char *msg)
{
	static void	(*exe[])(t_params *) = {destroy_minilibx, destroy_graphics,
		destroy_graphics_paths, destroy_world_map, destroy_map,
		destroy_map_tiles, destroy_sprites, destroy_texture_images,
		destroy_main_image, free_zbuffer, free_zdoor};

	if (msg)
	{
		ft_fprintf(stderr, "%s", GLOBAL_ERR_MSG);
		ft_fprintf(stderr, "%s\n", msg);
	}
	if (var->free_stage == -1)
		exit(1);
	else
	{
		while (var->free_stage > 0)
		{
			exe[var->free_stage - 1](var);
			var->free_stage--;
		}
		exit(1);
	}
}

void	destroy_texture_images(t_params *var)
{
	int	i;

	i = 0;
	while (i < TEXTURES_MAX)
	{
		if (var->texture_image[i].img)
			mlx_destroy_image(var->mlx, var->texture_image[i].img);
		i++;
	}
	ft_printf("destroy texture images\n");
}

void	destroy_minilibx(t_params *var)
{
	if (var->mlx_status == WIN)
		mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	ft_printf("destroy minilibx...\n");
}

void	destroy_main_image(t_params *var)
{
	mlx_destroy_image(var->mlx, var->image.img);
	ft_printf("destroy main image...\n");
}
