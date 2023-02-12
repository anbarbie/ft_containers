# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:26:14 by antbarbi          #+#    #+#              #
#    Updated: 2023/02/12 15:24:46 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_containers

INCLUDES		= ./includes
SRCS			= ./srcs/main.cpp
OBJS			= $(SRCS:.cpp=.o)
HEADERS			= ft_containers.hpp random_access_iterator.hpp vector.hpp
HEADER_FILES	= $(addprefix includes/, $(HEADERS))


CXX				= c++

CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(HEADER_FILES)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)


.PHONY:	all clean fclean re