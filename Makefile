CC= \
	cc
CFLAGS= \
	-Wall \
	-Wextra \
	-Werror \
	-g
SRCS= \
	./push_swap.c \
	./stack0.c \
	./stack1.c \
	./lang0.c \
	./lang1.c \
	./lang2.c \
	./lang3.c \
	./sort0.c \
	./sort1.c \
	./simulate0.c \
	./utils.c
OBJS= \
	$(SRCS:.c=.o)
LIBFT= \
	./libft/libft.a
LDFLAGS= \
	-L ./libft
LFLAGS= \
	-lft
NAME= \
	push_swap	

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LFLAGS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

.PHONY: clean fclean re

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
