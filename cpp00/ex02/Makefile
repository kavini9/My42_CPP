# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 19:45:48 by wweerasi          #+#    #+#              #
#    Updated: 2025/08/26 19:52:32 by wweerasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp \
	Account.cpp \

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