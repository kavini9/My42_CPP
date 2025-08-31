# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 19:42:01 by wweerasi          #+#    #+#              #
#    Updated: 2025/08/28 16:39:52 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp \
	Harl.cpp \

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