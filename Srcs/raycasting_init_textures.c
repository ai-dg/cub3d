/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/07 09:39:48 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	set_texture_direction(t_params *var)
{
	if (var->calc.step == 0)
	{
		if (var->calc.ray_dir_x < 0)
			var->texture.direction = 0;
		else
			var->texture.direction = 1;
	}
	else
	{
		if (var->calc.ray_dir_y < 0)
			var->texture.direction = 2;
		else
			var->texture.direction = 3;
	}
	if (var->calc.collission == 2)
		var->texture.direction = 4;
	if (var->calc.collission == 3 && var->calc.door_found == 1)
		var->texture.direction = 5;
}

static void	calculate_texture_position(t_params *var)
{
	double	texture_pos;

	if (var->calc.step == 0)
	{
		texture_pos = var->player.pos.y + var->calc.distance_wall
			* var->calc.ray_dir_y;
	}
	else
	{
		texture_pos = var->player.pos.x + var->calc.distance_wall
			* var->calc.ray_dir_x;
	}
	var->texture.wall_distance = texture_pos - floor(texture_pos);
}

void	init_texture_image(t_params *var)
{
	set_texture_direction(var);
	calculate_texture_position(var);
}
