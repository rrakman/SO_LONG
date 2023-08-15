/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:43:47 by =           #+#    #+#             */
/*   Updated: 2023/08/15 00:10:17 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_read(int fd, char *everything);
char	*g_line(char *s);
char	*delline(char *line, char *everything);
char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strdup(char *s1);
char	*send_join(char *s1, char *s2);
void	error(char *str);

typedef struct game
{
	void	*mlx;
	void	*win;
	char	*map_name;
	char	**map;
	char 	**map_cpy;
	int		map_fd;
	int		map_w;
	int		map_h;
	int		p;	
	int		e;
	int		c;	
	int		px;
	int		py;
	int		ex;
	int		ey;
	void	*img;
}	t_game;

void	args_check(int ac, char **av, t_game *game);
void	init_game(t_game *game);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	map_read(t_game *game);
void	map_check_borders(t_game *game);
void	map_len_check(t_game *game);
void	map_check_pec(t_game *game);
void	map_cpy(t_game *game);
void	print_map_2d(t_game *game);
void	get_cords(t_game *game);
void	valid_path(t_game *game);

#endif