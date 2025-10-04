NAME    = pipex
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     = pipex.c \
          transactions/close_multi.c transactions/create_pipe.c transactions/execute_cmd.c \
          transactions/find_cmd_path.c transactions/first_process.c transactions/get_cmd_path.c \
          transactions/open_input_file.c transactions/open_output_file.c transactions/second_process.c \
          transactions/split_cmd.c \
          utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c \
          utils/ft_strncmp.c utils/ft_substr.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
