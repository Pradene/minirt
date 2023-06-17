FILES	= camera/camera.c \
		event/event.c \
		math/matrix.c \
		math/vec.c \
		object/sphere.c \
		render/renderer.c \
		render/render.c \
		utils/clamp.c \
		utils/fmin.c \
		utils/pixel.c \
		utils/radian.c \
		utils/rgba.c \
		main.c

SRCS	= $(addprefix srcs/, $(FILES))

OBJS	= $(SRCS:.c=.o)

CC		= cc -fenable-matrix

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= minirt

.SILENT:

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: re fclean clean all