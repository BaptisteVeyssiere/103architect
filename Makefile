##
## Makefile for 103architect in /home/VEYSSI_B/rendu/103architect
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Nov 30 13:09:03 2015 Baptiste veyssiere
## Last update Mon Nov 30 14:52:38 2015 Baptiste veyssiere
##

NAME	= 103architect

SRCS	= 103architect.c

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
