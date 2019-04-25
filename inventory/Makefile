##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_rpg
##

NAME	=	my_rpg

SRC	=	src

SRCS	=	$(SRC)/main.c				\
		$(SRC)/init_items.c			\
		$(SRC)/destroy_items.c			\
		$(SRC)/print_items_data.c		\
		$(SRC)/items/create_sword.c		\
		$(SRC)/items/create_ring.c		\
		$(SRC)/get_input/get_input.c		\
		$(SRC)/get_input/remove_return_line.c	\
		$(SRC)/init_inventory.c			\
		$(SRC)/manage_inventory.c		\
		$(SRC)/print_inventory_data.c		\
		$(SRC)/destroy_inventory.c		\
		$(SRC)/add_item.c			\
		$(SRC)/remove_item.c			\
		$(SRC)/graphics/graphics.c		\
		$(SRC)/graphics/check_event.c		\
		$(SRC)/graphics/display_inventory.c	\
		../$(SRC)/create_window.c		\

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L../lib/my

MY	=	-lmy

GRAPH	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

MAKE	=	make

RM	=	rm -f

CFLAGS	=	-I../include -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../lib/my --no-print-directory
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)

clean:
	$(MAKE) clean -C ../lib/my --no-print-directory
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ../lib/my --no-print-directory
	$(RM) *~
	$(RM) $(SRC)/*~
	$(RM) $(SRC)/items/*~
	$(RM) $(SRC)/get_input/*~
	$(RM) $(SRC)/graphics/*~
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g

debug: fclean $(OBJS)
	$(MAKE) debug -C lib/my
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MY) $(GRAPH)
