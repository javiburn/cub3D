/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/28 15:23:51 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	ft_handle_was(enum e_keys key, t_game *game)
{
	if (key == W || key == UP)
	{
		game->player.old_x = game->player.x;
		game->player.old_y = game->player.y;
		game->player.x -= game->player.dx;
		game->player.y -= game->player.dy;
	}
	else if (key == A)
	{
		game->player.old_x = game->player.x;
		game->player.old_y = game->player.y;
		game->player.x -= game->player.dy;
		game->player.y -= game->player.dx;
	}
	else if (key == S || key == DOWN)
	{
		game->player.old_x = game->player.x;
		game->player.old_y = game->player.y;
		game->player.x += game->player.dx;
		game->player.y += game->player.dy;
	}
}

static void	ft_handle_arrows_and_d(enum e_keys key, t_game *game)
{
	if (key == D)
	{
		game->player.old_x = game->player.x;
		game->player.old_y = game->player.y;
		game->player.x += game->player.dy;
		game->player.y += game->player.dx;
	}
	else if (key == LEFT)
	{
		game->player.direction -= 0.1;
		if (game->player.direction < 0)
			game->player.direction += 2 * M_PI;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
	else if (key == RIGHT)
	{
		game->player.direction += 0.1;
		if (game->player.direction > 2 * M_PI)
			game->player.direction -= 2 * M_PI;
		game->player.dx = cos(game->player.direction) * 5;
		game->player.dy = sin(game->player.direction) * 5;
	}
}

/**
 * Check what key was pressed and move the player accordingly, the draw the
 * screen to update the player's view.
*/
int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	ft_handle_was(key, game);
	ft_handle_arrows_and_d(key, game);
	draw_screen(game);
	return (0);
}
