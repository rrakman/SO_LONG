/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:12:56 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/18 09:39:27 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

void	init_images(t_game *game)
{
	int	x;
	int	y;

	game->w = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &x, &y);
	game->f = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &x, &y);
	game->coll = mlx_xpm_file_to_image(game->mlx, "./flower.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &x, &y);
	game->pl = mlx_xpm_file_to_image(game->mlx, "./player.xpm", &x, &y);
}

void	ft_norm(t_game *game, int i, int j)
{
	int		x;
	int		y;
	char	ch;

	while (j < ft_strlen(game->map[i]))
	{
		x = j * 50;
		y = i * 50;
		ch = game->map[i][j];
		if (ch == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->coll, x, y);
		else if (ch == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
		else if (ch == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->pl, x, y);
		j++;
	}
}

void	put_wffpe(t_game *game)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	ch;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < ft_strlen(game->map_cpy[i]))
		{
			x = j * 50;
			y = i * 50;
			ch = game->map_cpy[i][j];
			if (ch == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->w, x, y);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->f, x, y);
			j++;
		}
		j = 0;
		ft_norm(game, i, j);
		i++;
	}
}
