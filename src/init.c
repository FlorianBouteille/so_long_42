/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:30:03 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/27 14:30:04 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(char **map, char pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (map[i][j] == 'P')
			{
				if (pos == 'x')
					return (j);
				if (pos == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	free_sprites(t_context *context)
{
	if (context->wall_sprite.img)
		mlx_destroy_image(context->mlx, context->wall_sprite.img);
	context->wall_sprite.img = NULL;
	if (context->coin_sprite.img)
		mlx_destroy_image(context->mlx, context->coin_sprite.img);
	context->coin_sprite.img = NULL;
	if (context->space_sprite.img)
		mlx_destroy_image(context->mlx, context->space_sprite.img);
	context->space_sprite.img = NULL;
	if (context->exit_sprite.img)
		mlx_destroy_image(context->mlx, context->exit_sprite.img);
	context->exit_sprite.img = NULL;
	if (context->player_sprite.img)
		mlx_destroy_image(context->mlx, context->player_sprite.img);
	context->player_sprite.img = NULL;
}

int	init_sprites(t_context *context)
{
	context->wall_sprite = load_sprite(context->mlx, "img/wall.xpm");
	if (!(context->wall_sprite.img))
		return (ft_printf("Error\nFailed to load sprite !\n"),
			free_and_exit(context, 1), 0);
	context->coin_sprite = load_sprite(context->mlx, "img/coin.xpm");
	if (!(context->coin_sprite.img))
		return (ft_printf("Error\nFailed to load sprite !\n"),
			free_and_exit(context, 2), 0);
	context->player_sprite = load_sprite(context->mlx, "img/player.xpm");
	if (!(context->player_sprite.img))
		return (ft_printf("Error\nFailed to load sprite !\n"),
			free_and_exit(context, 2), 0);
	context->exit_sprite = load_sprite(context->mlx, "img/exit.xpm");
	if (!(context->exit_sprite.img))
		return (ft_printf("Error\nFailed to load sprite !\n"),
			free_and_exit(context, 2), 0);
	context->space_sprite = load_sprite(context->mlx, "img/space.xpm");
	if (!(context->space_sprite.img))
		return (ft_printf("Error\nFailed to load sprite !"),
			free_and_exit(context, 2), 0);
	return (1);
}

int	init_context(t_context *context, char *file)
{
	context->map = parse_map(file);
	if (!context->map)
		free_and_exit(context, 0);
	context->mlx = mlx_init();
	if (!context->mlx)
		free_and_exit(context, 0);
	context->width = ft_strlen(context->map[0]) * 64;
	context->height = get_map_height(context->map) * 64;
	context->player_x = find_player(context->map, 'x');
	context->player_y = find_player(context->map, 'y');
	context->nb_of_moves = 0;
	context->wall_sprite.img = NULL;
	context->coin_sprite.img = NULL;
	context->space_sprite.img = NULL;
	context->exit_sprite.img = NULL;
	context->player_sprite.img = NULL;
	init_sprites(context);
	context->coins = count_elements(context->map, 'C');
	context->window = mlx_new_window(context->mlx,
			context->width,
			context->height,
			"let's play !");
	return (1);
}
