/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:49:06 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/19 02:55:56 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_ec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_cpy[i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_path(t_game *game, int x, int y)
{
	if (x >= game->map_w || x < 0 || y >= game->map_h || y < 0)
		return ;
	if (game->map_cpy[y][x] == '1')
		return ;
	if (game->map_cpy[y][x] != 'X')
	{
		game->map_cpy[y][x] = 'X';
		valid_path(game, x, y + 1);
		valid_path(game, x - 1, y);
		valid_path(game, x, y - 1);
		valid_path(game, x + 1, y);
		if (check_ec(game) == 1)
			return ;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
