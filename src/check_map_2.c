/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:59:45 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/27 09:59:50 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	copy[i] = NULL;
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!(copy[i]))
			return (NULL);
		i++;
	}
	return (copy);
}

int	is_fillable(char c)
{
	if (c == '1' || c == 'X')
		return (0);
	return (1);
}

void	set_next_point(int next[2], int a, int b)
{
	next[0] = a;
	next[1] = b;
}

void	flood_fill(char **map, int *size, int *begin)
{
	int	next_point[2];

	map[begin[0]][begin[1]] = 'X';
	if (begin[0] > 0 && is_fillable(map[begin[0] - 1][begin[1]]))
	{
		set_next_point(next_point, begin[0] - 1, begin[1]);
		flood_fill(map, size, next_point);
	}
	if ((begin[0] < (size[0] - 1)) && is_fillable(map[begin[0] + 1][begin[1]]))
	{
		set_next_point(next_point, begin[0] + 1, begin[1]);
		flood_fill(map, size, next_point);
	}
	if (begin[1] > 0 && is_fillable(map[begin[0]][begin[1] - 1]))
	{
		set_next_point(next_point, begin[0], begin[1] - 1);
		flood_fill(map, size, next_point);
	}
	if ((begin[1] < (size[1] - 1)) && is_fillable(map[begin[0]][begin[1] + 1]))
	{
		set_next_point(next_point, begin[0], begin[1] + 1);
		flood_fill(map, size, next_point);
	}
}

int	check_path(char **map)
{
	char	**copy;
	int		size[2];
	int		begin[2];
	int		return_value;

	return_value = 1;
	copy = copy_map(map);
	if (!copy)
		return (0);
	get_map_size(map, size);
	get_start_position(map, begin);
	flood_fill(copy, size, begin);
	if (count_elements(copy, 'P') != 0)
		return_value = 0;
	if (count_elements(copy, 'E') != 0)
		return_value = 0;
	if (count_elements(copy, 'C') != 0)
		return_value = 0;
	free_map(copy);
	return (return_value);
}
