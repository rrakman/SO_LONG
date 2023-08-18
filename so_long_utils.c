/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:08 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/18 09:38:56 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	put_wffpe(game);
	ft_printf("moves = %d\n", game->moves);
}

void	move_up(t_game *game)
{
	if (game->map[game->py - 1][game->px] == '0')
	{
		game->map[game->py - 1][game->px] = 'P';
		game->map[game->py][game->px] = '0';
		game->py--;
		game->moves++;
		update_game(game);
	}
	else if (game->map[game->py - 1][game->px] == 'C')
	{
		game->map[game->py - 1][game->px] = 'P';
		game->map[game->py][game->px] = '0';
		game->py--;
		game->moves++;
		game->c--;
		update_game(game);
	}
	else if (game->map[game->py - 1][game->px] == 'E' && game->c == 0)
	{
		ft_printf("You win\n");
		exit(1);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->py + 1][game->px] == '0')
	{
		game->map[game->py + 1][game->px] = 'P';
		game->map[game->py][game->px] = '0';
		game->py++;
		game->moves++;
		update_game(game);
	}
	else if (game->map[game->py + 1][game->px] == 'C')
	{
		game->map[game->py + 1][game->px] = 'P';
		game->map[game->py][game->px] = '0';
		game->py++;
		game->moves++;
		game->c--;
		update_game(game);
	}
	else if (game->map[game->py + 1][game->px] == 'E' && game->c == 0)
	{
		ft_printf("You win\n");
		exit(1);
	}
}

void	move_r(t_game *game)
{
	if (game->map[game->py][game->px + 1] == '0')
	{
		game->map[game->py][game->px + 1] = 'P';
		game->map[game->py][game->px] = '0';
		game->px++;
		game->moves++;
		update_game(game);
	}
	else if (game->map[game->py][game->px + 1] == 'C')
	{
		game->map[game->py][game->px + 1] = 'P';
		game->map[game->py][game->px] = '0';
		game->px++;
		game->moves++;
		game->c--;
		update_game(game);
	}
	else if (game->map[game->py][game->px + 1] == 'E' && game->c == 0)
	{
		ft_printf("You win\n");
		exit(1);
	}
}

void	move_l(t_game *game)
{
	if (game->map[game->py][game->px - 1] == '0')
	{
		game->map[game->py][game->px - 1] = 'P';
		game->map[game->py][game->px] = '0';
		game->px--;
		game->moves++;
		update_game(game);
	}
	else if (game->map[game->py][game->px - 1] == 'C')
	{
		game->map[game->py][game->px - 1] = 'P';
		game->map[game->py][game->px] = '0';
		game->px--;
		game->moves++;
		game->c--;
		update_game(game);
	}	
	else if (game->map[game->py][game->px - 1] == 'E' && game->c == 0)
	{
		ft_printf("You win\n");
		exit(1);
	}
}
