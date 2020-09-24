# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:53:10 by qjosmyn           #+#    #+#              #
#    Updated: 2020/02/25 21:33:35 by qjosmyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qjosmyn.filler
CFLAGS = -Wall -Wextra -Werror -I libft/includes -L./libft -lft
HEADER = filler.h
SRC = distance.c filler.c token.c
LIBFT_DIR = libft/

SRC_LIB = ft_atoi.c		ft_bzero.c		ft_memccpy.c	ft_memchr.c		ft_lstmerge.c\
	  ft_memcmp.c	ft_memcpy.c		ft_memmove.c 	ft_memset.c		ft_lstremove_if.c\
	  ft_strlen.c	ft_strcmp.c		ft_isalnum.c	ft_lstqsort.c	ft_lstadd_back.c\
	  ft_strcpy.c	ft_strncpy.c	ft_strcat.c		ft_strncat.c	ft_lstfind.c\
	  ft_strlcat.c	ft_strchr.c		ft_strrchr.c	ft_strstr.c		ft_lstmap.c\
	  ft_strnstr.c	ft_strncmp.c	ft_isalpha.c	ft_isdigit.c	ft_putnbr_fd.c\
	  ft_isascii.c	ft_toupper.c	ft_tolower.c	ft_isprint.c	ft_strdup.c\
	  ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c		ft_lstswap.c\
	  ft_strclr.c	ft_striter.c	ft_striteri.c	ft_strmap.c		ft_strmapi.c \
	  ft_strequ.c	ft_strnequ.c	ft_strsub.c		ft_strjoin.c	ft_strtrim.c\
	  ft_putchar.c	ft_putendl.c	ft_putstr.c		ft_strsplit.c	ft_itoa.c\
	  ft_putnbr.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c get_next_line.c\
	  ft_lstnew.c	ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstiter.c \
	  ft_qsort.c	ft_lstsize.c	ft_lstlast.c	ft_lsti.c		ft_lstreverse.c\
	  free_table.c  ft_itoabase.c   ft_itoahex.c    ft_itoa_signed.c ft_itoadouble.c\
	  ft_stradd_front.c ft_stradd_back.c    ft_strreplace.c ft_strcat_front.c ft_strcut.c\
	  ft_twodemint.c ft_free.c printf.c

SRC_PRINTF_LST = bonus_star.c ft_kek.c fun_length.c funtypes_ubp.c parse.c set_precision_width.c\
				unixtime.c flag_hash.c ft_longarith.c funtypes_cdx_upx_o.c get_flag_sign.c\
				placeholder.c type_color.c ft_double.c fun_flags.c funtypes_sf_percent.c\
				length_bonus.c precision.c type_unixtime.c

SRC_LIB1 = $(addprefix $(LIBFT_DIR), $(SRC_LIB))
SRC_LIB2 = $(addprefix $(LIBFT_DIR)srcs_for_printf/, $(SRC_PRINTF_LST))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(SRC) $(SRC_LIB1) $(SRC_LIB2)
	make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) -I $(HEADER) $(SRC) -o $(NAME)

clean:
	make -sC $(LIBFT_DIR) clean

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re: fclean all
