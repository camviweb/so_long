NAME	=so_long

INCD	=include
SRCD	=src
OBJD	=obj
LIBFTD	=libft

CFLAGS	=-Wall -Wextra -Werror
MLX		=-Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
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