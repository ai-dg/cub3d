/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_on_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:31:53 by ls                #+#    #+#             */
/*   Updated: 2024/09/30 15:03:37 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_on_map_error(t_params *var, int stage, char *msg)
{
	int	i;

	i = 0;
	while (i < stage)
	{
		if (!var->world_map[i])
			break ;
		free_variable((void **)&var->world_map[i]);
		i++;
	}
	exit_on_error(var, msg);
}

void	free_sprite(t_params *var, SPRITE *sprite)
{
	int	i;

	(void)var;
	i = 0;
	while (i < sprite->frame)
	{
		mlx_destroy_image(var->mlx, sprite->frames[i].img);
		i++;
	}
	free_variable((void **)&sprite->frames);
	free_variable((void **)&sprite);
}

void	free_sprite_array(t_params *var, SPRITE **sprite)
{
	int	i;
	int	j;

	(void)var;
	i = 0;
	j = 0;
	while (sprite[j])
	{
		while (i < sprite[j]->frame)
		{
			mlx_destroy_image(var->mlx, sprite[j]->frames[i].img);
			i++;
		}
		free_variable((void **)&sprite[j]->frames);
		free_variable((void **)&sprite[j]);
	}
	free(sprite);
}

void	free_memory(t_params *var)
{
	free_zdoor(var);
	free_zbuffer(var);
	destroy_main_image(var);
	destroy_texture_images(var);
	destroy_sprites(var);
	destroy_map_tiles(var);
	destroy_map(var);
	destroy_world_map(var);
	destroy_graphics_paths(var);
	destroy_graphics(var);
	destroy_minilibx(var);
	exit(0);
}
