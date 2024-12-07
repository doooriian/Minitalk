CC            = cc
CFLAGS        = -Wall -Wextra -Werror
RM            = rm -f

CLIENT        = client
SERVER        = server

LIB           = includes/Libft/libft.a \
			includes/Ft_printf/libftprintf.a

LIBFT_DIR     = includes/Libft
FT_PRINTF_DIR = includes/Ft_printf

CLIENT_SRC    = srcs/mandatory/client.c
SERVER_SRC    = srcs/mandatory/server.c

CLIENT_OBJS   = $(CLIENT_SRC:.c=.o)
SERVER_OBJS   = $(SERVER_SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(LIB):
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)

$(CLIENT): $(LIB) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT)

$(SERVER): $(LIB) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
