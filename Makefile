PATH_BIN =	bin
NAME =		psh

SRC =		src/Main.cpp \
		src/Environment.cpp \
		src/Prompt.cpp \
		src/Shell.cpp
OBJ =		$(SRC:.cpp=.o)

CXX =		g++
CXXFLAGS +=	-std=c++11 -O0
CXXFLAGS +=	-Wall -Wextra
CXXFLAGS +=	-I inc/

$(NAME):	$(OBJ)
		mkdir -p $(PATH_BIN)
		$(CXX) -o $(PATH_BIN)/$(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		rm -vf $(OBJ)

fclean:		clean
		rm -vf $(PATH_BIN)/$(NAME)

re:		fclean all

.PHONY:		all clean fclean re
