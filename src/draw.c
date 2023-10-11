/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:01:04 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/11 14:47:21 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// ! Bugged function
void	ft_put_pixel(t_img img, int x, int y, t_color rgb)
{
	int		color;

	color = ft_rgba(rgb.red, rgb.green, rgb.blue, 0);
	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
		*(int *)&img.addr[((x * img.bpp) >> 3) + (y * img.line_len)] = color;
}

void	ft_draw_wall(t_game *game)
{
	static int	x = 0;
	int			start;
	int			end;

	game->camera.lineheight = (int)(SCREEN_HEIGHT / game->camera.distance);
	start = -game->camera.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (x == SCREEN_WIDTH)
		x = 0;
	if (start < 0)
		start = 0;
	end = SCREEN_HEIGHT / 2 + game->camera.lineheight / 2;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	while (start < end)
	{
		if (game->camera.offset == 0)
			mlx_pixel_put(game->mlx, game->win, x, start, 0xffffff);
		else
			mlx_pixel_put(game->mlx, game->win, x, start, 0xffafaf);
		start++;
	}
	x++;
}

void	draw_ceiling_floor(t_game *game, t_color ceiling, t_color floor)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < SCREEN_HEIGHT)
	{
		x = -1;
		while (x++ < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
			{
				//ft_put_pixel(game->img, x, y, floor);
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(ceiling.red, ceiling.green, ceiling.blue, 0));
			}
			else
			{
				//ft_put_pixel(game->img, x, y, ceiling);
				mlx_pixel_put(game->mlx, game->win, x, y, ft_rgba(floor.red, floor.green, floor.blue, 0));
			}
		}
	}
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	re_draw_screen(t_game *game)
{
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
	//minimap(game, game->map_data.map);
	raycasting(game);
}
