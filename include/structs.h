/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:37:11 by alaparic          #+#    #+#             */
/*   Updated: 2023/10/13 15:24:49 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * Main program struct containing the mlx vars
*/

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map_data
{
	char	**map;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		max_x;
	int		max_y;
	t_color	floor;
	t_color	ceiling;
}	t_map_data;

/**
 * Player position and direction
*/
typedef struct s_player
{
	float		x;
	float		y;
	float		old_x;
	float		old_y;
	float		dx;
	float		dy;
	float		camera;
	t_vector	direction;
}	t_player;

typedef struct s_camera
{
	int			hit;
	int			offset;
	int			grid_x;
	int			grid_y;
	int			**buffer;
	float		x;
	float		y;
	float		stepx;
	float		stepy;
	float		camerax;
	float		directionx;
	float		directiony;
	t_vector	plane;
	float		raydirx;
	float		raydiry;
	float		dx;
	float		dy;
	float		sidedx;
	float		sidedy;
	float		distance;
	double		wallx;
	double		wally;
	float		lineheight;
}	t_camera;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map_data	map_data;
	t_img		img;
	t_player	player;
	t_camera	camera;
	void		*textu_n;
	void		*textu_s;
	void		*textu_e;
	void		*textu_w;
}	t_game;

#endif
