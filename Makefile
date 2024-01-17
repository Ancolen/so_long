src = Game_Source/main.c Game_Source/map_controls.c Game_Source/utils.c Game_Source/path_finder.c Game_Source/utils2.c Game_Source/hook.c Game_Source/graphics.c Game_Source/split.c Game_Source/split_utils.c Game_Source/map_open.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c
INC = inc
NAME = so_long
BNAME = so_long_bonus
CFLAGS = -Wall -Werror -Wextra
MLX = mlx/libmlx.a

ifeq ($(shell uname), Linux)
	FRAMEWORKS = -L/mlx -lmlx -lX11 -lXext -lm
else
	FRAMEWORKS = -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(src)
	@make -C mlx
	@gcc -g -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

bonus: $(BNAME)

$(BNAME): $(Bsrc)
	@make -C mlx
	@gcc -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

clean:
	@rm -rf $(NAME)
	@rm -rf $(BNAME)

fclean: clean
	@make -C mlx clean

re: fclean all

.PHONY: clean fclean re all
