# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:28:30 by yyakuben          #+#    #+#              #
#    Updated: 2024/05/16 22:25:48 by yyakuben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export red=`tput setaf 1`
export green=`tput setaf 2`
export yellow=`tput setaf 3`
export blue=`tput setaf 4`
export magenta=`tput setaf 5`
export cyan=`tput setaf 6`
export white=`tput setaf 7`
export reset=`tput sgr0`


SRCS		=	main.c map_create.c image_create.c image_to_window.c\
				check_map.c check_parses.c handle_error.c actions.c\
				check_collectible.c\


# BONUS_SRCS 	=	utils.c main.c static_path_enum.c map.c\
# 				valid_map.c exit_game.c movements.c \
# 				init_game.c events.c path_finder.c \
# 				animation.c init_enemy.c


MLX_FLAGS		=   -L$(MLX) -lmlx_Linux -I$(MLX)/mlx.h -lXext -lX11 -lm -lz -o $(NAME)
CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	gcc
SRCS_F			= src/

OBJS_F			= obj/
OBJS_F_B		= obj_bonus/

SRCS_B			= src_bonus/

PRINTF = inc/ft_printf/
MLX = MiniLibX/
GNL = inc/get_next_line/
LFT = inc/libft/

OBJS			=	$(SRCS:.c=.o)
OBJS_B			=	$(BONUS_SRCS:.c=.o)

OBJS_P			=	$(addprefix $(OBJS_F), $(OBJS))
OBJS_BONUS		=	$(addprefix $(OBJS_F_B), $(OBJS_B))

NAME			= 	so_long

all:$(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile so_long.h
	@mkdir -p $(OBJS_F)
	@echo "${magenta}Working on: ${reset} $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS_P)
	@$(MAKE) -C $(MLX) 
	@$(MAKE) -C $(PRINTF) 
	@$(MAKE) -C $(GNL)
	@$(MAKE) -C $(LFT)
	@$(CC)  -o $(NAME) $(OBJS_P) $(CC_FLAGS) -O3 $(MLX_FLAGS) $(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a
	@echo "${green}OK main part${reset}"

$(OBJS_F_B)%.o: $(SRCS_B)%.c Makefile so_long.h
	@mkdir -p $(OBJS_F_B)
	@echo "${magenta}Working on: ${reset} $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@


bonus: $(OBJS_BONUS)


	@$(MAKE) -C $(MLX) 
	@$(MAKE) -C $(PRINTF) 
	@$(MAKE) -C $(GNL)
	@$(MAKE) -C $(LFT)
	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) $(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a -o $(NAME) $(OBJS_BONUS)
	@echo "${green}OK Bonus part${reset}"

clean:
	@rm -rf $(OBJS_F)
	@rm -rf $(OBJS_F_B)
	# @$(MAKE) clean -C $(	) 
	@$(MAKE) fclean -C $(PRINTF) 
	@$(MAKE) fclean -C $(GNL)
	@$(MAKE) fclean -C $(LFT)

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re