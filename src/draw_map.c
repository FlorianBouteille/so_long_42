/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:19:02 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/20 15:19:03 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	what_to_draw(t_context context, int *coord)
{
	int	i;
	int	j;

	i = coord[1];
	j = coord[0];
	if (context.map[i][j] == '1')
		return (context.wall_sprite);
	else if (context.map[i][j] == '0')
		return (context.space_sprite);
	else if (context.map[i][j] == 'P')
		return (context.player_sprite);
	else if (context.map[i][j] == 'C')
		return (context.coin_sprite);
	else if (context.map[i][j] == 'E')
		return (context.exit_sprite);
	return (context.wall_sprite);
}

int	get_sizex(char **map, int map_width)
{
	int	nb_of_columns;

	nb_of_columns = ft_strlen(map[0]);
	return (map_width / nb_of_columns);
}

int	get_sizey(char **map, int map_height)
{
	int	nb_of_rows;

	nb_of_rows = 0;
	while (map[nb_of_rows])
		nb_of_rows++;
	return (map_height / nb_of_rows);
}

void	draw_map(t_context *context)
{
	int		i;
	int		j;
	int		coordinates[2];
	t_data	sprite;

	i = 0;
	while (context->map[i])
	{
		j = 0;
		coordinates[1] = i;
		while (context->map[i][j])
		{
			coordinates[0] = j;
			sprite = what_to_draw(*context, coordinates);
			mlx_put_image_to_window(context->mlx, context->window,
				sprite.img,
				coordinates[0] * 64,
				coordinates[1] * 64);
			j++;
		}
		i++;
	}
}
