##
## Makefile for 103architect in /home/VEYSSI_B/rendu/103architect
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Nov 30 13:09:03 2015 Baptiste veyssiere
## Last update Mon Nov 30 17:29:08 2015 Baptiste veyssiere
##

NAME	= 103architect

SRCS	= case.c \
	get_args_call_function.c

OBJS	= $(SRCS:.c=.o)

$(NAME):
	cc -c $(SRCS)
	cc -o $(NAME) $(OBJS) -lm

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bis: fclean all
	rm -f $(OBJS);
