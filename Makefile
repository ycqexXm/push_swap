# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 20:01:32 by yorlians          #+#    #+#              #
#    Updated: 2023/06/24 03:04:35 by yorlians         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME			=	push_swap
NAME_BONUS		=	checker

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra

LIBFT_FOLDER	=	utils/Libft
LIBFT			=	$(LIBFT_FOLDER)/libft.a
PRINTF_FOLDER	=	utils/ft_printf
PRINTF			=	$(PRINTF_FOLDER)/libftprintf.a

SRCS			=	checks/parsing.c checks/duplicate_check.c checks/integer_check.c checks/sorted_check.c \
					instructions/push.c instructions/reverse_rotate.c instructions/rotate.c instructions/swap.c \
					sort/sort_3.c \
					utils/list_utils.c \
					find_min_max.c free_all.c index_a.c moves.c push_back_a.c push_swap.c

GNL_SRCS		=	utils/Get_Next_Line/get_next_line_bonus.c utils/Get_Next_Line/get_next_line_utils_bonus.c

SRCS_BONUS		=	checker_bonus/checker.c utils/list_utils.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c \
					checks/sorted_check.c instructions/swap.c moves.c find_min_max.c checks/parsing.c checks/duplicate_check.c \
					checks/integer_check.c free_all.c push_back_a.c index_a.c

OBJS			=	${SRCS:.c=.o}
GNL_OBJS		=	${GNL_SRCS:.c=.o}
OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

all:				$(NAME)

$(LIBFT):
					@make all -C $(LIBFT_FOLDER)

$(PRINTF):
					@make all -C $(PRINTF_FOLDER)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)	
	gcc $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT) $(GNL_OBJS) $(PRINTF)
	gcc $(OBJS_BONUS) $(GNL_OBJS) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)

clean:
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)
					$(RM) $(GNL_OBJS)
					@make clean -C $(LIBFT_FOLDER)
					@make clean -C $(PRINTF_FOLDER)

fclean: 			clean
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					@make fclean -C $(LIBFT_FOLDER)
					@make fclean -C $(PRINTF_FOLDER)
					
re:					clean all

.PHONY:				all clean fclean re bonus