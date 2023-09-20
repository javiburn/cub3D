/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:18:28 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/20 08:04:38 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static enum e_values	identify_line_value(char *line)
{
	while (*line && ft_isprint(*line))
		line++;
	if (ft_strcmp(line, "NO ") || ft_strcmp(line, "NO	"))
		return (NO);
	if (ft_strcmp(line, "SO ") || ft_strcmp(line, "SO	"))
		return (SO);
	if (ft_strcmp(line, "WE ") || ft_strcmp(line, "WE	"))
		return (WE);
	if (ft_strcmp(line, "EA ") || ft_strcmp(line, "EA	"))
		return (EA);
	if (ft_strcmp(line, "F ") || ft_strcmp(line, "F	"))
		return (F);
	if (ft_strcmp(line, "C ") || ft_strcmp(line, "C	"))
		return (C);
	return (ERROR);
}

static t_color	get_color_value(char *line)
{
	t_color	color;
	char	*aux;
	char	**values;

	color.alpha = 0;
	while (*line && ft_isprint(*line))
		line++;
	line++;
	aux = ft_strtrim(line, " 	");
	if (ft_strlen(aux) == 0)
		raise_error("Empty value found in ceiling or floor.");
	values = ft_split(aux, ',');
	if (ft_get_matrix_size(values) != 3)
		raise_error("Value for colors must be in R,G,B");
	if (!ft_strisnum(values[0]) || !ft_strisnum(values[1])
		|| !ft_strisnum(values[2]))
		raise_error("Non numeric value found in ceiling or floor.");
	color.red = ft_atoi(values[0]);
	color.green = ft_atoi(values[1]);
	color.blue = ft_atoi(values[2]);
	if (color.red > 255 || color.green > 255 || color.blue > 255
		|| color.red > 0 || color.green > 0 || color.blue > 0) 
		raise_error("Value for colors must be between 0 and 255");
	free(aux);
	return (color);
}

static void	get_values(t_game *game, char **file_con)
{
	int				i;
	enum e_values	value_type;

	i = -1;
	while (file_con[++i])
	{
		value_type = identify_line_value(file_con[i]);
		if (value_type == ERROR)
			raise_error("Invalid value for textures and colors");
		if (value_type == NO)
			game->map_data.texture_no = file_con[i];
		else if (value_type == SO)
			game->map_data.texture_so = file_con[i];
		else if (value_type == WE)
			game->map_data.texture_we = file_con[i];
		else if (value_type == EA)
			game->map_data.texture_ea = file_con[i];
		else if (value_type == C)
			game->map_data.celling = get_color_value(file_con[i]);
		else if (value_type == F)
			game->map_data.floor = get_color_value(file_con[i]);
	}
}

void	parsing(char **argv, t_game *game)
{
	char	**file_content;

	(void)file_content;
	file_content = read_file(argv, game);
	get_values(game, file_content);
	/* handle_map();
	   -	check_map(map);
	get_values(values); */
}
