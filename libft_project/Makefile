NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR =.
INC_DIR =.

# List of source files
SRC_FILE_NAMES =  ft_isalpha.c \
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

# BONUS source files
BONUS_FILE_NAMES =  ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c 

#BONUS source files names to full paths
BONUS_FILE_PATHS = $(addprefix $(SRC_DIR)/, $(BONUS_FILE_NAMES))

#Generate corresponding project file names
BONUS_OBJ_FILE_PATHS = $(BONUS_FILE_PATHS:.c=.o)

#convert source files names to full paths
SRC_FILE_PATHS	= $(addprefix $(SRC_DIR)/, $(SRC_FILE_NAMES))

#Generate corresponding project file names
OBJ_FILE_PATHS	= $(SRC_FILE_PATHS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILE_PATHS) $(BONUS_OBJ_FILE_PATHS)
	ar rcs $(NAME) $(OBJ_FILE_PATHS) $(BONUS_OBJ_FILE_PATHS)

#Pattern rule to compile individual source files to object files
$(OBJ_FILE_PATHS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BONUS_OBJ_FILE_PATHS): $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ 
	
#create rule to compile individual source files for bonus to object files
clean:
	rm -f $(OBJ_FILE_PATHS) $(BONUS_OBJ_FILE_PATHS)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJ_FILE_PATHS) $(BONUS_OBJ_FILE_PATHS)
	ar rcs $(NAME) $(OBJ_FILE_PATHS) $(BONUS_OBJ_FILE_PATHS)

re: fclean all

.PHONY: all clean fclean re bonus

#.PHONY, where we define all the targets that are not files.
#https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html
# this is for stuff like what addprefix does
# The addprefix function in a Makefile is used to prefix a string to a list of words. In the context of your Makefile, it's used to prepend the $(SRC_DIR)/ directory path to each item in the list $(BONUS_FILE_NAMES).
#
#The '$' character is used to denote variables in Makefiles. When you see '$()' within a Makefile, it's used to reference the value of a variable.
#$(SRC_DIR)/%.o : $(SRC_DIR)/%.c: This line defines the dependency relationship between source files and object files. It says that each object file depends on the corresponding C source file in the source directory.
#$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@: This is the command that is executed to build each object file.
#$(CC): This is the C compiler specified in the Makefile.
#$(CFLAGS): These are compiler flags specified in the Makefile.
#-I $(INC_DIR): This includes the directory specified in $(INC_DIR) for header files.
#-c: This flag tells the compiler to create an object file.
#$<: This is a special variable that represents the source file being compiled.
#-o $@: This specifies the output file (the object file) to be generated.
#(SRC_DIR)/%.o : $(SRC_DIR)/%.c: This is the dependency pattern. It means that any target ending in .o in the $(SRC_DIR) directory depends on a corresponding source file ending in .c in the same directory.
#-I $(INC_DIR): This flag includes the directory specified in $(INC_DIR) for header files.
#-c: This flag tells the compiler to create an object file.
#$<: This represents the source file (.c file) being compiled.
#-o $@: This specifies the output file (the object file) to be generated.
#rm -f is used to forcefully remove files without displaying error messages or asking for confirmation. It's typically used to clean up generated files.
#ar is the archive management command, and rcs are options used with ar:
#r: Replace or add files to the archive.
#c: Create the archive if it doesn't exist.
#s: Create an archive index.
#This command creates an archive file with the name specified by $(NAME) and adds the object files listed in $(OBJ_FILE_PATHS) and $(BONUS_OBJ_FILE_PATHS) to the archive. It essentially bundles the object files into a single archive file.
# re fclean all make re should first clean (fclean) and then build (all) the project. 
#.PHONY, it tells Make that the target doesn't represent a file and should always be considered out-of-date. It's often used for defining targets that perform actions other than file generation, such as all, clean, fclean, and re. In your Makefile, it's used to declare the targets that should always be executed regardless of whether a file with the same name exists.
