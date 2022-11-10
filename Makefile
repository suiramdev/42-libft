## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/10/27 13:35:58 by mnouchet          #+#    #+#             ##
##   Updated: 2022/11/10 10:55:28 by mnouchet         ###   ########.fr       ##
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
		  ft_split.c ft_itoa.c ft_strmapi.c

INCLUDES = libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rsc $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS)

.PHONY: all fclean 
