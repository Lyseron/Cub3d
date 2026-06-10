NAME       = cub3d
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g

INCS	   = -I. -I$(LIBFT_DIR)

LIBFT_DIR  = libft

LIBFT      = $(LIBFT_DIR)/libft.a

SRCS_DIR   = src

PARS_DIR   = $(SRCS_DIR)/parsing
CLEAN_DIR  = $(SRCS_DIR)/clean_exit


PARS_SRC   = \
	$(PARS_DIR)/check_valid_map.c \
	$(PARS_DIR)/check_valid_map_utils.c \
	$(PARS_DIR)/check_map_cub.c \
	$(PARS_DIR)/init_player.c \
	$(PARS_DIR)/init_mlx.c \
	$(PARS_DIR)/mini_map.c \
	$(PARS_DIR)/create_img.c

CLEAN_SRC  = \
	$(CLEAN_DIR)/clean_mlx.c

SRCS    = \
	$(PARS_SRC) \
	$(CLEAN_SRC) \
	$(SRCS_DIR)/main.c


OBJ_DIR    = obj/
OBJS    = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

RM      = rm -f
UNAME_S := $(shell uname)

ifeq ($(UNAME_S),Darwin)
	MLX_DIR = mlx_macos
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx
	MLX_INC = -I$(MLX_DIR)
	MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

INC = -Iincludes $(MLX_INC)
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@printf "🍀\033[32m Compiling completed \033[0m🍀\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(INC) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(MLX_DIR) clean > /dev/null 2>&1
	@printf "\033[34mObjects cleaned\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "\033[36mFull clean\033[0m\n"

re: fclean all

.PHONY: all clean fclean re