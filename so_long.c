#include "so_long.h"

void	args_check(int ac, char **av, t_game *game)
{
	if (ac != 2)
		error("Error\nInvalid number of arguments\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		error("Error\nInvalid file extension\n");
	game->map_name = ft_strdup(av[1]);
}
int flood_fill


void	valid_map(t_game *game)
{
	if(!flood_fill(game))
		error("Error\nInvalid map\n");
}

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
	ft_free(game->map);
	valid_map(game);
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
	map_read_2(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	args_check(ac, av, &game);
	map_read(&game);
	init_game(&game);
	int width = 500;
	int height = 500;

	game.img = mlx_xpm_file_to_image(game.mlx, "1.xpm",&width, &height);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);

}
