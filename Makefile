NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -g -Werror
MAKEFLAGS	+= --no-print-directory

INCS		= -I. -I$(LIBFT_DIR)

# BLACK		= \033[0;30m
# RED			= \033[0;31m
# GREEN		= \033[0;32m
# YELLOW		= \033[0;33m
# BLUE		= \033[0;34m
# MAGENTA		= \033[0;35m
# CYAN		= \033[0;36m
# GRAS		= \033[1m
# RESET		= \033[0m

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= ./src/main.c\
			./src/parsing/extract.c\
			./src/parsing/extract_map.c\
			./src/parsing/extract_color.c\
			./src/parsing/check_name_texture.c\
			./src/parsing/read_map.c\
			./src/parsing/extract_texture_and_color.c\
			./src/parsing/free.c\

OBJS		= $(SRCS:%.c=%.o)
RM			= rm -f
UNAME_S		:= $(shell uname)
SRCS_DIR   = src

PARS_DIR    = $(SRCS_DIR)/parsing
CLEAN_DIR   = $(SRCS_DIR)/clean_exit
INIT_DIR    = $(SRCS_DIR)/init
MINI_DIR    = $(SRCS_DIR)/mini_map
MLX_WIN_DIR = $(SRCS_DIR)/mlx_win

PARS_SRC   = \
	$(PARS_DIR)/check_valid_map.c \
	$(PARS_DIR)/check_valid_map_utils.c \
	$(PARS_DIR)/check_map_cub.c \
	$(PARS_DIR)/check_name_texture.c\
	$(PARS_DIR)/read_map.c
	
MLX_WIN_SRC = \
	$(MLX_WIN_DIR)/create_img.c

MINI_SRC    = \
	$(MINI_DIR)/mini_map.c

INIT_SRC    = \
	$(INIT_DIR)/extract_color.c \
	$(INIT_DIR)/extract.c \
	$(INIT_DIR)/verif_extract.c \
	$(INIT_DIR)/extract_map.c \
	$(INIT_DIR)/extract_texture_and_color.c \
	$(INIT_DIR)/init_player.c \
	$(INIT_DIR)/init_mlx.c

CLEAN_SRC  = \
	$(CLEAN_DIR)/clean_mlx.c \
	$(CLEAN_DIR)/free.c

SRCS    = \
	$(PARS_SRC) \
	$(CLEAN_SRC) \
	$(MLX_WIN_SRC) \
	$(INIT_SRC) \
	$(MINI_SRC) \
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
# 	@$(MAKE) name_ascii;
# 	@$(MAKE) user42;
	@printf "🍀\033[32m Compiling completed \033[0m🍀\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(INC) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

