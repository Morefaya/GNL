CFLAG = -Wall -Wextra -Werror
H_LIB = libft/includes

.PHONY: test_gnl

all: lib gnl

lib:
	make -C libft/ fclean && make -C libft/
	
gnl:
	clang $(CFLAG) -I $(H_LIB) -o get_next_line.o -c -g -ggdb get_next_line.c
	clang $(CFLAG) -I $(H_LIB) -o main.o -c -g -ggdb main.c
	clang -o test_gnl main.o get_next_line.o -I $(H_LIB) -L libft -lft

clean:
	rm -rf *.o

fclean: clean
	rm -rf test_gnl

re: fclean all
