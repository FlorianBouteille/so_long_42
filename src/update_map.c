/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:22:04 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/27 14:22:07 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_old_pos(t_context *context, int x, int y)
{
	int		coordinates[2];
	t_data	sprite;

	context->map[y][x] = '0';
	coordinates[0] = x;
	coordinates[1] = y;
	sprite = what_to_draw(*context, coordinates);
	mlx_put_image_to_window(context->mlx, context->window,
		sprite.img, coordinates[0] * 64, coordinates[1] * 64);
}

void	go_new_pos(t_context *context, int new_x, int new_y)
{
	int		coordinates[2];
	t_data	sprite;

	context->map[new_y][new_x] = 'P';
	coordinates[0] = new_x;
	coordinates[1] = new_y;
	sprite = what_to_draw(*context, coordinates);
	mlx_put_image_to_window(context->mlx, context->window,
		sprite.img,
		coordinates[0] * 64, coordinates[1] * 64);
}
