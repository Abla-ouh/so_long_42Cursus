# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 16:30:12 by abouhaga          #+#    #+#              #
#    Updated: 2022/08/12 15:10:21 by abouhaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror #-fsanitize=address -g

NAME 	= 	so_long
NAME_BONUS = so_longbonus

LIBFT	=	libft/libft.a

PRINTF  =  ft_printf/libftprintf.a

SRC		=   So_long_mandatory/so_long.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			So_long_mandatory/lunch_game.c \
			So_long_mandatory/ft_validate_map.c \
			So_long_mandatory/ft_utils.c \
			So_long_mandatory/ft_game_on.c \
			So_long_mandatory/ft_game_off.c \
			So_long_mandatory/ft_extra_utils.c \
			so_long_mandatory/ft_collectible.c \

SRC_BONUS	=	So_long_bonus/ft_animation_bonus.c \
					get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c \
					So_long_bonus/ft_extra_utils_bonus.c \
					So_long_bonus/ft_game_enemy_anim_bonus.c \
					So_long_bonus/ft_game_off_bonus.c \
					So_long_bonus/ft_game_on_bonus.c \
					So_long_bonus/ft_utils_bonus.c \
					So_long_bonus/ft_utils2_bonus.c \
					So_long_bonus/ft_validate_map_bonus.c \
					So_long_bonus/lunch_game_bonus.c\
					So_long_bonus/so_long_bonus.c \

OBJS 	= $(SRC:.c=.o)
OBJS_BNS 	= $(SRC_BONUS:.c=.o)

all:	$(NAME)
bonus: $(NAME_BONUS)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit

$(NAME_BONUS):	$(LIBFT) $(PRINTF) $(OBJS_BNS)
	$(CC) $(CFLAGS) $(OBJS_BNS) -o $(NAME_BONUS) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf


clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(OBJS)
	rm -rf $(OBJS_BNS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all