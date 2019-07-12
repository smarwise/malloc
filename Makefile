ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAMEPT1 = libft_malloc
NAMEPT2 = .so
NAME = $(NAMEPT1)_$(HOSTTYPE)$(NAMEPT2)


FLAGS = clang -Wall -Wextra -Werror -Wuninitialized

OBJ = obj/malloc.o obj/free.o obj/realloc.o\
		obj/large.o obj/small.o obj/tiny.o\
		obj/get_new_pointer.o obj/show_alloc_mem.o\

$(NAME): $(OBJ)
		make -C libft/
		$(FLAGS) -g  -o $(NAME) $(OBJ) libft/libft.a
		ln -s $(NAME) $(NAMEPT1)$(NAMEPT2)

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
	rm -f $(NAMEPT1)$(NAMEPT2)
	
re: fclean all