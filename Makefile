NAME	=so_long

INCD	=include
SRCD	=src
OBJD	=obj
LIBFTD	=libft

CFLAGS	=-Wall -Wextra -Werror
MLX		=-Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
CC		=cc $(CFLAGS)

SRC 	=$(SRCD)/main.c \
$(SRCD)/form.c \
$(SRCD)/color.c \
$(SRCD)/texture.c \
$(SRCD)/m_utils1.c \
$(SRCD)/m_utils2.c \
$(SRCD)/s_utils1.c \
$(SRCD)/game.c

OBJ		=$(OBJD)/main.o \
$(OBJD)/form.o \
$(OBJD)/color.o \
$(OBJD)/texture.o \
$(OBJD)/m_utils1.o \
$(OBJD)/m_utils2.o \
$(OBJD)/s_utils1.o \
$(OBJD)/game.o

LIBFT	=$(LIBFTD)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFTD) -lft -I$(INCD) $(MLX) -o $@

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	$(CC) -I/usr/include -Iminilibx-linux -O3 -I$(INCD) -o $@ -c $<

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