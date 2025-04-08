/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:53:07 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/20 14:53:11 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	i;
	int	len;

	if (!map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_walled(char **map, int number_of_lines)
{
	int	i;
	int	last_column;

	i = 0;
	last_column = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last_column] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[number_of_lines - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_caracters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P')
			{
				if (map[i][j] != 'C' && map[i][j] != 'E')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	check_map(char **map)
{
	if (!map)
		return (ft_printf("Error\nMap is NULL\n"), 0);
	if (get_map_height(map) < 3)
		return (ft_printf("Error\nMap is too small to play\n"), 0);
	if (!check_caracters(map))
		return (ft_printf("Error\nMap contains invalid caracters\n"), 0);
	if (!is_rectangle(map))
		return (ft_printf("Error\nMap is not a rectangle !\n"), 0);
	if (!is_walled(map, get_map_height(map)))
		return (ft_printf("Error\nMap is not properly walled !\n"), 0);
	if (count_elements(map, 'P') != 1)
		return (ft_printf("Error\nStarting position is not 1 !\n"), 0);
	if (count_elements(map, 'E') != 1)
		return (ft_printf("Error\nNumber of exits is not 1 !\n"), 0);
	if (count_elements(map, 'C') < 1)
		return (ft_printf("Error\nNeeds at least 1 collectible !\n"), 0);
	if (!valid_exit(map))
		return (ft_printf("Error\nNo valid path found !\n"), 0);
	if (!check_path(map))
		return (ft_printf("Error\nNo valid path found !\n"), 0);
	return (1);
}
