#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "structure.h"
# include <fcntl.h> // open
# include <mlx.h>

// m_utils1
void	map_check(t_map *map);
void	m_error(char *s);
int		map_name(char *s);
int		linelen(char *s);
void	map_init(t_game *game);

// m_utils2
void	print_tab(t_map *map);
void	tile_count(t_game *game, char c, t_point pos);
void	print_s_map(t_map *map);
int		is_closed(t_map *map);
void	tile_check(t_map *map);

// s_utils1
void	sprite_init(t_game *game);
void	bg_print(t_game *game);
void	map_print(t_game *game);
void	cat_print(t_game *game);
int		all_print(t_game *game);

// game
void	game_init(t_game *game, char *mapfile);

// event
int		close_win(t_game *game);

#endif