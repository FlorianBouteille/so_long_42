/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:55:19 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/27 16:55:21 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_context *context)
{
	if (keycode == 119 || keycode == 65362)
		move_player(context, -1, 0);
	if (keycode == 115 || keycode == 65364)
		move_player(context, 1, 0);
	if (keycode == 97 || keycode == 65361)
		move_player(context, 0, -1);
	if (keycode == 100 || keycode == 65363)
		move_player(context, 0, 1);
	if (keycode == 65307)
		free_and_exit(context, 3);
	return (0);
}

void	move_player(t_context *context, int delta_y, int delta_x)
{
	int	x;
	int	y;

	x = context->player_x;
	y = context->player_y;
	if (context->map[y + delta_y][x + delta_x] == '1')
		return ;
	if (context->map[y + delta_y][x + delta_x] == 'C')
		context->coins -= 1;
	if (context->map[y + delta_y][x + delta_x] == 'E')
	{
		if (context->coins == 0)
			win(context);
		else
			return ;
	}
	replace_old_pos(context, x, y);
	go_new_pos(context, x + delta_x, y + delta_y);
	context->player_x += delta_x;
	context->player_y += delta_y;
	context->nb_of_moves += 1;
	ft_printf("%i moves\n", context->nb_of_moves);
}

void	win(t_context *context)
{
	context->nb_of_moves += 1;
	ft_printf("You won in %i moves !\n", context->nb_of_moves);
	ft_printf("You're the Meilleur Dresseur !\n");
	free_and_exit(context, 3);
}

int	free_and_exit(t_context *context, int mode)
{
	if (mode >= 0 && context->map != NULL)
		free_map(context->map);
	if (mode >= 2)
		free_sprites(context);
	if (mode >= 3)
		mlx_destroy_window(context->mlx, context->window);
	if (mode >= 1)
	{
		mlx_destroy_display(context->mlx);
		free(context->mlx);
	}
	exit (0);
	return (0);
}

int	free_and_exit_all(t_context *context)
{
	free_map(context->map);
	free_sprites(context);
	mlx_destroy_window(context->mlx, context->window);
	mlx_destroy_display(context->mlx);
	free(context->mlx);
	exit (0);
	return (0);
}
