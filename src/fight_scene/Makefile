NAME	=	rpg

SRCS	=	main.c			\
		init/create_button.c		\
		display_fight_scene.c	\
		init/create_object.c	\
		init/init_fight_scene.c	\
		../create_window.c	\

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-L../../lib/my -lmy

CFLAGS	=	-I../../include/

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

all	:	lib

lib	:
		make -C ../../lib/my

all	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(FLAGS)

clean	:
		$(RM) $(OBJS)
		make clean -C ../../lib/my

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C ../../lib/my

re	:	fclean all

.PHONY	:	lib clean fclean re
