/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:49:53 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/20 13:49:55 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	if (line)
		free(line);
	close(fd);
	return (count);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*remove_ln(char *str)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(str) - 1;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	free(str);
	return (result);
}

char	**parse_map(char *file)
{
	char	**map;
	char	*line;
	int		number_of_lines;
	int		fd;
	int		i;

	number_of_lines = count_lines(file);
	ft_printf("%i lignes !\n", number_of_lines);
	fd = open(file, O_RDONLY);
	if (fd < 0 || number_of_lines == 0)
		return (NULL);
	map = (char **)malloc((number_of_lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = remove_ln(line);
	}
	close(fd);
	map[i] = 0;
	return (map);
}
