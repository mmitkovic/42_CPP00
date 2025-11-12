# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 13:28:40 by mmitkovi          #+#    #+#              #
#    Updated: 2025/11/12 16:21:48 by mmitkovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= megaphone
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS	:= megaphone.cpp
OBJS	:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re