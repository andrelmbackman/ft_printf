NAME =  libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ./src/conversion.c\
	./src/conversion2.c\
	./src/flags.c\
	./src/insert_width.c\
	./src/itoa_base.c\
	./src/length.c\
	./src/lib1.c\
	./src/lib2.c\
	./src/numbers.c\
	./src/as_parse.c\
	./src/parse.c\
	./src/strings.c\
	./src/ultoa_base.c\
	./src/utilities.c\
	./src/utilities2.c

OBJS = $(SRCS:.c=.o)

INCL = -I ./includes

all: $(NAME)

$(NAME): $(SRCS)
	@gcc $(FLAGS) $(INCL) -c $(SRCS) ft_printf.c
	@ar rc $(NAME) *.o
	ranlib $(NAME)
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all