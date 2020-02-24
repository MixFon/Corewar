# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: widraugr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 13:07:44 by widraugr          #+#    #+#              #
#    Updated: 2020/02/24 13:20:58 by widraugr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIBDIR = ./libft


FILE_C = main.c\
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
		 write_code_str.c\
		 write_header.c

FLAGS = -Wall -Wextra -Werror -I libft -I include 


FLIB = -L ./libft -lftprintf 

DIRC = ./source/

LIB = ./libft/libftprintf.a

#$(LIB): ./libft/*.c
#	make -C ./libft

VPATH = $(DIROBJ)

DIROBJ = ./obj/

OBJ = $(addprefix $(DIROBJ), $(FILE_C:.c=.o))

all : $(NAME) 

$(NAME): $(DIROBJ) $(OBJ) 
	make -C $(LIBDIR)
	gcc $(FLAGS) $(OBJ) $(FLIB) $(FMLXLIB) -o $(NAME)

$(DIROBJ)%.o : $(DIRC)%.c
	gcc -g $(FLAGS) -c $< -o $@

$(DIROBJ):
	mkdir -p $(DIROBJ)

clean:
	/bin/rm -rf $(DIROBJ)
	
fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBDIR)
	
re: fclean all 
