/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:50:10 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:01:49 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./colors.h"
# include "./data.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/**
 * @file check_map_tools.c
 *
 */

bool	flood_fill_internal(int **map, t_params *var, int x, int y);
void	map_checks(int **map, int x, int y, int *zero);
void	flood_fill(int **map, t_params *var, int x, int y);

/**
 * @file check_map.c
 *
 */

void	check_map(t_params *var);

/**
 * @file check_map_msg.c
 *
 */

void	msg_and_exit(t_params *var, char *msg, int i, int j);

/**
 * @file circles.c
 *
 */

void	draw_filled_circle(t_params *vars, t_point o, int radius, int color);

/**
 * @file collision_door.c
 *
 */

bool	is_door_in_front(t_params *var, int direction, int *x, int *y);

/**
 * @file collision.c
 *
 */

int		check_collision(t_params *var, double new_x, double new_y);
bool	is_in_map_range(t_params *var, int x, int y);
int		check_collision_coin(t_params *var, double new_x, double new_y);

/**
 * @file cub3d_exit.c
 *
 */

void	exit_on_error(t_params *var, char *msg);
void	destroy_texture_images(t_params *var);
void	destroy_minilibx(t_params *var);
void	destroy_main_image(t_params *var);

/**
 * @file cub3d_init.c
 *
 */

void	init_var(t_params *var);
void	set_texture_image_to_null(t_params *var);
void	init_minilibx(t_params *var);
void	init_main_image(t_params *var);
void	set_sprites_map(t_params *var);

/**
 * @file cub3d_textures.c
 *
 */

void	get_addr_libx(t_params *var);
void	get_xpm_and_addr(t_params *var);

/**
 * @file cub3d.c
 *
 */

void	check_args(int ac, char **av);
int		main(int ac, char **av);

/**
 * @file debug.c
 *
 */

void	print_paths(t_params *var);
void	print_colors(t_params *var);
void	print_datas(t_params *var);
void	print_sprites(t_params *var);

/**
 * @file doors.c
 *
 */

void	init_doors(t_params *var);
void	draw_doors(t_params *var);

/**
 * @file free_on_exit_destroy.c
 *
 */

void	destroy_world_map(t_params *var);
void	destroy_map(t_params *var);
void	destroy_graphics_paths(t_params *var);
void	destroy_graphics(t_params *var);

/**
 * @file free_on_exit.c
 *
 */

void	free_on_map_error(t_params *var, int stage, char *msg);
void	free_sprite(t_params *var, SPRITE *sprite);
void	free_sprite_array(t_params *var, SPRITE **sprite);
void	free_memory(t_params *var);

/**
 * @file parsing.c
 *
 */

void	parsing_map(char *file, t_params *var);
int		parsing_graphics(char *file, t_params *var);
void	init_position(t_params *var, int y, int x, int orientation);

/**
 * @file map_tools.c
 *
 */

void	replace_value_in_map(t_params *var, int new, int old);
void	print_world_map(int **world_map, t_params *var);
void	set_value_at_pos(t_params *var, int new, int x, int y);
bool	is_map_line(char *line);

/**
 * @file game_map_draw_map.c
 *
 */

int		draw_map(t_params *var);

/**
 * @file game_map_image.c
 *
 */

void	set_pix_color(t_image *img, int x, int y, int color);
void	fill_img(t_params *var, int start_x, int start_y, int color);
void	img_put_tile(t_params *var, SPRITE *sprite, int start_x, int start_y);

/**
 * @file game_map_limits.c
 *
 */

void	set_map_x_limits(t_params *var, int *start, int *end);
void	set_map_y_limits(t_params *var, int *start, int *end);
void	set_limits(t_params *var, t_map_data *map);

/**
 * @file game_map.c
 *
 */

void	resize_point(int *p, int max);
void	draw_player(t_params *var);
void	show_map(t_params *var);

/**
 * @file handle_drawers.c
 *
 */

void	set_drawer(t_draw *drawer, t_point o, t_point dest);

/**
 * @file handle_keyboard_door.c
 *
 */

void	toogle_door(t_params *var, int x, int y);
void	check_open_door(t_params *var);
void	handle_space_key(t_params *var);

/**
 * @file handle_keyboard.c
 *
 */

int		handle_key_press(int key, t_params *var);
int		handle_close(t_params *var);
int		handle_key_release(int key, t_params *var);

/**
 * @file handle_mouse.c
 *
 */

void	get_mouse_pos(t_params *var);
int		mouse_hook(int mousecode, int x, int y, t_params *var);

/**
 * @file init.c
 */

void	destroy_map_tiles(t_params *var);
void	init_map_tiles(t_params *var);
int		init_map(t_params *var);
void	init_calc(t_params *var);

/**
 * @file init_bonus.c
 */

void	init_bonus_part(t_params *var, char *line);

/**
 * @file lines.c
 */

void	draw_v_lines(t_point o, t_point dest, t_params *var);
void	draw_h_lines(t_point o, t_point dest, t_params *var);
void	draw_more_h_lines(t_point o, t_point dest, t_params *var);
void	draw_more_v_lines(t_point o, t_point dest, t_params *var);
void	mlx_draw_line(t_point *o, t_point *dest, t_params *var, int color);

/**
 * @file map_dimensions.c
 *
 */

void	handle_fd_error(t_params *var, int fd, char *msg);
void	found_map_dimensions(char *path, t_params *var);
bool	ft_is_single_char(char *line, char c);

/**
 * @file map_tools.c
 *
 */

