NAME = asm

FILEC =	asm.c\
		add_lable_list.c\
		check_op_fork.c\
		create_file_cor.c\
		create_lable_arg.c\
		delete_list.c\
		delete_opr.c\
		get_arg_opr.c\
		instraction.c\
		operators.c\
		read_comment_champion.c\
		three_char_operator.c\
		write_big_endian.c\
		write_header.c

DIRSRC = ./source/

OBJ = $(FILEC:.c=.o)

SRC = $(addprefix $(DIRSRC), $(FILEC))

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) $(HFILES) -c $(SRC)
	gcc $(FLAGS) $(OBJ) -L ./libft -lftprintf -o $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)
	
re: fclean all
	make re -C ./libft
