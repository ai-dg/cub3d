/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_on_exit_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:31:53 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 00:36:45 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_world_map(t_params *var)
{
	free(var->world_map);
	ft_printf("destroy world_map...\n");
}

void	destroy_map(t_params *var)
{
	int	i;

	i = 0;
	while (i < var->map_height + 1)
	{
		free_variable((void **)&var->world_map[i]);
		i++;
	}
}

void	destroy_graphics_paths(t_params *var)
{
	if (var->graphics->north_wall_path)
		free_variable((void **)&var->graphics->north_wall_path);
	if (var->graphics->south_wall_path)
		free_variable((void **)&var->graphics->south_wall_path);
	if (var->graphics->east_wall_path)
		free_variable((void **)&var->graphics->east_wall_path);
	if (var->graphics->west_wall_path)
		free_variable((void **)&var->graphics->west_wall_path);
	if (var->graphics->door_path)
		free_variable((void **)&var->graphics->door_path);
	if (var->graphics->open_door_path)
		free_variable((void **)&var->graphics->open_door_path);
	ft_printf("destroy_textures...\n");
}

void	destroy_graphics(t_params *var)
{
	if (var->graphics)
		free_variable((void **)&var->graphics);
	ft_printf("destroy_graphics...\n");
}
