# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlow <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:14:15 by mlow              #+#    #+#              #
#    Updated: 2023/11/29 16:11:30 by mlow             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = ./libft_project/libft.a

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
SRC_DIR =.
OTHER_SRC_DIR = ./libft_project
INC_DIR =.

# ************************************************************************** */
#	SOURCE                                                               */
# ************************************************************************** */
#List of SOURCE(SRC) files
SRC_FILE_NAMES = pipex.c \
		utility_pipex.c\
		
#List of OTHER source files
OTHER_SRC_FILE_NAMES = ft_isalpha.c \
				  ft_isdigit.c \
				  ft_isalnum.c \
				  ft_isascii.c \
				  ft_isprint.c \
				  ft_strlen.c \
				  ft_memset.c \
				  ft_bzero.c \
				  ft_memcpy.c \
				  ft_memmove.c \
				  ft_strlcpy.c \
				  ft_strlcat.c \
				  ft_toupper.c \
				  ft_tolower.c \
				  ft_strchr.c \
				  ft_strrchr.c \
				  ft_strncmp.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_strnstr.c \
				  ft_atoi.c \
				  ft_calloc.c \
				  ft_strdup.c \
				  ft_substr.c \
				  ft_strjoin.c \
				  ft_strtrim.c \
				  ft_split.c \
				  ft_itoa.c \
				  ft_strmapi.c \
				  ft_striteri.c \
				  ft_putchar_fd.c \
				  ft_putstr_fd.c \
				  ft_putendl_fd.c \
				  ft_putnbr_fd.c \
				 ft_lstnew.c \
				 ft_lstadd_front.c \
				 ft_lstsize.c \
				 ft_lstlast.c \
				 ft_lstadd_back.c \
				 ft_lstdelone.c \
				 ft_lstclear.c \
				 ft_lstiter.c \
				 ft_lstmap.c 


#List of TEST files (DETELE/COMMENT LATER)
#TEST_FILE_NAMES = testcase.c

# ************************************************************************** */
#	FILE_LOCATION                                                        */
# ************************************************************************** */
SRC_FILE_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILE_NAMES))
OTHER_SRC_FILE_PATHS = $(addprefix $(OTHER_SRC_DIR)/, $(OTHER_SRC_FILE_NAMES))

#List of TEST files (DETELE/COMMENT LATER)
#TEST_FILE_PATH = $(addprefix $(SRC_DIR)/, $(TEST_FILE_NAMES))

OBJ_FILE_PATHS = $(SRC_FILE_PATHS:.c=.o)
OTHER_OBJ_FILE_PATHS = $(OTHER_SRC_FILE_PATHS:.c=.o)

# ************************************************************************** */
#	RULES                                                                */
# ************************************************************************** */
all: $(NAME) $(LIBFT)

$(NAME): $(OBJ_FILE_PATHS) $(OTHER_OBJ_FILE_PATHS)
	$(CC) $(CFLAGS) $(OBJ_FILE_PATHS) $(OTHER_OBJ_FILE_PATHS) -o $(NAME)

$(LIBFT): 
	make -C $(OTHER_SRC_DIR)

$(OBJ_FILE_PATHS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OTHER_OBJ_FILE_PATHS): $(OTHER_SRC_DIR)/%.o : $(OTHER_SRC_DIR)/%.c 
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

#Creating rules to compile individual source files for bonus to object files
clean: 
	rm -f $(OBJ_FILE_PATHS) $(OTHER_OBJ_FILE_PATHS)

#clear .o files including static library $(NAME)
fclean: clean
	rm -f $(NAME) $(LIBFT)

#clean files and remake "all"
re: fclean all

.PHONY: all clean fclean re

#List of TEST files (DETELE/COMMENT LATER ALL 3 of them)
#test: $(TEST_FILE_PATH) $(SRC_FILE_PATHS)
#	$(CC) $(CFLAGS) -I $(INC_DIR) $^
#	echo $(OBJ_FILE_PATHS)
