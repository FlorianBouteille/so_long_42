/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:52:33 by fbouteil          #+#    #+#             */
/*   Updated: 2025/03/05 10:52:35 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**replace_exit(char **map)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = copy_map(map);
	if (!copy)
		return (NULL);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{	
			if (copy[i][j] == 'E')
				copy[i][j] = '1';
			j++;
		}
		i++;
	}
	return (copy);
}

int	valid_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'r' && file[len - 2] == 'e' && file[len - 3] == 'b'
		&& file[len - 4] == '.')
		return (1);
	return (0);
}

int	valid_exit(char **map)
{
	char	**copy_no_exit;
	int		size[2];
	int		begin[2];
	int		return_value;

	return_value = 1;
	copy_no_exit = replace_exit(map);
	if (!copy_no_exit)
		return (0);
	get_map_size(map, size);
	get_start_position(map, begin);
	flood_fill(copy_no_exit, size, begin);
	if (count_elements(copy_no_exit, 'P') != 0)
		return_value = 0;
	if (count_elements(copy_no_exit, 'C') != 0)
		return_value = 0;
	free_map(copy_no_exit);
	return (return_value);
}
