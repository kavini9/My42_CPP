# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 18:21:04 by wweerasi          #+#    #+#              #
#    Updated: 2025/09/26 18:25:33 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp \
	Fixed.cpp \
	Point.cpp \
	bsp.cpp
	 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re