NAME	=so_long

INCD	=include
SRCD	=src
OBJD	=obj
LIBFTD	=libft
MLXD	=minilibx-linux

CFLAGS	=-Wall -Wextra -Werror
MLX		=-L$(MLXD) -lmlx -L/usr/lib -I$(MLXD) -lXext -lX11 -lm -lz
CC		=cc $(CFLAGS)

SRC 	=$(SRCD)/main.c \
$(SRCD)/m_utils1.c \
$(SRCD)/m_utils2.c \
$(SRCD)/m_utils3.c \
$(SRCD)/s_utils1.c \
$(SRCD)/game.c \
$(SRCD)/event.c

OBJ		=$(OBJD)/main.o \
$(OBJD)/m_utils1.o \
$(OBJD)/m_utils2.o \
$(OBJD)/m_utils3.o \
$(OBJD)/s_utils1.o \
$(OBJD)/game.o \
$(OBJD)/event.o

LIBFT	=$(LIBFTD)/libft.a
LIBMLX		=$(MLXD)/libmlx.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJ) -L$(LIBFTD) -lft -I$(INCD) $(MLX) -o $@

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	$(CC) -I/usr/include -I$(MLXD) -O3 -I$(INCD) -o $@ -c $<

$(OBJD):
	mkdir -p $(OBJD)

$(LIBFT):
	make -C $(LIBFTD)

$(LIBMLX):
	make -C $(MLXD)

clean: 
	rm -rf $(OBJD)
	make -C $(LIBFTD) clean
	make -C $(MLXD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean
	make -C $(MLXD) clean

re: fclean all

.PHONY: all clean fclean re