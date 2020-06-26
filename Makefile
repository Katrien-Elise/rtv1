# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 20:11:18 by nmartins       #+#    #+#                 #
#    Updated: 2019/07/03 21:59:08 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=RTv1

OBJECT_NAMES=	\
				rtv1 \
				gfx_setup \
				gfx_debug \
				gfx_cleanup \
				gfx_loop \
				gfx_render \
				gfx_color \
				gfx_prim \
				gfx_time \
				gfx_vec3 \
				gfx_vec2 \
				gfx_point \
				gfx_scene \
				gfx_sphere \
				gfx_plane \
				gfx_material \
				gfx_ray \
				gfx_camera \
				gfx_math \
				gfx_update \
				evt_keys \
				
# dependencies
#
# libft

LIBFT=./libft

# do not configure
CC=gcc
INCLUDES=-I./inc -I./libft
SRC=./src
OBJ=./.obj
EXTRA=
CFLAGS=-Werror -Wall -Wextra $(EXTRA) -pthread -I/usr/local/include/SDL2 -D_THREAD_SAFE
LFLAGS=-L$(LIBFT) -lft -L/usr/local/lib -lSDL2
OBJECTS=$(patsubst %, $(OBJ)/%.o, $(OBJECT_NAMES))
SOURCES=$(patsubst %, $(SRC)/%.c, $(OBJECT_NAMES))

# colors feel free to add more as you need them
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

#########
# rules #
#########
all: $(NAME)

$(LIBFT)/libft.a:
	@echo ">>= Making libft"
	@$(MAKE) -C $(LIBFT)
	@echo ">>= Done making libft"

libft_clean:
	@$(MAKE) -C $(LIBFT) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT) fclean

$(NAME): $(LIBFT)/libft.a $(OBJECTS)
	@printf " λ Linking $(UNDERLINE)$(BLUE)$@$(RESET)\n"
	@$(CC) -o $@ $(OBJECTS) $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$^$(RESET)\n"
	@$(CC) -c -o $@ $^ $(CFLAGS) $(INCLUDES)

clean:
	@echo "$(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJ)

fclean: libft_fclean clean
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
quickre:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@$(MAKE) -C .

superfast:
	@$(MAKE) EXTRA=-O2 re -C . 

.SECONDARY: $(OBJECTS)
.PHONY: all debug libft clean fclean re
