/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/25 15:22:31 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	else if (key == W)
	{
		game->player.x += game->player.dx;
		game->player.y += game->player.dy;
	}
	else if (key == A)
		game->player.y -= 1;
	else if (key == S)
	{
		game->player.x -= game->player.dx;
		game->player.y -= game->player.dy;
	}
	else if (key == D)
		game->player.y += 1;
	else if (key == LEFT)
	{
		game->player.direction -= 0.1;
		if (game->player.direction < 0)
			game->player.direction += 2 * M_PI;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	else if (key == RIGHT)
	{
		game->player.direction += 0.1;
		if (game->player.direction > 2 * M_PI)
			game->player.direction -= 2 * M_PI;
		game->player.dx = cos(game->player.direction);
		game->player.dy = sin(game->player.direction);
	}
	re_draw_screen(game);
	return (0);
}
