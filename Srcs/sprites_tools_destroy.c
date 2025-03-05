/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:24:19 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:29:03 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	destroy_coin_sprite(t_params *var)
{
	free_variable((void **)&var->coins);
}

void	destroy_coin_frames(t_params *var)
{
	free_variable((void **)&var->coins->frames);
}

void	destroy_coin_images(SPRITE **sprite)
{
	free((*sprite)->frames);
}

void	destroy_sprite(t_params *var, SPRITE **sprite)
{
	int	i;

	i = 0;
	if (!*sprite)
		return ;
	while (i < (*sprite)->frame)
	{
		mlx_destroy_image(var->mlx, (*sprite)->frames[i].img);
		i++;
	}
	free_variable((void **)&(*sprite)->frames);
	free(*sprite);
}

void	destroy_sprites(t_params *var)
{
	int	i;

	i = 0;
	if (var->free_sprite_stage <= MAP_TILES_SPRITES)
	{
		destroy_sprite(var, &var->coins);
	}
	if (var->free_sprite_stage == MAP_TILES_SPRITES)
	{
		while (i < MAP_TILES_LENGTH)
		{
			if (var->map_tiles[i])
			{
				destroy_sprite(var, &var->map_tiles[i]);
			}
			i++;
		}
	}
	ft_printf("destroy sprites...\n");
}
