NAME			=	EmpireEarth
CC				= clang
CFLAGS 		= -Wall -Werror -Wextra
RAYLIB		=	-I/usr/local/include -L/usr/local/lib -lraylib
LIBS 			= -lGL -lm -lpthread -ldl -lrt -lX11
SRC				=	./src/main.c	\
						./src/features/camera/camera.c
OBJ_SRC		=	$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $^ -o $(NAME) $(RAYLIB) $(CFLAGS) $(LIBS)

clean:
	rm -rf $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
