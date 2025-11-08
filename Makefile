CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = main.o display_list.o get_list_length.o node_data.o add_node.o remove_node.o utils.o
NAME = main.out
LIB = libchainedlist.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

lib : $(OBJECTS)
	ar -rcs $(LIB) $(OBJECTS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME) $(LIB)

re : fclean all
