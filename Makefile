# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:26:14 by antbarbi          #+#    #+#              #
#    Updated: 2023/02/09 16:57:07 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_containers

INCLUDES		= ./includes
SRCS			= ./srcs/main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++

CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): includes/random_access_iterator.hpp

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)


.PHONY:	all clean fclean re