/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:24:19 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:25:29 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	free_images_local(t_params *var, SPRITE **sprite, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		mlx_destroy_image(var->mlx, (*sprite)->frames[i].img);
		i++;
	}
}

static void	initialize_sprite(t_params *var, SPRITE **sprite, int frame)
{
	(*sprite)->frame = frame;
	(*sprite)->count = 0;
	(*sprite)->frame_pos = 0;
	(*sprite)->frames = malloc((frame + 1) * sizeof(t_image));
	if (!(*sprite)->frames)
	{
		free(*sprite);
		exit_on_error(var, "Fail on memory allocation");
	}
	ft_bzero((*sprite)->frames, (frame + 1) * sizeof(t_image));
}

static void	load_single_frame(t_params *var, SPRITE **sprite, int i, char *path)
{
	(*sprite)->frames[i].img = mlx_xpm_file_to_image(var->mlx, path,
			&(*sprite)->frames[i].width, &(*sprite)->frames[i].height);
	if (!(*sprite)->frames[i].img)
	{
		if (i > 0)
			free_images_local(var, sprite, i);
		free((*sprite)->frames);
		free(*sprite);
		exit_on_error(var, "Fail on image initialisation");
	}
	(*sprite)->frames[i].addr = (int *)mlx_get_data_addr(
			(*sprite)->frames[i].img,
			&(*sprite)->frames[i].bits_per_pixel,
			&(*sprite)->frames[i].line_length, &(*sprite)->frames[i].endian);
}

static void	load_sprite_frames(t_params *var, SPRITE **sprite, int frame,
		char *path)
{
	int		i;
	char	*new_path;

	i = 0;
	while (i < frame)
	{
		new_path = build_path(path, i);
		if (!new_path)
		{
			free((*sprite)->frames);
			free(*sprite);
			exit_on_error(var, "Fail on memory allocation");
		}
		load_single_frame(var, sprite, i, new_path);
		free_variable((void **)&new_path);
		i++;
	}
}

void	init_sprite(t_params *var, SPRITE **sprite, int frame, char *path)
{
	*sprite = malloc(sizeof(SPRITE));
	if (!*sprite)
		exit_on_error(var, "Fail on memory allocation");
	initialize_sprite(var, sprite, frame);
	load_sprite_frames(var, sprite, frame, path);
}
