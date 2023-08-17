/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:44:08 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/17 08:54:50 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}

int ft_strlen2d(char **str)
{
	int counter;
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

void print_map(t_game *game)
{
	int idx;
	int idx2;

	idx =0 ;
	while (game->map[idx])
	{
		idx2 = 0;
		while (game->map[idx][idx2])
		{
			printf("%c", game->map[idx][idx2]);
			idx2++;
		}
		idx++;
	}
	printf("\n");
}

void init_images(t_game *game)
{
	int x;
	int y;
	game->wall = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./flower.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "./player.xpm", &x, &y);
}

void put_wffpe(t_game *game) {
    int	i;
	int	j;
	char ch;

	i = 0;
    while (i < game->map_h) {
        j = 0;
        while (j < strlen(game->map_cpy[i])) {
            int x = j * 50;
            int y = i * 50;
            char ch = game->map_cpy[i][j];
            
            if (ch == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->floor, x, y);
            
            j++;
        }
        j = 0;
        while (j < strlen(game->map[i]))
		{
            int x = j * 50;
            int y = i * 50;
            ch = game->map[i][j];
            if (ch == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible, x, y);
            else if (ch == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
            else if (ch == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
            
            j++;
        }
        i++;
    }
}

int	key_action(t_game *game, int keycode)
{
	game->moves = 0;
	if (keycode == KEY_A)
	{
		game->moves = 1;
	}
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	init_game(t_game *game)
{
	int screen_width = (strlen(game->map_cpy[0]) - 1) * 50;
	int scree_height = game->map_h* 50 ;
	print_map(game);
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, screen_width, scree_height, "so_long");
	put_wffpe(game);
	mlx_hook(game->win, 2, 0, key_action, game);
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
