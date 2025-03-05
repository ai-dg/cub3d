/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_put_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 17:13:00 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	calculate_texture_steps(t_params *var)
{
	var->texture.step = 1.0 * var->texture_image[var->texture.direction].height
		/ var->calc.line_height;
	var->texture.coor_x = (int)(var->texture.wall_distance
			* var->texture_image[var->texture.direction].width);
	if ((var->calc.step == 0 && var->calc.ray_dir_x > 0) || (var->calc.step == 1
			&& var->calc.ray_dir_y < 0))
	{
		var->texture.coor_x = var->texture_image[var->texture.direction].width
			- var->texture.coor_x - 1;
	}
	var->texture.position = (var->calc.start - var->screen_height / 2
			+ var->calc.line_height / 2) * var->texture.step;
}

static void	apply_texture_color(t_params *var, int index, int color)
{
	if (var->texture.direction != 5)
	{
		var->image.addr[index] = color;
	}
	if (var->texture.direction == 5 && var->calc.door_found == 1)
	{
		if ((color & 0x00FFFFFF) != 0 && (color & 0xFF000000) == 0)
		{
			var->doors.addr[index] = color;
		}
	}
}

static void	handle_texture_positions(t_params *var, int i, int j)
{
	int	index;
	int	color;
	int	texture_height;
	int	line_length;
	int	*texture_addr;

	texture_height = var->texture_image[var->texture.direction].height;
	line_length = var->texture_image[var->texture.direction].line_length / 4;
	texture_addr = var->texture_image[var->texture.direction].addr;
	j = var->calc.start - 1;
	while (++j <= var->calc.end)
	{
		var->texture.coor_y = (int)var->texture.position & (texture_height - 1);
		var->texture.position += var->texture.step;
		if (j < var->screen_height && i < var->screen_width)
		{
			index = j * var->image.line_length / 4 + i;
			color = texture_addr[var->texture.coor_y * line_length
				+ var->texture.coor_x];
			apply_texture_color(var, index, color);
		}
	}
}

void	put_textures_from_images(t_params *var, int i, int j)
{
	init_texture_image(var);
	calculate_texture_steps(var);
	handle_texture_positions(var, i, j);
}
