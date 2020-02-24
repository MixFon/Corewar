# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: widraugr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 13:07:44 by widraugr          #+#    #+#              #
#    Updated: 2020/02/24 18:58:41 by widraugr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

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

MINI_LIB_C = ft_atoi.c\
		 ft_isalpha.c\
		 ft_isdigit.c\
		 ft_isprint.c\
		 ft_memccpy.c\
		 ft_memset.c\
		 ft_putchar.c\
		 ft_putchar_fd.c\
		 ft_putendl.c\
		 ft_putendl_fd.c\
		 ft_putnbr_fd.c\
		 ft_putstr.c\
		 ft_putstr_fd.c\
		 ft_strcat.c\
		 ft_strchr.c\
		 ft_strcmp.c\
		 ft_strdel.c\
		 ft_strdup.c\
		 ft_strjoin.c\
		 ft_strlen.c\
		 ft_strncmp.c\
		 ft_strncpy.c\
		 ft_strnew.c\
		 ft_strstr.c\
		 ft_strsub.c\
		 get_next_line.c\
		 sys_err.c

FLAGS = -Wall -Wextra -Werror -I include

DIRC = ./source/

DIR_MINI_LIB = ./source/mini_libft/

VPATH = $(DIROBJ)

DIROBJ = ./obj/

OBJ = $(addprefix $(DIROBJ), $(FILE_C:.c=.o))

OBJ_MINI_LIB = $(addprefix $(DIROBJ), $(MINI_LIB_C:.c=.o))

all : $(NAME)

$(NAME): $(DIROBJ) $(OBJ_MINI_LIB) $(OBJ) 
	gcc $(FLAGS) $(OBJ)  $(OBJ_MINI_LIB) $(FLIB) $(FMLXLIB) -o $(NAME)

$(DIROBJ)%.o : $(DIRC)%.c
	gcc $(FLAGS) -c $< -o $@

$(DIROBJ)%.o : $(DIR_MINI_LIB)%.c
	gcc $(FLAGS) -c $< -o $@

$(DIROBJ):
	mkdir -p $(DIROBJ)

clean:
	/bin/rm -rf $(DIROBJ)
	
fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all 
