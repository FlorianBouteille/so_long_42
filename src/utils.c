/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:28:57 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/27 10:28:58 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	get_map_size(char **map, int *size)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (!is_rectangle(map))
		return ;
	size[0] = i;
	i = 0;
	while (map[0][i])
		i++;
	size[1] = i;
}

void	get_start_position(char **map, int *begin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				begin[0] = i;
				begin[1] = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
