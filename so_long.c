/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:43:59 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/18 06:51:20 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	args_check(int ac, char **av, t_game *game)
{
	if (ac != 2)
		error("Error\nInvalid number of arguments\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		error("Error\nInvalid file extension\n");
	game->map_name = ft_strdup(av[1]);
}

void	map_read_2(t_game *game)
{
	int	i;

	game->map = malloc(sizeof(char *) * (game->map_h + 1));
	if (!game->map)
		error("Error\nMemory allocation failed\n");
	game->map_fd = open(game->map_name, O_RDONLY);
	if (game->map_fd == -1)
		error("Error\nInvalid file\n");
	i = 0;
	while (1)
	{
		game->map[i] = get_next_line(game->map_fd);
		if (!game->map[i])
			break ;
		i++;
	}
	game->map_w = ft_strlen(game->map[0]);
	close(game->map_fd);
	map_check_borders(game);
	map_len_check(game);
	map_check_pec(game);
	map_cpy(game);
	get_cords(game);
	valid_path(game, game->px, game->py);
	map_p_check(game);
}

void	map_read(t_game *game)
{
	char	*line;
	int		i;

	game->map_h = 0;
	game->map_w = 0;
	game->map_fd = open(game->map_name, O_RDONLY);
	if (game->map_fd == -1)
		error("Error\nInvalid file\n");
	while (1)
	{
		line = get_next_line(game->map_fd);
		if (!line)
			break ;
		if (line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			error("Error\nMap has an extra newline\n");
		}
		game->map_h++;
		free(line);
	}
	close(game->map_fd);
	if (game->map_h == 0)
		error("Error\nEmpty file\n");
	map_read_2(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	args_check(ac, av, &game);
	map_read(&game);
	init_game(&game);
	ft_free(game.map);
	ft_free(game.map_cpy);
}
