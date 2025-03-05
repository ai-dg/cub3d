/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:24:19 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 12:00:17 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	validate_sprite_format(char **sp, t_params *var, int fd)
{
	if (ft_count_args(sp) != 4)
	{
		free_array(&sp);
		close(fd);
		exit_on_error(var, "Invalid sprite format");
	}
}

static void	init_map_tile_sprite(t_params *var, char *type, int frame,
		char *path)
{
	if (ft_strncmp(type, "WALL", ft_strlen(type)) == 0)
		init_sprite(var, &var->map_tiles[TILE_WALL], frame, path);
	else if (ft_strncmp(type, "PLAYER", ft_strlen(type)) == 0)
		init_sprite(var, &var->map_tiles[TILE_PLAYER], frame, path);
	else if (ft_strncmp(type, "DOOR", ft_strlen(type)) == 0)
		init_sprite(var, &var->map_tiles[TILE_DOOR], frame, path);
}

static void	handle_sprite_initialization(t_params *var, char *type, int frame,
		char *path)
{
	if (ft_strncmp(type, "M", ft_strlen(type)) == 0)
	{
		init_sprite(var, &var->coins, frame, path);
		var->free_stage++;
		var->free_sprite_stage = COIN_SPRITE;
	}
	else if (ft_strncmp(type, "VOID", ft_strlen(type)) == 0)
	{
		init_sprite(var, &var->map_tiles[TILE_VOID], frame, path);
		var->free_sprite_stage = MAP_TILES_SPRITES;
	}
	else
		init_map_tile_sprite(var, type, frame, path);
}

void	check_sprite(char *line, t_params *var, int fd)
{
	char	**sp;
	int		frame;
	char	*path;

	sp = ft_split(line, ' ');
	if (!sp)
	{
		close(fd);
		exit_on_error(var, "Fail on memory allocation");
	}
	validate_sprite_format(sp, var, fd);
	frame = ft_atoi(sp[2]);
	path = sp[3];
	handle_sprite_initialization(var, sp[1], frame, path);
	free_array(&sp);
}
