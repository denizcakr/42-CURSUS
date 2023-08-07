/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:29:53 by ezcakir           #+#    #+#             */
/*   Updated: 2023/08/05 21:29:54 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define PIXEL 64

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;

	void			*spongebob_sprite;
	void			*floor_sprite;
	void			*wall_sprite;
	void			*coin_sprite;
	void			*exit_sprite;

	int				player_x;
	int				player_y;
	int				map_height;
	int				map_width;

	unsigned int	moves;
	char			**map;

	int				exit;
	int				ply;
	int				coins;

	int				exit_is_possible;
}	t_game;

//GAME
void				start_game(char *map_name);

//INPUT
int					key_down(int keycode, t_game *game);
int					game_exit(t_game *game);

//DRAW
int					render(t_game *game);

//MAP
char				**map_constractor(t_game *game, int fd);
int					map_validation(t_game *sl);
int					flood_fill(t_game *game);
//UTILS
int					ft_strlen(char *str);
void				ft_reset(char *buffer);
char				*ft_itoa(int n);

#endif