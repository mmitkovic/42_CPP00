# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 13:16:06 by mmitkovi          #+#    #+#              #
#    Updated: 2025/11/12 16:21:41 by mmitkovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := phonebook

CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := main.cpp \
           Contact.cpp \
           PhoneBook.cpp \
           Utils.cpp

OBJS    := $(SRCS:.cpp=.o)

DEPS    := Contact.hpp PhoneBook.hpp Utils.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
