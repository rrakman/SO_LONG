/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:08 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/14 22:44:09 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 500, 500, "so_long");
	mlx_loop(game->mlx);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	map_check_pec_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->p = 0;
	game->e = 0;
	game->c = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'P')
				game->p++;
			else if (game->map[i][j] == 'E')
				game->e++;
			else if (game->map[i][j] == 'C')
				game->c++;
			j++;
		}
		i++;
	}
	if (game->p != 1 || game->e != 1 || game->c == 0)
		error("Error\nInvalid number of P or E or C\n");
}

void	map_check_pec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == '\0' || game->map[i][j] == '\n')
				j++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0' \
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C' \
					&& game->map[i][j] != 'E')
				error("Error\nInvalid character in map\n");
			j++;
		}
		i++;
	}
	map_check_pec_2(game);
}
