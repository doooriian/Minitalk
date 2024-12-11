CC				  = cc
CFLAGS			  = -Wall -Wextra -Werror
RM				  = rm -f

CLIENT			  = client
SERVER			  = server
CLIENT_BONUS	  = client_bonus
SERVER_BONUS	  = server_bonus


LIB					= includes/Libft/libft.a \
					includes/Ft_printf/libftprintf.a

LIBFT_DIR			= includes/Libft
FT_PRINTF_DIR		= includes/Ft_printf

CLIENT_SRC			= srcs/mandatory/client.c
SERVER_SRC			= srcs/mandatory/server.c
CLIENT_BONUS_SRC	= srcs/bonus/client_bonus.c
SERVER__BONUS_SRC	= srcs/bonus/server_bonus.c

CLIENT_OBJS			= $(CLIENT_SRC:.c=.o)
SERVER_OBJS			= $(SERVER_SRC:.c=.o)
CLIENT__BONUS_OBJS	= $(CLIENT_BONUS_SRC:.c=.o)
SERVER__BONUS_OBJS	= $(SERVER_BONUS_SRC:.c=.o)

$(LIB):
	make -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)

$(CLIENT): $(LIB) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT)

$(SERVER): $(LIB) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER)

$(CLIENT_BONUS): $(LIB) $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIB) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(LIB) $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIB) -o $(SERVER_BONUS)

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
