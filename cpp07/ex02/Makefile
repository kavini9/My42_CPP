# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 22:05:32 by wweerasi          #+#    #+#              #
#    Updated: 2026/02/01 17:43:25 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  array
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp

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