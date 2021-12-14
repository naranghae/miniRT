# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 15:43:14 by chanykim          #+#    #+#              #
#    Updated: 2021/03/18 16:55:50 by chanykim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
		srcs/libft.c srcs/get_next_line.c\
		srcs/key_utils.c srcs/parsing.c srcs/init_parameter.c \
		srcs/error.c srcs/color_calc.c \
		srcs/calculate_func.c srcs/parse_elements.c \
		srcs/make_img_utils.c srcs/make_img.c \
		srcs/ray_utils.c srcs/vector_utils.c \
		srcs/vector_utils2.c srcs/vector_utils3.c srcs/vector_utils4.c\
		srcs/parse_object.c srcs/sphere.c srcs/plane.c \
		srcs/parsing_utils.c srcs/rt_free.c srcs/object_free.c \
		srcs/square.c srcs/triangle.c srcs/cylinder.c srcs/cylinder_utils.c \
		srcs/bmp_save.c

OBJS	= $(SRCS:.c=.o)

BONUS = bonus/cone_bonus.c bonus/free_bonus.c \
		bonus/cone_utils_bonus.c bonus/cube_bonus.c \
		bonus/pyramid_bonus.c bonus/pyramid_utils_bonus.c \
		bonus/filter_sepia_bonus.c

OBJSBONUS = $(BONUS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME	= libft.a
MLXDIR	= ./mlx/
MLXNAME	= libmlx.dylib

NAME	= miniRT

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror -g
RM		= rm -f

%.o:		%.c
			$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME) $(MLXNAME) $(OBJS) $(OBJSBONUS)
			$(GCC) $(GCCFLAG) -I$(INCDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(OBJSBONUS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
			@$(MAKE) -C $(LIBDIR) bonus
			@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

$(MLXNAME):
			@$(MAKE) -C $(MLXDIR)
			@cp $(addprefix $(MLXDIR), $(MLXNAME)) $(MLXNAME)

fsani:
	$(GCC) $(GCCFLAG) -fsanitize=address -I$(INCDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(OBJSBONUS) $(LIBNAME) $(MLXNAME)

bonus:
	$(GCC) $(GCCFLAG) -I$(INCDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(OBJSBONUS) $(LIBNAME) $(MLXNAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJSBONUS) rt/*.bmp

fclean:		clean
			$(RM) $(NAME) $(LIBNAME) $(MLXNAME)
			@$(MAKE) -C $(LIBDIR) fclean
			@$(MAKE) -C $(MLXDIR) clean

debug:		clean  all

re:			fclean all

.PHONY:		all clean fclean re fsani
