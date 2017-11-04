NAME = fillit

SRC = srcs/error_checker.c \
	  srcs/main.c \
	  srcs/find_solution.c \
	  srcs/xy_map.c \
	  includes/libft/ft_bzero.c \
	  includes/libft/ft_putchar.c \
	  includes/libft/ft_putendl.c \
	  includes/libft/ft_strcpy.c \
	  includes/libft/ft_strdup.c \
	  includes/libft/ft_strlen.c \
	  includes/libft/ft_strndup.c \
	  includes/libft/ft_strnew.c \
	  includes/libft/ft_strsplit.c \
	  includes/libft/ft_strsub.c \
	  includes/libft/ft_strncpy.c \

HEADER = srcs/fillit.h \
		 includes/libft/libft.h \

FLAGS = -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o fillit $(OBJ)

%.o: %.c
	gcc -o $@ -c $^

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
