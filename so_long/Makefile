NAME	=	so_long

DEF		=	-D NUMBER_WASP=2

HEADER_DIR	=	includes
HEADER	=	so_long.h	struct.h

DIR	=	source
FC	=	main.c	events.c	init.c	move.c	ft_itoa.c	wasp.c	end_game.c	draw.c\
		utils.c		utils_validate.c	validate.c		get_next_line.c		get_next_line_utils.c
FO	=	$(addprefix $(DIR)/,$(FC:%.c=%.o))
FH	=	$(addprefix $(HEADER_DIR)/,$(HEADER))

GFLAGS	=	-Wall -Wextra -Werror

.PHONY	: all clean fclean re mandatory bonus

%.o	:	%.c $(FH)
			$(CC) $(GFLAGS) $(DEF) -c $< -o $(<:.c=.o) -I mlx -I $(HEADER_DIR)

all		:	$(NAME)

$(NAME)	:	$(FO) $(FH)
			$(CC) $(GFLAGS) $(DEF) -o $(NAME) $(FO) -Lmlx -lmlx -framework OpenGL -framework AppKit

clean	:
		@rm -f $(FO)

fclean	:	clean
		@rm -f $(NAME)

re		:	fclean all
