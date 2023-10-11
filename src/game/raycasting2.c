/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:42:16 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 10:10:09 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	dda_algorithm2(t_game *game)
{
	game->camera.hit = 0;
	while (game->camera.hit == 0)
	{
		printf("aver: %d %d\n", game->camera.grid_x, game->camera.grid_y);
		if (game->camera.sidedx < game->camera.sidedy)
		{
			game->camera.sidedx += game->camera.dx;
			game->camera.grid_x += game->camera.stepx;
			game->camera.offset = 0;
		}
		else
		{
			game->camera.sidedy += game->camera.dy;
			game->camera.grid_y += game->camera.stepy;
			game->camera.offset = 1;
		}
		if (game->map_data.map[game->camera.grid_y][game->camera.grid_x]
			== '1')
			game->camera.hit = 1;
	}
}

void	check_ray_direction2(t_game *game)
{
	printf("eeee: %f %f\n", game->camera.raydirx, game->camera.raydiry);
	if (game->camera.raydirx < 0)
	{
		game->camera.stepx = -1;
		game->camera.sidedx = ((game->player.x / WALL_SIZE)
				- game->camera.grid_x) * game->camera.dx;
	}
	else
	{
		game->camera.stepx = 1;
		game->camera.sidedx = (game->camera.grid_x + 1
				- (game->player.x / WALL_SIZE)) * game->camera.dx;
	}
	if (game->camera.raydiry < 0)
	{
		game->camera.stepy = -1;
		game->camera.sidedy = ((game->player.y / WALL_SIZE)
				- game->camera.grid_y) * game->camera.dy;
	}
	else
	{
		game->camera.stepy = 1;
		game->camera.sidedy = (game->camera.grid_y + 1
				- (game->player.y / WALL_SIZE)) * game->camera.dy;
	}
}

void	raycasting2(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		game->camera.camerax = (2 * x / (double)SCREEN_WIDTH) - 1;
		game->camera.raydirx = game->camera.directionx
			+ game->camera.plane.x * game->camera.camerax;
		game->camera.raydiry = game->camera.directiony
			+ game->camera.plane.y * game->camera.camerax;
		game->camera.grid_x = game->player.x / WALL_SIZE;
		game->camera.grid_y = game->player.y / WALL_SIZE;
		game->camera.dx = fabs(1 / game->camera.raydirx);
		game->camera.dy = fabs(1 / game->camera.raydiry);
		check_ray_direction2(game);
		dda_algorithm2(game);
		if (game->camera.offset == 0)
			game->camera.distance = game->camera.sidedx - game->camera.dx;
		else
			game->camera.distance = game->camera.sidedy - game->camera.dy;
		ft_draw_wall(game);
		x++;
	}
}
