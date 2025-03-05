/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:50:10 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:19:35 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "./cube3d.h"
# include <stdbool.h>
# define MAX_SPRITE 1000
# define SCREEN_WIDTH 1280
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 0.132
# define SCREEN_HEIGHT 720
# define MLX 1
# define WIN 2
# define EXTERN_MAP 5
# define EMPTY 0
# define WALL 1
# define PLAYER 2
# define COIN 9
# define CLOSED_DOOR 8
# define OPENED_DOOR 7
# define ERROR_MAP -1
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define FLOOR 5
# define CEIL 6
# define FRAME_SPEED 4
# define TILE_VOID 0
# define TILE_WALL 1
# define TILE_PLAYER 2
# define TILE_DOOR 3
# define ORIENTATION_THRESHOLD 0.66
# define PLANE 0.66
# define TEXTURES_MAX 6
# define UNSET 0
# define COIN_SPRITE 1
# define MAP_TILES_SPRITES 2
# define MAP_TILES_LENGTH 5
# define DBL_MAX 1.7976931348623157e+308
# define GLOBAL_ERR_MSG "Error\n"
# define MAP_LENGTH_ERROR "The map must have the same length in all lines\n"
# define MAP_ERROR "Please, check it's a valid map"
# define MAP_AROUND_PLAYER 10
# define SPRITE t_sprite
# define SPRITE_DATA t_sprite_data

typedef struct s_sprite_calc
{
	int				texture_x;
	int				texture_y;
	int				color;
	int				index;
	int				texture_y_offset;
}					t_sprite_calc;

typedef struct s_ipoint
{
	int				x;
	int				y;
}					t_ipoint;

typedef struct s_point
{
	double			x;
	double			y;
	int				p_x;
	int				p_y;
	int				color;
}					t_point;

typedef struct s_player
{
	t_point			pos;
	t_point			dir;
	t_point			plan;
	int				map_x;
	int				map_y;
}					t_player;

typedef struct s_graphics
{
	int				ceil_color_temp;
	int				floor_color_temp;
	char			*north_wall_path;
	char			*south_wall_path;
	char			*east_wall_path;
	char			*west_wall_path;
	char			*door_path;
	char			*open_door_path;
	short			floor_color[3];
	short			ceil_color[3];
}					t_graphics;

typedef struct s_texture
{
	int				coor_x;
	int				coor_y;
	int				direction;
	double			step;
	double			wall_distance;
	double			position;

}					t_texture;

typedef struct s_image
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				distance;

}					t_image;

typedef struct s_calculation
{
	int				start;
	int				end;
	int				x;
	int				y;
	int				step;
	int				step_x;
	int				step_y;
	int				collission;
	int				door_found;
	int				line_height;
	int				line_length;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			camera_x;
	double			distance_wall;
}					t_calculation;

typedef struct s_sprite
{
	int				frame;
	int				frame_pos;
	long long int	count;
	t_image			*frames;

}					t_sprite;

typedef struct s_sprite_data
{
	int				x;
	int				y;
	int				screen_x;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				width;
	int				height;
	bool			can_display;
	double			transform_x;
	double			transform_y;
	int				type;
	double			distance;
}					t_sprite_data;

typedef struct s_mouse
{
	int				x_pos;
	int				y_pos;
	int				oldx;
}					t_mouse;

typedef struct s_map_data
{
	t_ipoint		offset;
	t_ipoint		start;
	t_ipoint		end;
}					t_map_data;

typedef struct s_draw
{
	int				x;
	int				y;
	int				delta_x;
	int				delta_y;
	int				add_x;
	int				add_y;
	int				slope;
	int				error;
	int				add_error;
}					t_draw;

typedef struct s_params
{
	void			*mlx;
	void			*win;
	int				error;
	int				x_check;
	int				y_check;
	bool			gradient;
	bool			bonus_map;
	int				mlx_status;
	int				close;
	bool			cursor_hide;
	int				score;
	int				screen_width;
	int				screen_height;
	int				map_height;
	int				map_width;
	int				move_forward;
	int				move_backwards;
	int				move_left;
	int				move_right;
	bool			show_map;
	int				free_stage;
	int				free_sprite_stage;
	int				rotate_right;
	int				rotate_left;
	int				orientation;
	int				**world_map;
	double			*zbuffer;
	double			*zdoor;
	int				gsv[6];
	t_mouse			mouse;
	t_image			image;
	t_image			doors;
	t_image			map_image;
	t_calculation	calc;
	t_player		player;
	t_player		map_player;
	t_texture		texture;
	t_image			texture_image[TEXTURES_MAX];
	t_graphics		*graphics;
	SPRITE			**map_tiles;
	SPRITE			*coins;
	int				sprites_nbr;
	SPRITE_DATA		sprites[MAX_SPRITE];
}					t_params;

typedef struct s_render_sprite
{
	int				x;
	t_params		*var;
	t_sprite_calc	calc;
	int				i;
	int				y;
	t_sprite		*spr;

}					t_render_sprite;

typedef struct s_position
{
	int				x;
	int				y;
	int				col;
	int				row;
}					t_position;

typedef struct s_sprite_transform
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
}					t_sprite_transform;

#endif
