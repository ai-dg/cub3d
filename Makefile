# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 12:07:46 by dagudelo          #+#    #+#              #
#    Updated: 2024/09/30 15:32:03 by dagudelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/zsh
SRC = ./Srcs/check_map.c        ./Srcs/cube3d_textures.c       ./Srcs/handle_drawers.c        ./Srcs/math_tools.c              ./Srcs/parsing_tools.c               ./Srcs/sprites_routine_convert_sprite_coords.c \
	./Srcs/debug.c            ./Srcs/handle_keyboard.c       ./Srcs/math_tools_orientation.c  ./Srcs/printer.c                     ./Srcs/sprites_routine_render_sprites.c \
	./Srcs/check_maps_msg.c   ./Srcs/doors.c                 ./Srcs/handle_keyboard_door.c  ./Srcs/mlx_cycles.c              ./Srcs/raycasting.c                  ./Srcs/sprites_routine_tools.c \
	./Srcs/check_map_tools.c  ./Srcs/free_on_exit.c          ./Srcs/handle_mouse.c          ./Srcs/moves.c                   ./Srcs/raycasting_distance_limits.c  ./Srcs/sprites_tools_check.c \
	./Srcs/circles.c          ./Srcs/free_on_exit_destroy.c  ./Srcs/init_bonus.c            ./Srcs/moves_rotation.c          ./Srcs/raycasting_init_textures.c    ./Srcs/sprites_tools_destroy.c \
	./Srcs/collision.c        ./Srcs/game_map.c              ./Srcs/init.c                  ./Srcs/parsing.c                 ./Srcs/raycasting_map_side_dist.c    ./Srcs/sprites_tools_parsing_path.c \
	./Srcs/collision_door.c   ./Srcs/game_map_draw_map.c     ./Srcs/lines.c                 ./Srcs/parsing_color.c           ./Srcs/raycasting_put_textures.c     ./Srcs/zbuffers.c \
	./Srcs/cube3d.c           ./Srcs/game_map_image.c        ./Srcs/map_dimensions.c        ./Srcs/parsing_graphics.c        ./Srcs/raycasting_variable_calc.c \
	./Srcs/cube3d_exit.c      ./Srcs/game_map_limits.c       ./Srcs/map_tools2.c            ./Srcs/parsing_map.c             ./Srcs/sprites.c \
	./Srcs/cube3d_init.c      ./Srcs/handle_colors.c         ./Srcs/map_tools.c             ./Srcs/parsing_set_map.c         ./Srcs/sprites_routine.c
OBJ =	$(SRC:.c=.o)
NAME = cub3D

CC	= cc
CFLAGS = -Wall -Wextra -Werror -g
X11 = /usr/lib/x86_64-linux-gnu/X11
GPATH = ./Includes/minilibx
MLX_PATH = $(GPATH)/libmlx_Linux.a
CFLAGS += -I$(GPATH) -I. -I./Includes -I./Includes/libft
LDFLAGS = -L $(GPATH) -lmlx  -lX11 -lXext -lm -lbsd -lreadline -lcurses -L $(LIBFT_DIR) -lft
#LDFLAGS = -L $(X11)  -lX11 -L $(GPATH) -lmlx  -lXext -lm -lbsd -lreadline -lcurses -L $(LIBFT_DIR) -lft
LIBFT_DIR = ./Includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

GREEN = \033[32m
BLINK = \033[5m
RESET = \033[0m
ORANGE = \033[33m


define SHOW_PROGRESS
@echo -n "$(1) $(2)"; \
for i in `seq 1 3`; do \
    sleep 0.1; \
    echo -n "."; \
done; \
echo ""
endef

define ASCII_ART
@cat ./Includes/ascii_art.txt
endef

define CHECK_MINILIBX
    @if [ -d "$(GPATH)" ]; then \
        if [ -z "`ls -A $(GPATH)`" ]; then \
            echo "$(GPATH) exists but is empty, downloading minilibx"; \
            rm -rf $(GPATH); \
            git clone https://github.com/42Paris/minilibx-linux.git $(GPATH); \
        fi; \
    else \
        echo "Downloading minilibx."; \
        git clone https://github.com/42Paris/minilibx-linux.git $(GPATH); \
    fi
endef

%.o : %.c
	$(call SHOW_PROGRESS,Compiling,$<)
	$(call CHECK_MINILIBX,Building,minilibx)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : _ascii_art $(OBJ) $(MLX_PATH) $(LIBFT)
	$(call SHOW_PROGRESS,Linking,$(NAME))
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo  "$(GREEN)$(BLINK)$(NAME) compiled successfully!$(RESET)"

$(LIBFT):
	$(call SHOW_PROGRESS,Building,libft)
	@make -C $(LIBFT_DIR)

all : _ascii_art $(MLX_PATH) $(LIBFT) $(NAME)

$(MLX_PATH) :
	$(call SHOW_PROGRESS,Building,minilibx)
	$(call CHECK_MINILIBX,Building,minilibx)
	@make -C $(GPATH) 
	@make -C $(GPATH) -f Makefile.gen

clean :
	$(call SHOW_PROGRESS,Cleaning,object files)
	@rm -rf $(OBJ)
	@if [ -d $(GPATH) ]; then \
		make clean -C $(GPATH); \
	else \
		echo "$(GPATH) does not exist."; \
	fi
	@echo "$(ORANGE)$(BLINK)Objects files cleaned.$(RESET)"
	@if [ -d $(LIBFT_DIR) ]; then \
		make clean -C $(LIBFT_DIR); \
	else \
		echo "$(LIBFT_DIR) does not exist."; \
	fi

fclean : clean
	$(call SHOW_PROGRESS,Cleaning,$(NAME) program and objects)
	@if [ -d $(GPATH) ]; then \
		rm -rf $(GPATH); \
	else \
		echo "$(GPATH) does not exist."; \
	fi
	@rm -rf $(NAME)
	@echo "$(ORANGE)$(BLINK)$(NAME) program cleaned.$(RESET)"
	@make fclean -C $(LIBFT_DIR)

_ascii_art:
	$(call ASCII_ART)

val :
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D maps/map2.cub

launch :
	./cub3D maps/map1.cub

launch2 :
	./cub3D maps/map2.cub


launch3 :
	./cub3D maps/map3.cub

launch6 :
	./cub3D maps/map6.cub

re : fclean all

.PHONY : all clean fclean re $(MLX_PATH) $(LIBFT) _ascii_art val launch
