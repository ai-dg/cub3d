/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools_parsing_path.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:24:19 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 23:26:45 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

char	*build_path(char *path, int i)
{
	char	*index;
	char	*new_path;

	index = ft_itoa(i + 1);
	new_path = ft_fstrjoin(path, index, SECOND);
	new_path = ft_fstrjoin(new_path, ".xpm", FIRST);
	return (new_path);
}

void	parsing_sprites(char *file, t_params *var)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	handle_fd_error(var, fd, "Error - fail to open map file");
	line = get_next_line(fd);
	ft_unallocated_trim(line);
	while (line)
	{
		if (strncmp(line, "SPRITE", 6) == 0)
			check_sprite(line, var, fd);
		free(line);
		line = get_next_line(fd);
		ft_unallocated_trim(line);
	}
	close(fd);
}
