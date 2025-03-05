/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:23:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:26:37 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	check_colors(int c)
{
	if (c < 0 || c > 255)
		return (-1);
	return (0);
}

char	**handle_spaces(char **splitted)
{
	char	**alt_splitted;
	char	*joined;
	int		i;

	i = 0;
	alt_splitted = splitted;
	alt_splitted++;
	if (ft_count_args(splitted) == 2)
		return (splitted);
	if (ft_count_args(splitted) > 2)
	{
		joined = ft_join_splitted(alt_splitted, " ");
		while (alt_splitted[i])
		{
			free(alt_splitted[i]);
			alt_splitted[i] = NULL;
			i++;
		}
		splitted[1] = joined;
	}
	return (splitted);
}

int	set_rgb_from_line(char *line, t_params *var)
{
	char	**splitted;
	char	**rgb;
	int		i;

	i = -1;
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (-1);
	splitted = handle_spaces(splitted);
	rgb = ft_split(splitted[1], ',');
	if (!rgb)
		return (free_array(&splitted), -1);
	if (ft_count_args(rgb) != 3)
		return (free_array(&splitted), free_array(&rgb), -4);
	while (rgb[++i])
	{
		if (check_colors(ft_atoi(rgb[i])) == -1)
			return (free_array(&splitted), free_array(&rgb), -2);
		if (line[0] == 'C')
			var->graphics->ceil_color[i] = (short)ft_atoi(rgb[i]);
		if (line[0] == 'F')
			var->graphics->floor_color[i] = (short)ft_atoi(rgb[i]);
	}
	return (free_array(&splitted), free_array(&rgb), 0);
}

int	get_color_from_array(short *color_array)
{
	return ((255 << 24) + (color_array[0] << 16) + (color_array[1] << 8)
		+ color_array[2]);
}

void	set_color_from_rbg(t_graphics *graphics)
{
	graphics->ceil_color_temp = get_color_from_array(graphics->ceil_color);
	graphics->floor_color_temp = get_color_from_array(graphics->floor_color);
}
