/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:50:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/28 15:11:41 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "structs.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define PROGRAM_NAME "cub3d - "
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define WALL_SIZE 20
# define PLAYER_SIZE WALL_SIZE / 3
# define PI 3.14159265

/* Enum */

enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53
};

/**
 * Representing the type of value is found in the file line.
 * If no type if found, ERROR is returned
*/
enum e_values
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
};

/* Functions */

int		map_width(char **map);
int		exit_game(t_game *game);
char	**read_file(char **argv);
void	raise_error(char *message);
void	check_config(t_game *game);
void	check_weird_char(t_game *game);
void	parsing(char **argv, t_game *game);
void	run_game(t_game *game, char *map_name);
int		ft_rgba(int r, int g, int b, int alpha);
void	get_values(t_game *game, char **file_con);
int		event_handler(enum e_keys key, t_game *game);
void	draw_ceiling_floor(t_game *game, t_color celing, t_color floor);

/* Parsing */
void	check_walls(t_game *game);

/* Game */

void	start_game(t_game *game);
void	minimap(t_game *game, char **map);
void	draw_screen(t_game *game);
void	raycasting(t_game *game);
void	ft_draw_wall(t_game *game);

#endif
