/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:04:04 by rrakman           #+#    #+#             */
/*   Updated: 2023/08/15 22:43:48 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_cords(t_game *game)
{
    int i;
    int j;
    
    game->px = 0;
    game->py = 0;
    i = 0;
    while (i < game->map_h)
    {
        j = 0;
        while (j < game->map_w)
        {
            if (game->map_cpy[i][j] == 'P')
            {
                game->px = j;
                game->py = i;
            }
            else if (game->map_cpy[i][j] == 'E')
            {
                game->ex = j;
                game->ey = i;
            }
            j++;
        }
        i++;
    }
}
