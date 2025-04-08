/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:42:22 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/30 16:42:24 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initial_checks(char *file)
{
	char	**map;

	if (!valid_extension(file))
		return (ft_printf("Error\nWrong file extension\n"), 0);
	map = parse_map(file);
	if (!map)
		return (ft_printf("Error\nFailed to parse the map !\n"), 0);
	if (!check_map(map))
		return (free_map(map), 0);
	free_map(map);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_context	context;

	if (argc != 2)
		return (ft_printf("Program takes 1 parameter : the map\n"), 1);
	if (!initial_checks(argv[1]))
		return (1);
	if (!init_context(&context, argv[1]))
		return (1);
	draw_map(&context);
	mlx_key_hook(context.window, handle_keypress, &context);
	mlx_hook(context.window, 17, 0, free_and_exit_all, &context);
	mlx_loop(context.mlx);
	return (0);
}
