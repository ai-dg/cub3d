/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/04 11:04:47 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	init_var(t_params *var)
{
	var->show_map = false;
	var->gradient = false;
	var->cursor_hide = false;
}

void	set_texture_image_to_null(t_params *var)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_MAX)
		var->texture_image[0].img = NULL;
}

void	init_minilibx(t_params *var)
{
	var->free_stage = 0;
	var->mlx = mlx_init();
	if (!var->mlx)
	{
		ft_fprintf(stderr, "%sFailed to initialize MLX\n", GLOBAL_ERR_MSG);
		exit(EXIT_FAILURE);
	}
	var->mlx_status = MLX;
	var->screen_height = SCREEN_HEIGHT;
	var->screen_width = SCREEN_WIDTH;
	var->win = mlx_new_window(var->mlx, var->screen_width, var->screen_height,
			"Cub3D");
	if (!var->win)
	{
		ft_fprintf(stderr, "%sFailed to create window\n", GLOBAL_ERR_MSG);
		destroy_minilibx(var);
		exit(EXIT_FAILURE);
	}
	var->mlx_status = WIN;
	var->free_stage = 1;
	ft_printf("minilibx ok...\n");
}

void	init_main_image(t_params *var)
{
	var->image.img = mlx_new_image(var->mlx, var->screen_width,
			var->screen_height);
	if (!var->image.img)
		exit_on_error(var, "fail on init minilibx image");
	var->free_stage++;
	var->image.addr = (int *)mlx_get_data_addr(var->image.img,
			&var->image.bits_per_pixel, &var->image.line_length,
			&var->image.endian);
	ft_printf("main image ok...\n");
}

void	set_sprites_map(t_params *var)
{
	int	i;

	i = 0;
	while (i < MAX_SPRITE)
	{
		var->sprites[i].x = -1;
		var->sprites[i].y = -1;
		var->sprites[i].type = -1;
		var->sprites[i].distance = -1;
		i++;
	}
}
