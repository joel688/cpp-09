NAME		= RPN

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -g3 -std=c++98

SRCS		=	./main.cpp\
				./Class/RPN/rpn.cpp\

OBJS		=		$(SRCS:.cpp=.o)

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CXX)  $(CXXFLAGS) $(OBJS) -o  $(NAME)

clean		:
					rm -rf $(OBJS)

fclean		:		clean
					rm -rf $(NAME)

re			:		fclean all

.PHONY		:		all	clean	fclean	re

