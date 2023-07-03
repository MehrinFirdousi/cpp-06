# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 18:46:52 by mfirdous          #+#    #+#              #
#    Updated: 2023/06/12 18:47:30 by mfirdous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	identify

SRCS	=	Utils.cpp main.cpp

OBJS	=	${SRCS:.cpp=.o}

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

${NAME}:	${OBJS}
			${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}
clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re