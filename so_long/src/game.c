/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:30:38 by ezcakir           #+#    #+#             */
/*   Updated: 2023/08/15 22:03:37 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	load_sprite(t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	game->spongebob_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/spongebob.xpm", &tmp_x, &tmp_y);
	game->wall_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/wall.xpm", &tmp_x, &tmp_y);
	game->floor_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/floor.xpm", &tmp_x, &tmp_y);
	game->coin_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/coin.xpm", &tmp_x, &tmp_y);
	game->exit_sprite = mlx_xpm_file_to_image(game->mlx,
			"./res/exit.xpm", &tmp_x, &tmp_y);
}

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
	{
		return (0);
	}
	write(1, "ERROR\n", 6);
	return (1);
}

static t_game	*game_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->coins = 0;
	game->exit = 0;
	game->ply = 0;
	game->moves = 0;
	return (game);
}

void	start_game(char *map_name)
{
	t_game	*game;
	int		fd;

	if (filename_check(map_name))
		return ;
	game = game_init();
	fd = open(map_name, O_RDONLY);
	game->map = map_constractor(game, fd);
	close(fd);
	if (map_validation(game))
	{
		write(1, "ERROR\n", 6);
		free(game);
		exit(1);
	}
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * PIXEL,
			game->map_height * PIXEL, "so_long");
	load_sprite(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_down, game);
	mlx_hook(game->mlx_win, 17, 0L << 0, game_exit, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
