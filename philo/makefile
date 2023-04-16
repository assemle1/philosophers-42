# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 09:17:55 by astalha           #+#    #+#              #
#    Updated: 2023/04/16 08:09:07 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_isdigit.c linkedlist.c philo.c time.c actions.c cleaner.c parcing.c routine.c 
					
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
NAME			= philo

.PHONY: all clean fclean re

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all