# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 11:47:12 by emflynn           #+#    #+#              #
#    Updated: 2025/02/26 16:15:51 by emflynn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libft.a

SRC_DIR :=		./src
OBJ_DIR :=		./obj

SRC_FILES :=	ft_abs.c \
				ft_all.c \
				ft_any.c \
				ft_atoi.c \
				ft_binary_tree_init.c \
				ft_binary_tree_newnode.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_getline.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_iscntrl.c \
				ft_isdigit.c \
				ft_isgraph.c \
				ft_islower.c \
				ft_isprint.c \
				ft_ispunct.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_isxdigit.c \
				ft_itoa.c \
				ft_list_append.c \
				ft_list_appendnode.c \
				ft_list_clear.c \
				ft_list_delnode.c \
				ft_list_destroy.c \
				ft_list_init.c \
				ft_list_iter.c \
				ft_list_map.c \
				ft_list_newnode.c \
				ft_list_pop.c \
				ft_list_prepend.c \
				ft_list_prependnode.c \
				ft_list_removenode.c \
				ft_list_size.c \
				ft_max.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memrchr.c \
				ft_memset.c \
				ft_min.c \
				ft_nbrlen.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putstr_fd.c \
				ft_putstr.c \
				ft_split_destroy.c \
				ft_split.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strcspn.c \
				ft_strdup.c \
				ft_strends.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strnlen.c \
				ft_strnstr.c \
				ft_strrange.c \
				ft_strrchr.c \
				ft_strspn.c \
				ft_strstarts.c \
				ft_strstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_umax.c \
				ft_umin.c
SRCS :=			$(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS :=			$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

PRINTF_SRC_DIR :=	$(SRC_DIR)/ft_printf
PRINTF_OBJ_DIR :=	$(OBJ_DIR)/ft_printf

PRINTF_SRC_FILES :=	ft_printf.c	\
					ft_dprintf.c \
					conversion_char.c \
					conversion_float.c \
					conversion_hex.c \
					conversion_int.c \
					conversion_str.c \
					conversion_uint.c \
					main_affixing.c \
					main_args.c \
					main_formatting.c \
					main_routing.c \
					main_saving.c \
					utils_affixing.c \
					utils_bit.c \
					utils_float.c \
					utils_number.c \
					utils_options.c \
					utils_parsing.c \
					utils_precision.c \
					utils_printing.c \
					utils_rounding.c \
					utils_routing.c \
					utils_string.c \
					utils_wchar.c \
					utils_wstr.c
PRINTF_SRCS := 		$(addprefix $(PRINTF_SRC_DIR)/,$(PRINTF_SRC_FILES))
PRINTF_OBJS :=		$(PRINTF_SRCS:$(PRINTF_SRC_DIR)/%.c=$(PRINTF_OBJ_DIR)/%.o)

INCLUDE_DIR :=	./include

CC :=			cc
CFLAGS :=		-Wall -Wextra -Werror -I $(INCLUDE_DIR)
AR :=			ar
ARFLAGS :=		rcs
MKDIR :=		mkdir -p
RM :=			rm -f

ifeq ($(OS),Windows_NT)
    UNAME :=	Windows
else
    UNAME :=	$(shell uname)
endif

ifeq ($(UNAME),Darwin)
    CFLAGS +=	-D MACOS
endif

$(NAME):		$(OBJS) $(PRINTF_OBJS)
				$(AR) $(ARFLAGS) $@ $^

$(PRINTF_OBJ_DIR):
						$(MKDIR) $@

$(PRINTF_OBJ_DIR)/%.o:	$(PRINTF_SRC_DIR)/%.c | $(PRINTF_OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				$(MKDIR) $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

clean:
				$(RM) -R $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
