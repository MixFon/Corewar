NAME = asm

FILEC =	main.c\
		add_lable_list.c\
		check_op_or_xor_and_arg.c\
		check_op_st_arg.c\
		delete_list.c\
		four_char_operator.c\
		init_agr.c\
		isprint_char.c\
		read_comment_champ.c\
		read_dir_arg.c\
		read_name_comment.c\
		search_lbl.c\
		write_header.c\
		write_code_str.c

DIRSRC = ./source/

OBJ = $(FILEC:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(DIRSRC), $(FILEC))

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(FLAGS) -c $(SRC)
		gcc $(FLAGS) $(OBJ) -L ./libft -lftprintf -o $(NAME)

clean:
		make clean -C ./libft
			/bin/rm -f $(OBJ)

fclean: clean
		#make fclean -C ./libft
			/bin/rm -f $(NAME)
				
re: fclean all
		#make re -C ./libft
