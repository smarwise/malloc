NAME = malloc

FLAGS = clang -Wall -Wextra -Werror -Wuninitialized

OBJ = obj/malloc.o obj/free.o obj/realloc.o\
		obj/large.o obj/small.o obj/tiny.o\
		obj/get_new_pointer.o\

$(NAME): $(OBJ)
		make -C libft/
		$(FLAGS) -g  -o $(NAME) $(OBJ) libft/libft.a

all:
	make $(NAME)

$(OBJ): obj/%.o: srcs/%.c
		$(FLAGS) -c -g srcs/$*.c -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)
	
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	
re: fclean all