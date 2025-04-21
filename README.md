# Projet en cours 🎮
![validation](./so_long.png)

## Description
 - Un petit jeu 2D avec la librairie graphique de 42 : la MiniLibX
 - Vous etes un chat qui arrivait d'un carton et vous devez partir de la piece apres avoir mange tous les steaks, en moins de coups possible. 
 - Page 12/12

## Keywords
 - programmation graphique

## To use
- [ ] perror, strerror -> gestion des erreurs 
- [ ] all functions of the math library (-lm compiler option, man man 3 math)
- [ ] **tiles** et **tilesets**
- [ ] Pressing ESC must close the window and quit the program in a clean way
- [ ] Game Logic (loop) : Implement movement, collision detection, and scoring, fin du jeu
- [ ] The W, A, S, and D keys must be used to move the cat
- [ ] The cat should be able to move in these four directions: up, down, left, and right.
- [ ] The cat should not be able to move into walls.
- [ ] At every move, the current number of movements must be displayed in the shell
- [ ] not have to be in real time
- [ ] Window management must remain smooth (switching to another window, minimizing)
- [ ] verify if there is a valid path in the map

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

### Compilation
```bash
cd .. && make
```

### Execution avec map.ber, ou autre map
```bash
./so_long map/map.ber
```
