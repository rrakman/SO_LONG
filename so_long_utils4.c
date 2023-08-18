/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:30:14 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/18 06:36:09 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_action(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		move_p_rorl(game, 'l');
	if (keycode == KEY_D)
		move_p_rorl(game, 'r');
	if (keycode == KEY_S)
		move_p_doru(game, 'd');
	if (keycode == KEY_W)
		move_p_doru(game, 'u');
	if (keycode == KEY_ESC)
	{
		printf("ESC\n");
		exit(0);
	}
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	init_game(t_game *game)
{
	int	s_width;
	int	s_height;

	s_height = game->map_h * 50;
	s_width = (ft_strlen(game->map_cpy[0]) - 1) * 50;
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, s_width, s_height, "so_long");
	put_wffpe(game);
	mlx_hook(game->win, 2, 0, key_action, game);
	mlx_hook(game->win, 17, 0, close_window, game);
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
