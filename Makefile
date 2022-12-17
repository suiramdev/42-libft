## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: mnouchet <mnouchet>                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/10/27 13:35:58 by mnouchet          #+#    #+#             ##
##   Updated: 2022/12/17 18:51:10 by marvin           ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = libft.a

SOURCES_DIR = ./srcs
SOURCES = converters/ft_atoi.c converters/ft_itoa.c \
		  core/ft_split.c core/ft_strchr.c core/ft_strdup.c core/ft_striteri.c \
		  core/ft_strjoin.c core/ft_strlcat.c core/ft_strlcpy.c core/ft_strlen.c \
		  core/ft_strmapi.c core/ft_strncmp.c core/ft_strnstr.c core/ft_strrchr.c \
		  core/ft_strtrim.c core/ft_substr.c core/ft_tolower.c core/ft_toupper.c \
		  handlers/ft_bzero.c handlers/ft_calloc.c handlers/ft_memchr.c handlers/ft_memcmp.c \
		  handlers/ft_memcpy.c handlers/ft_memmove.c handlers/ft_memset.c \
		  verifiers/ft_isalnum.c verifiers/ft_isalpha.c verifiers/ft_isascii.c verifiers/ft_isdigit.c \
		  verifiers/ft_islower.c verifiers/ft_isprint.c verifiers/ft_isupper.c

INCLUDES_DIR = ./includes

OBJECTS = $(addprefix $(SOURCES_DIR)/, $(SOURCES:%.c=%.o))

CC = cc -Wall -Werror -Wextra

%.o: %.c
	@$(CC) -I$(INCLUDES_DIR) -c $< -o $@
	@echo "→ Compiling $<"


$(NAME): $(OBJECTS)
	@ar -rsc $@ $^
	@echo "\033[0;32m✓ READY"

clean:
	@rm -f $(OBJECTS)
	@echo "→ Removing objects"

fclean: clean
	@rm -f $(NAME)
	@echo "→ Removing binaries"

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
