/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:05:14 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	print_world_map(int **world_map, t_params *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map_height)
	{
		if (world_map[i] == NULL)
			break ;
		while (j < var->map_width)
		{
			ft_fprintf(stdout, "%d", world_map[i][j]);
			j++;
		}
		ft_fprintf(stdout, "\n");
		j = 0;
		i++;
	}
}

void	replace_value_in_map(t_params *var, int new, int old)
{
	int		col;
	int		row;
	bool	done;

	done = false;
	col = 0;
	row = 0;
	while (row < var->map_height)
	{
		while (col < var->map_width)
		{
			if (var->world_map[row][col] == old)
			{
				var->world_map[row][col] = new;
				done = true;
				break ;
			}
			col++;
		}
		if (done)
			break ;
		row++;
		col = 0;
	}
}

void	set_value_at_pos(t_params *var, int new, int x, int y)
{
	var->world_map[y][x] = new;
}

bool	allowed_for_map(char *line)
{
	int	i;

	i = 0;
	if (ft_is_single_char(line, ' '))
		return (false);
	if (ft_strlen(line) == 0 || ft_strncmp(line, "\n", 1) == 0)
		return (false);
	while (line[i] != '\n' || line[i] != '\0')
	{
		if (line[i] == '\n' || line[i] == '\0')
			break ;
		if (ft_strncmp("C ", line, 2) == 0 || ft_strncmp("F ", line, 2) == 0
			|| ft_strncmp("NO", line, 2) == 0 || ft_strncmp("SO", line, 2) == 0
			|| ft_strncmp("EA", line, 2) == 0 || ft_strncmp("WE", line, 2) == 0
			|| ft_strncmp("CD", line, 2) == 0 || ft_strncmp("OD", line, 2) == 0
			|| ft_strncmp("SPRITE", line, 6) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_line(char *line)
{
	char	*test_line;

	test_line = ft_strdup(line);
	ft_unallocated_trim(test_line);
	if (allowed_for_map(test_line))
		return (free(test_line), true);
	return (free(test_line), false);
}
