/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:39:17 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/30 16:39:19 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../shared_libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_context
{
	void	*mlx;
	void	*window;
	char	**map;
	t_data	wall_sprite;
	t_data	player_sprite;
	t_data	coin_sprite;
	t_data	exit_sprite;
	t_data	space_sprite;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		nb_of_moves;
	int		coins;
}	t_context;

int		init_context(t_context *context, char *file);
int		find_player(char **map, char pos);
void	win(t_context *context);
int		count_lines(char *file);
char	**parse_map(char *file);
void	print_map(char **map);
void	color_full_image(t_data image, int width, int height, int color);
t_data	make_image(void *mlx, int width, int height);
int		get_map_height(char **map);
int		check_map(char **map);
int		valid_extension(char *file);
int		is_walled(char **map, int number_of_lines);
int		is_rectangle(char **map);
t_data	what_to_draw(t_context context, int *coord);
t_data	draw_wall(void *mlx, void *window, int *coordinates, int *size);
t_data	draw_space(void *mlx, void *window, int *coordinates, int *size);
t_data	draw_player(void *mlx, void *window, int *coordinates, int *size);
t_data	draw_coin(void *mlx, void *window, int *coordinates, int *size);
t_data	draw_exit(void *mlx, void *window, int *coordinates, int *size);
int		get_sizex(char **map, int map_width);
int		get_sizey(char **map, int map_height);
void	draw_map(t_context *context);
void	free_map(char **tab);
void	print_map(char **map);
int		check_path(char **map);
int		count_elements(char **map, char c);
void	flood_fill(char **map, int *size, int *begin);
char	**copy_map(char **map);
char	**replace_exit(char **map);
int		valid_exit(char **map);
void	get_map_size(char **map, int *size);
void	get_start_position(char **map, int *begin);
int		handle_keypress(int keycode, t_context *context);
void	move_player(t_context *context, int delta_y, int delta_x);
t_data	load_sprite(void *mlx, char *filename);
void	replace_old_pos(t_context *context, int x, int y);
void	go_new_pos(t_context *context, int new_x, int new_y);
void	free_sprites(t_context *context);
int		free_and_exit(t_context *context, int mode);
int		free_and_exit_all(t_context *context);

#endif
