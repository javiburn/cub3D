/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:52:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/02 17:50:14 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_player	get_player_direction(t_game *game)
{
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'N')
	{
		game->player.direction = 1.570796325;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'E')
	{
		game->player.direction = 6.2831853;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'W')
	{
		game->player.direction = 3.14159265;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	if (game->map_data.map[(int)game->player.y / WALL_SIZE][(int)game->player.x / WALL_SIZE] == 'S')
	{
		game->player.direction = 4.712388975;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	return (game->player);
}

void	start_game(t_game *game)
{
	game->player = get_player_direction(game);
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	minimap(game, game->map_data.map);
}
