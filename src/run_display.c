/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:00 by jsarabia          #+#    #+#             */
/*   Updated: 2023/10/10 17:05:08 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_graphics(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
}

void	run_game(t_game *game, char *map_name)
{
	char	*aux;

	aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, aux);
	free(aux);
	set_graphics(game);
	start_game(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}
