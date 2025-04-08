/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:50:01 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/20 14:50:03 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	load_sprite(void *mlx, char *filename)
{
	t_data	sprite;

	sprite.img = mlx_xpm_file_to_image(mlx, filename,
			&sprite.width,
			&sprite.height);
	if (!sprite.img)
	{
		sprite.width = 0;
		sprite.height = 0;
		sprite.addr = NULL;
		sprite.bits_per_pixel = 0;
		sprite.line_length = 0;
		sprite.endian = 0;
	}
	else
	{
		sprite.addr = mlx_get_data_addr(sprite.img,
				&sprite.bits_per_pixel,
				&sprite.line_length,
				&sprite.endian);
	}
	return (sprite);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_full_image(t_data image, int width, int height, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		while (j < height)
		{
			my_mlx_pixel_put(&image, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

t_data	make_image(void *mlx, int width, int height)
{
	t_data	n;

	n.img = mlx_new_image(mlx, width, height);
	n.addr = mlx_get_data_addr(n.img,
			&n.bits_per_pixel,
			&n.line_length,
			&n.endian);
	return (n);
}
