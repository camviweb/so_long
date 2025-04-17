CFLAGS	=-Wall -Wextra -Werror
MLX		=-Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
CC		=cc $(CFLAGS)
NAME	=so_long
SRC 	=main.c \
form.c \
color.c \
texture.c
OBJD	=obj
OBJ		=$(SRC:%.c=$(OBJD)/%.o)
LIBFTD	=libft
LIBFT	=$(LIBFTD)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFTD) -lft $(MLX) -o $@

$(OBJD)/%.o: %.c | $(OBJD)
	$(CC) -I/usr/include -Iminilibx-linux -O3 -o $@ -c $<

$(OBJD):
	mkdir -p $(OBJD)

$(LIBFT):
	make -C $(LIBFTD)

clean: 
	rm -rf $(OBJD)
	make -C $(LIBFTD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all

.PHONY: all clean fclean re