clean:
	@$(RM) $(OBJS) .last_colors vgcore.* logs
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(MLX_DIR) clean > /dev/null 2>&1
	@printf "\033[34mObjects cleaned\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "\033[36mFull clean\033[0m\n"

re: fclean all


# COLOR_FILE	= .last_colors

# # Fonction pour obtenir une couleur différente de la précédente
# define get_random_color
# $(shell \
# 	LAST=$$(cat $(COLOR_FILE) 2>/dev/null | head -1 || echo 0); \
# 	NEW=$$(od -An -N1 -tu1 /dev/urandom | tr -d ' '); \
# 	NEW=$$((NEW % 6 + 1)); \
# 	COUNT=0; \
# 	while [ "$$NEW" = "$$LAST" ] && [ $$COUNT -lt 10 ]; do \
# 		NEW=$$(od -An -N1 -tu1 /dev/urandom | tr -d ' '); \
# 		NEW=$$((NEW % 6 + 1)); \
# 		COUNT=$$((COUNT + 1)); \
# 	done; \
# 	echo $$NEW > $(COLOR_FILE); \
# 	printf "\033[0;3%dm" $$NEW \
# )
# endef


# name_ascii:
# 	@$(eval COL1=$(call get_random_color))
# 	@$(eval COL2=$(call get_random_color))
# 	@$(eval COL3=$(call get_random_color))
# 	@$(eval COL4=$(call get_random_color))
# 	@$(eval COL5=$(call get_random_color))
# 	@printf "\n"
# #	@printf "$(call get_random_color)$(GRAS)"
# 	@printf "                                                                                         _______     ___    _  _______      .-'''-.    ______     \n"
# 	@printf "                                                                                        /   __  \  .'   |  | |\  ____  \   /   _   \  |    $(COL5)_$(RESET) '''. \n"
# 	@printf "                                                                                       | $(COL1),_$(RESET)/  \__) |   .'  | || |    \ |  |__/' '.  | | $(COL5)_ | ) _ $(RESET) \ \n"
# 	@printf "                                                                                     $(COL1),-./  )$(RESET)       .'  '$(COL2)_$(RESET)  | || |____/ /     .--'  /  |$(COL5)( ''_'  )$(RESET) |\n"
# 	@printf "                                                                                     $(COL1)\  '_ '')$(RESET)     |   $(COL2)( \.-.$(RESET)||   $(COL3)_ _$(RESET) '.  ___'--$(COL4)._ _\$(RESET)  | $(COL5). (_) '.$(RESET) |\n"
# 	@printf "                                                                                      $(COL1)> (_)  )$(RESET)  __ | $(COL2)('. _' /$(RESET)||  $(COL3)( ' )$(RESET)  \|   |  $(COL4)( ' )$(RESET) |$(COL5)(_    ._)$(RESET) '\n"
# 	@printf "                                                                                     $(COL1)(  .  .-'$(RESET)_/  )| $(COL2)(_ (_) _)$(RESET)| $(COL3)(_{;}_)$(RESET) ||   '-$(COL4)(_{;}_)$(RESET)|  $(COL5)(_.\.'$(RESET) / \n"
# 	@printf "                                                                                      $(COL1)'-''-'$(RESET)     /  \ $(COL2)/  . \ /$(RESET)|  $(COL3)(_,_)$(RESET)  / \     $(COL4)(_,_)$(RESET) |       .'  \n"
# 	@printf "                                                                                        '._____.'    '$(COL2)'-''-''$(RESET) /_______.'   '-..__.-'  '-----''    $(RESET)\n"


# user42:
# 	@$(eval COL1=$(call get_random_color))
# 	@$(eval COL2=$(call get_random_color))
# 	@$(eval COL3=$(call get_random_color))
# 	@$(eval COL4=$(call get_random_color))
# 	@$(eval COL5=$(call get_random_color))
# 	@$(eval COL6=$(call get_random_color))
# 	@$(eval COL7=$(call get_random_color))
# 	@$(eval COL8=$(call get_random_color))
# 	@$(eval COL9=$(call get_random_color))
# 	@$(eval COL10=$(call get_random_color))
# 	@$(eval COL11=$(call get_random_color))
# 	@$(eval COL12=$(call get_random_color))
# 	@$(eval COL13=$(call get_random_color))
# 	@$(eval COL14=$(call get_random_color))
# 	@$(eval COL15=$(call get_random_color))
# 	@$(eval COL16=$(call get_random_color))
# 	@printf "   .---.       ____     __   ____     _______       .-''-.  .-------.      .-$(COL8)_$(RESET)'''-.       .-''-.                $(COL10)_ _$(RESET)          ,---.    ,---.,---.  ,---.$(COL13).-./')$(RESET)   .-$(COL14)_$(RESET)'''-.   ,---.   .--.    .-''-.     .-'''-.   \n"
# 	@printf "   | $(COL2),_$(RESET)|       \\\\   \\\\   /  /.'  __ '. \\\\  ____  \\\\   .'$(COL6)_ _$(RESET)   \\\\ |  $(COL7)_ _$(RESET)   \\\\    '$(COL8)_( )_$(RESET)   \\\\    .'$(COL9)_ _$(RESET)   \\\\              $(COL10)( ' )$(RESET)         |    \\\\  /    ||   /  |   |$(COL13)\\\\ .-.')$(RESET) '$(COL14)_( )_$(RESET)   \\\\  |    \\\\  |  |  .'$(COL15)_ _$(RESET)   \\\\   / $(COL16)_ $(RESET)    \\\\  \n"
# 	@printf "$(COL2) ,-./  )$(RESET)        \\\\  $(COL3)_$(RESET). /  '/   '  \\\\  \\\\| |    \\\\ |  / $(COL6)( ' )$(RESET)   '| $(COL7)( ' )$(RESET)  |   |$(COL8)(_ o _)$(RESET)|  '  / $(COL9)( ' )$(RESET)   '            $(COL10)(_{;}_)$(RESET)        |  ,  \\\\/  ,  ||  |   |  .'$(COL13)/ '-' \\\\$(RESET)|$(COL14)(_ o _)$(RESET)|  ' |  ,  \\\\ |  | / $(COL15)( ' )$(RESET)   ' $(COL16)('' )$(RESET)/'--'  \n"
# 	@printf "$(COL2) \\\\  '_ '')$(RESET)       $(COL3)_( )_$(RESET) .' |___|  /  || |____/ / . $(COL6)(_ o _)$(RESET)  ||$(COL7)(_ o _)$(RESET) /   . $(COL8)(_,_)$(RESET)/___| . $(COL9)(_ o _)$(RESET)  |             $(COL10)(_,_)$(RESET)         |  |\\\\$(COL11)_$(RESET)   /|  ||  | $(COL12)_$(RESET) |  |  $(COL13)'-''\\\"'$(RESET). $(COL14)(_,_)$(RESET)/___| |  |\\\\$(COL14)_$(RESET) \\\\|  |. $(COL15)(_ o _)$(RESET)  |$(COL16)(_ o _)$(RESET).     \n"
# 	@printf "$(COL2)  > (_)  )$(RESET)   ___$(COL3)(_ o _)$(RESET)'     _.-'   ||   $(COL5)_ _$(RESET) '. |  $(COL6)(_,_)$(RESET)___|| $(COL7)(_,_)$(RESET).' __ |  |  .-----.|  $(COL9)(_,_)$(RESET)___|             //            |  $(COL11)_( )_$(RESET)/ |  ||  $(COL12)_( )_$(RESET)  |  .---. |  |  .-----.|  $(COL14)_( )_$(RESET)\\\\  ||  $(COL15)(_,_)$(RESET)___| $(COL16)(_,_)$(RESET). '.   \n"
# 	@printf "$(COL2) (  .  .-'$(RESET)  |   |$(COL3)(_,_)$(RESET)'   .'   $(COL4)_$(RESET)    ||  $(COL5)( ' )$(RESET)  \\\\'  \\\\   .---.|  |\\\\ \\\\  |  |'  \\\\  '-   .''  \\\\   .---.            //             | $(COL11)(_ o _)$(RESET) |  |\\\\ $(COL12)(_ o._)$(RESET) /  |   | '  \\\\  '-   .'| $(COL14)(_ o _)$(RESET)  |'  \\\\   .---..---.  \\\\  :  \n"
# 	@printf "$(COL2)  '-''-'$(RESET)|___|   '-'  /    |  $(COL4)_( )_$(RESET)  || $(COL5)(_{;}_)$(RESET) | \\\\  '-'    /|  | \\\\ ''   / \\\\  '-''   |  \\\\  '-'    /         ,-'/              |  $(COL11)(_,_)$(RESET)  |  | \\\\ $(COL12)(_,_)$(RESET) /   |   |  \\\\  '-''   | |  $(COL14)(_,_)$(RESET)\\\\  | \\\\  '-'    /\\\\    '-'  |  \n"
# 	@printf "   |        \\\\\\\\      /     \\\\ $(COL4)(_ o _)$(RESET) /|  $(COL5)(_,_)$(RESET)  /  \\\\       / |  |  \\\\    /   \\\\        /   \\\\       /         )  (               |  |      |  |  \\\\     /    |   |   \\\\        / |  |    |  |  \\\\       /  \\\\       /   \n"
# 	@printf "   '--------' '-..-'       '.$(COL4)(_,_)$(RESET).' /_______.'    ''-..-'  ''-'   ''-'     ''-...-'     ''-..-'          '---'              '--'      '--'   '---'     '---'    ''-...-'  '--'    '--'   ''-..-'    '-...-'    \n"
# 	@printf "$(RESET)\n"

.PHONY: all clean fclean re
