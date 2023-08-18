/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:08 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/18 06:36:23 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	printf("%s", str);
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
		i++;
	}
}

void	move_p_doru(t_game *game, char c)
{
	if (c == 'u')
	{
		if (game->map[game->py - 1][game->px] == '0')
		{
			game->map[game->py - 1][game->px] = 'P';
			game->map[game->py][game->px] = '0';
			game->py--;
			game->moves++;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n",game->moves);
		}
		else if (game->map[game->py - 1][game->px] == 'C')
		{
			game->map[game->py - 1][game->px] = 'P';
			game->map[game->py][game->px] = '0';
			game->py--;
			game->moves++;
			game->c--;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);	
		}
		else if (game->map[game->py - 1][game->px] == 'E' && game->c == 0)
		{
			printf("You win\n");
			exit(1);
		}
	}
	else if (c == 'd')
	{
		if (game->map[game->py + 1][game->px] == '0')
		{
			game->map[game->py + 1][game->px] = 'P';
			game->map[game->py][game->px] = '0';
			game->py++;
			game->moves++;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}
		else if (game->map[game->py + 1][game->px] == 'C')
		{
			game->map[game->py + 1][game->px] = 'P';
			game->map[game->py][game->px] = '0';
			game->py++;
			game->moves++;
			game->c--;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}
		else if (game->map[game->py + 1][game->px] == 'E' && game->c == 0)
		{
			printf("You win\n");
			exit(1);
		}
	}
}

void	move_p_rorl(t_game *game, char c)
{
	if (c == 'r')
	{
		if (game->map[game->py][game->px + 1] == '0')
		{
			game->map[game->py][game->px + 1] = 'P';
			game->map[game->py][game->px] = '0';
			game->px++;
			game->moves++;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}
		else if (game->map[game->py][game->px + 1] == 'C')
		{
			game->map[game->py][game->px + 1] = 'P';
			game->map[game->py][game->px] = '0';
			game->px++;
			game->moves++;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}
		else if (game->map[game->py][game->px + 1] == 'E' && game->c == 0)
		{
			printf("You win\n");
			exit(1);
		}
	}
	else if (c == 'l')
	{
		if (game->map[game->py][game->px - 1] == '0')
		{
			game->map[game->py][game->px - 1] = 'P';
			game->map[game->py][game->px] = '0';
			game->px--;
			game->moves++;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}
		else if (game->map[game->py][game->px - 1] == 'C')
		{
			game->map[game->py][game->px - 1] = 'P';
			game->map[game->py][game->px] = '0';
			game->px--;
			game->moves++;
			game->c--;
			mlx_clear_window(game->mlx, game->win);
			put_wffpe(game);
			printf("moves = %d\n", game->moves);
		}	
		else if (game->map[game->py][game->px - 1] == 'E' && game->c == 0)
		{
			printf("You win\n");
			exit(1);
		}
	}
}

