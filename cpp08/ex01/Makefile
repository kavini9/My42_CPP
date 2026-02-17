# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/01 21:27:14 by wweerasi          #+#    #+#              #
#    Updated: 2026/02/17 22:36:39 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  span
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp \
	Span.cpp

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
