/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:06 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 16:28:01 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	**copy_map(int **map, int height, int width)
{
	int	**new_map;
	int	i;

	i = 0;
	new_map = (int **)malloc(height * sizeof(int *));
	if (!new_map)
		return (NULL);
	while (i < height)
	{
		new_map[i] = (int *)malloc(width * sizeof(int));
		ft_memcpy(new_map[i], map[i], width * sizeof(int));
		i++;
	}
	return (new_map);
}

void	free_map(int **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	replace_map_data(t_params *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map_height)
	{
		while (j < var->map_width)
		{
			if (var->world_map[i][j] == 5)
				var->world_map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_valid_char(t_params *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map_height)
	{
		j = 0;
		while (j < var->map_width)
		{
			if (var->world_map[i][j] == -1)
				msg_and_exit(var, "The map must contain valid characters", i,
					j);
			j++;
		}
		i++;
	}
}
