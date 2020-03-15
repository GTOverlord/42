# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hsillem <hsillem@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/01 14:17:23 by hsillem        #+#    #+#                 #
#    Updated: 2020/03/13 20:47:23 by hsillem       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libminirt.a
SRC = image_utils math calc_col calc_dist
SRCC = $(SRC:%=%.c)
SRCO = $(SRC:%=%.o)
FLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L minilibx -lmlx -framework OpenGL -framework AppKit

ifdef DEBUG
	FLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(SRCC)
	gcc -c $(FLAGS) $(SRCC) -I.
	ar -rc $(NAME) $(SRCO)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

cr: all
	gcc main.c $(FLAGS) $(MLXFLAGS) $(NAME)
	./a.out