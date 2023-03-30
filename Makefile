# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 22:19:57 by mnouchet          #+#    #+#              #
#    Updated: 2023/02/06 18:18:33 by mnouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

## ########################################################################## ##
#   INGREDIENTS																  ##
## ########################################################################## ##
# INCS			header file locations
#
# SRCS_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

INCS		:= includes

SRCS_DIR	:= srcs
SRCS		:= converters/ft_abs.c		\
			   converters/ft_atoi.c		\
			   converters/ft_itoa.c		\
			   converters/ft_lerp.c		\
			   converters/ft_atol.c		\
			   core/ft_split.c			\
			   core/ft_strchr.c			\
			   core/ft_strdup.c			\
			   core/ft_striteri.c		\
			   core/ft_strjoin.c		\
			   core/ft_strlcat.c		\
			   core/ft_strlcpy.c		\
			   core/ft_strlen.c			\
			   core/ft_strmapi.c		\
			   core/ft_strncmp.c		\
			   core/ft_strnjoin.c		\
			   core/ft_strnstr.c		\
			   core/ft_strnstr.c		\
			   core/ft_strrchr.c		\
			   core/ft_strtrim.c		\
			   core/ft_substr.c			\
			   core/ft_tolower.c		\
			   core/ft_toupper.c		\
			   handlers/ft_bzero.c		\
			   handlers/ft_calloc.c		\
			   handlers/ft_memchr.c		\
			   handlers/ft_memcmp.c		\
			   handlers/ft_memcpy.c		\
			   handlers/ft_memmove.c	\
			   handlers/ft_memrep.c		\
			   handlers/ft_memset.c		\
			   loaders/ft_gnl.c			\
			   loaders/ft_env.c			\
			   verifiers/ft_isalnum.c	\
			   verifiers/ft_isalpha.c	\
			   verifiers/ft_isascii.c	\
			   verifiers/ft_isdigit.c	\
			   verifiers/ft_islower.c	\
			   verifiers/ft_isprint.c	\
			   verifiers/ft_isupper.c	\
			   verifiers/ft_isspace.c	\
			   verifiers/ft_issign.c
			   

SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror	
CPPFLAGS    := $(INCS:%=-I%)

## ########################################################################## ##
#   UTENSILS																  ##
## ########################################################################## ##
# RM			force remove
# MAKEFLAGS		make flags
# DIR_UP		duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

## ########################################################################## ##
#   RECIPES																	  ##
## ########################################################################## ##
# all			default goal
# $(NAME)		link .o -> archive
# %.o			compilation .c -> .o
# clean			remove .o
# fclean		remove .o + binary
# re			remake default goal

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	echo "→ Compiling $<"
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@ar -rsc $@ $^
	echo "\033[0;32m✓ $@ READY\033[0m"

clean:
	echo "→ Removing objects"
	$(RM) $(OBJS)

fclean: clean
	echo "→ Removing binaries"
	$(RM) $(NAME)

re: fclean all

.PHONY: re