void	print_world_map(int **world_map, t_params *var);
void	replace_value_in_map(t_params *var, int new, int old);
void	set_value_at_pos(t_params *var, int new, int x, int y);
bool	allowed_for_map(char *line);
bool	is_map_line(char *line);

/**
 * @file map_tools2.c
 *
 */

int		**copy_map(int **map, int height, int width);
void	free_map(int **map, int height);
void	replace_map_data(t_params *var);
void	check_valid_char(t_params *var);

/**
 * @file moves.c
 *
 */

void	moves_rotate(t_params *var);
void	moves_player(t_params *var);

/**
 * @file math_tools.c
 */

int		get_orientation(t_params *var);

/**
 * @file math_tools.c
 */

void	rotate_vector(double *x, double *y, double cos_angle, double sin_angle);
int		get_sign(int nbr);

/**
 * @file mlx_cycles.c
 */

int		loop_hook(t_params *var);
void	cube3d_cycle(t_params *var);

/**
 * @file moves_rotation.c
 */

void	moves_rotate(t_params *var);

/**
 * @file moves.c
 */

void	update_position(t_params *var, double x, double y);
void	longitudinal_move(t_params *var, double *x, double *y);
void	moves_player(t_params *var);

/**
 * @file parsing_color.c
 */

int		set_rgb_from_line(char *line, t_params *var);
int		get_color_from_array(short *color_array);
void	set_color_from_rbg(t_graphics *graphics);

/**
 * @file parsing_graphics.c
 */

int		init_graphics(t_graphics *graphics);
void	check_graphics(t_params *var);
int		parsing_graphics(char *file, t_params *var);

/**
 * @file parsing_map.c
 */

void	parsing_map(char *file, t_params *var);

/**
 * @file parsing_set_map.c
 */

int		set_map(char *line, int y_pos, t_params *var);

/**
 * @file parsing_tools.c
 */

char	*get_new_line(char *line, int fd);
bool	is_authorised_char(char c);

/**
 * @file parsing_map.c
 */

void	add_sprite(t_params *var, int y_pos, int x, int type);
int		check_line(char *line, t_params *var, int *comp);
char	*get_path_from_line(t_params *var, char *line);
int		count_printable(char *str);

/**
 * @file printer.c
 */

void	print_score(t_params *var);

/**
 * @file raycasting_distance_limits.c
 *
 */

void	calculation_distance_steps(t_params *var);
void	calculate_wall_distance(t_params *var, int is_x_direction);
void	calculate_line_limits(t_params *var);
void	calculation_start_and_end(t_params *var);

/**
 * @file raycasting_init_textures.c
 *
 */

void	init_texture_image(t_params *var);

/**
 * @file raycasting_map_side_dist.c
 *
 */

void	calculation_map_side_dist(t_params *var);

/**
 * @file raycasting_put_textures.c
 *
 */

void	put_textures_from_images(t_params *var, int i, int j);

/**
 * @file raycasting_variable_calc.c
 *
 */

void	calculate_delta_distance_save(double ray_dir_x, double ray_dir_y,
			double *delta_dist_x, double *delta_dist_y);
void	calculate_delta_distance(double ray_dir_x, double ray_dir_y,
			double *delta_dist_x, double *delta_dist_y);
void	variable_declaration_calc(t_params *var);

/**
 * @file raycasting.c
 *
 */

void	draw_ceiling(t_params *var, int *j);
void	draw_floor(t_params *var, int *j);
void	put_texture_on_images(t_params *var, int ELEMENT);
void	raycasting_routine(t_params *var, int ELEMENT);

/**
 * @file sprites_routine_convert_sprite_coords.c
 *
 */

void	convert_sprite_coords(t_params *var, SPRITE_DATA *sprite);

/**
 * @file sprites_routine_render_sprites.c
 *
 */

void	render_sprites(t_params *var);

/**
 * @file sprites_routine_tools.c
 *
 */
void	set_sprite_display(t_params *var, int x, int y, bool value);
void	reset_sprite_display(t_params *var);
void	swap_sprite(SPRITE_DATA *a, SPRITE_DATA *b);
int		sprite_difference(SPRITE_DATA a, SPRITE_DATA b);
int		set_frame(SPRITE *sprite);

/**
 * @file sprites_routine.c
 *
 */

void	set_sprites_distance(t_params *var);
void	sort_sprites_by_distance(t_params *var);
void	sprite_routine(t_params *var);

/**
 * @file sprites_tools_check.c
 *
 */

void	check_sprite(char *line, t_params *var, int fd);

/**
 * @file sprites_tools_destroy.c
 *
 */

void	destroy_coin_sprite(t_params *var);
void	destroy_coin_frames(t_params *var);
void	destroy_coin_images(SPRITE **sprite);
void	destroy_sprite(t_params *var, SPRITE **sprite);
void	destroy_sprites(t_params *var);

/**
 * @file sprites_tools_parsing_path.c
 *
 */

char	*build_path(char *path, int i);
void	parsing_sprites(char *file, t_params *var);

/**
 * @file sprites.c
 *
 */

void	free_images_local(t_params *var, SPRITE **sprite, int max);
void	init_sprite(t_params *var, SPRITE **sprite, int frame, char *path);

/**
 * @file zbuffers.c
 *
 */

void	free_zdoor(t_params *var);
double	*init_zbuffer(t_params *var, double *buffer);
void	free_zbuffer(t_params *var);
void	reset_zbuffer(t_params *var, double *buffer);
void	debug_z(double *buffer, t_params *var);

/**
 * @file handle_colors.c
 *
 */

int		get_darker_color(int c, t_params *var, int *j);
int		get_lighter_color(int c, t_params *var, int *j);

bool	is_map_valid(t_params *var);

#endif
