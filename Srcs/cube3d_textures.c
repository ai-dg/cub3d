/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/02 13:07:10 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	set_texture_image_addr(t_image *texture_image)
{
	texture_image->addr = (int *)mlx_get_data_addr(texture_image->img,
			&texture_image->bits_per_pixel, &texture_image->line_length,
			&texture_image->endian);
}

void	get_addr_libx(t_params *var)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (var->texture_image[i].img)
			set_texture_image_addr(&var->texture_image[i]);
		i++;
	}
}

static void	set_texture(t_params *var, int step, char *path)
{
	var->texture_image[step].img = mlx_xpm_file_to_image(var->mlx,
			path, &(var->texture_image[step].width),
			&(var->texture_image[step].height));
}

static void	get_xpm_and_addr_textures(t_params *var)
{
	var->free_stage++;
	set_texture(var, 0, var->graphics->north_wall_path);
	if (!var->texture_image[0].img)
		exit_on_error(var, "Error loading north texture");
	set_texture(var, 1, var->graphics->south_wall_path);
	if (!var->texture_image[1].img)
		exit_on_error(var, "Error loading  south texture");
	set_texture(var, 2, var->graphics->east_wall_path);
	if (!var->texture_image[2].img)
		exit_on_error(var, "Error loading east texture");
	set_texture(var, 3, var->graphics->west_wall_path);
	if (!var->texture_image[3].img)
		exit_on_error(var, "Error loading west texture");
	if (var->graphics->door_path)
	{
		set_texture(var, 4, var->graphics->door_path);
		if (!var->texture_image[4].img)
			exit_on_error(var, "Error loading door texture");
		set_texture(var, 5, var->graphics->open_door_path);
		if (!var->texture_image[5].img)
			exit_on_error(var, "Error loading open door texture");
	}
}

void	get_xpm_and_addr(t_params *var)
{
	get_xpm_and_addr_textures(var);
	var->free_stage++;
	get_addr_libx(var);
}
