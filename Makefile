## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/10/27 13:35:58 by mnouchet          #+#    #+#             ##
##   Updated: 2022/11/12 15:56:45 by mnouchet         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = libft.a

SOURCES = ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		  ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_isupper.c \
		  ft_islower.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
		  ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c \
		  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SOURCES_BONUS = ft_lstnew.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rsc $@ $^

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar -rsc $(NAME) $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS)

soclean: fclean
	rm -rf a.out libft.so

.PHONY: all bonus clean fclean re so soclean
