/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:26 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/17 00:28:37 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_w - 1)
	{
		if (game->map[0][i] != '1')
			error("Error\nMap is not closed\n");
		if (game->map[game->map_h - 1][i] != '1')
			error("Error\nMap is not closed\n");
		i++;
	}
	i = 0;
	while (i < game->map_h)
	{
		if (game->map[i][0] != '1')
			error("Error\nMap is not closed\n");
		if (game->map[i][game->map_w - 2] != '1')
			error("Error\nMap is not closed\n");
		i++;
	}
}

void	map_len_check(t_game *game)
{
	int	i;
	int	j;

	j = ft_strlen(game->map[game->map_h - 1]) + 1;
	i = 0;
	while (i < game->map_h - 1)
	{
		if (ft_strlen(game->map[i]) != j)
			error("Error\nMap isn't rectangular\n");
		i++;
	}
}

void	map_cpy(t_game *game)
{
	int	i;
	
	i = 0;
	game->map_cpy = (char **)malloc(sizeof(char *) * game->map_h);
	while (i < game->map_h)
	{
		game->map_cpy[i] = ft_strdup(game->map[i]);	
		i++;
	}
}

void	print_map_2d(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_h)
	{
		printf("%s", game->map_cpy[i]);
		i++;
	}
}