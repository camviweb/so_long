# Projet en cours 🎮
![validation](./so_long.png)

## Description
 - Un petit jeu 2D avec la librairie graphique de 42 : la MiniLibX
 - Un petit chat (character) part d'une piece (=map) apres avoir mange quelques steaks (collectible). 
 - Page 7/12

## Keywords
 - programmation graphique

## To use
- [ ] perror -> gestion des erreurs 
- [ ] strerror
- [ ] all functions of the math library (-lm compiler option, man man 3 math)
- [ ] mlx_pixel_put.c -> my_mlx_pixel_put.c
- [ ] mlx_mouse_hook.c
- [ ] mlx_key_hook.c
- [ ] mlx_expose_hook.c
- [ ] mlx_loop_hook.c
- [ ] mlx_int_anti_resize_win.c
- [ ] mlx_int_do_nothing.c
- [ ] mlx_int_wait_first_expose.c
- [ ] mlx_int_get_visual.c
- [ ] mlx_flush_event.c
- [ ] mlx_string_put.c
- [ ] mlx_set_font.c
- [ ] mlx_get_color_value.c
- [ ] mlx_clear_window.c
- [ ] mlx_xpm.c
- [ ] mlx_int_str_to_wordtab.c
- [ ] mlx_destroy_window.c
- [ ] mlx_int_param_event.c
- [ ] mlx_int_set_win_event_mask.c
- [ ] mlx_hook.c
- [ ] mlx_rgb.c
- [ ] mlx_destroy_image.c
- [ ] mlx_mouse.c
- [ ] mlx_screen_size.c
- [ ] mlx_destroy_display.c
- [ ] **tiles** et **tilesets**
- [ ] display **sprites** et **sprite sheets**
- [ ] ? fermer fenetre ?
- [ ] the bytes are not aligned, this means that the line_length differs from the actual window width. We therefore should ALWAYS calculate the memory offset using the line length. We can calculate it by using the following formula: int offset = (y * line_length + x * (bits_per_pixel / 8));
- [ ] Game Logic (loop) : Implement movement, collision detection, and scoring, fin du jeu

## To test
- [ ] make fclean
- [ ] headers 42
- [ ] norminette
- [ ] ? testeurs ?
- [ ] valgrind !!
- [ ] file names/git repo : Makefile, *.h, *.c, maps, textures
- [ ] (guidelines -> tests)

## Utilisation
### Installer la mlx
```bash
cd minilibx && make
```
