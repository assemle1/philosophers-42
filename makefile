# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 09:17:55 by astalha           #+#    #+#              #
#    Updated: 2023/04/14 01:17:45 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_isdigit.c linkedlist.c philo.c time.c actions.c cleaner.c parcing.c routine.c 
BONUS           =	
					
OBJS			= $(SRCS:.c=.o)
B_OBJS          = $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
NAME			= philo
NAME_B		    = Bonus/pipex

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_B): $(B_OBJS) 
	$(CC) $(FLAGS) $(B_OBJS) -o $(NAME_B)

all: $(NAME) 

bonus: $(NAME_B)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re: fclean all