/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_draw_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:55:55 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:18:42 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	set_tile_and_player(t_map_data *map, int col,
	int row, t_params *var)
{
	img_put_tile(var, var->map_tiles[TILE_VOID], (int)map->offset.x + col
		* 16, (int)map->offset.y + row * 16);
	var->player.pos.p_x = (int)map->offset.x + col * 16 + 8;
	var->player.pos.p_y = (int)map->offset.y + row * 16 + 8;
}

static void	draw_tile(t_params *var, t_map_data *map, t_position pos, int tile)
{
	int	col;
	int	row;

	col = pos.col;
	row = pos.row;
	if (tile == 0 || tile == 9 || tile == 7)
		img_put_tile(var, var->map_tiles[TILE_VOID], (int)map->offset.x + col
			* 16, (int)map->offset.y + row * 16);
	else if (tile == 1)
		img_put_tile(var, var->map_tiles[TILE_WALL], (int)map->offset.x + col
			* 16, (int)map->offset.y + row * 16);
	else if (tile == 2)
		set_tile_and_player(map, col, row, var);
	else if (tile == 8)
		img_put_tile(var, var->map_tiles[TILE_DOOR], (int)map->offset.x + col
			* 16, (int)map->offset.y + row * 16);
	else
		img_put_tile(var, var->map_tiles[TILE_VOID], (int)map->offset.x + col
			* 16, (int)map->offset.y + row * 16);
}

static void	draw_map_tiles(t_params *var, t_map_data *map, t_position pos)
{
	int	tile;

	while (pos.y < map->end.y)
	{
		while (pos.x < map->end.x)
		{
			tile = var->world_map[pos.y][pos.x];
			draw_tile(var, map, pos, tile);
			pos.col++;
			pos.x++;
		}
		pos.col = 0;
		pos.x = map->start.x;
		pos.row++;
		pos.y++;
	}
}

int	draw_map(t_params *var)
{
	t_map_data	map;
	t_position	pos;

	set_limits(var, &map);
	pos.row = 0;
	pos.col = 0;
	pos.x = map.start.x;
	pos.y = map.start.y;
	draw_map_tiles(var, &map, pos);
	draw_player(var);
	return (0);
}
