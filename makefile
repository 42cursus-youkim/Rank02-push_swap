# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/11 19:41:53 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := push_swap

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -g3\
			#-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address" -g
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --show-reachable=no \
			# --suppressions=./libft/macos.supp \
			--suppressions=./mlx.supp
VSFLAGS  := --show-reachable=yes --error-limit=no --gen-suppressions=all \
			# --log-file=./mlx.supp
RM       := rm -rf

PRE      := src/
INC      := -I includes/ -I libft/includes
LIBFT    := libft/libft.a
HGEN     := hgen

# ===== Packages =====
PKGS     := engine opers

engineV  := \
	push_swap init_engine func_engine
opersV   := \
	opers manager manager_utils

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

define build_library
	@echo "$(Y)<Building Library>$(E)"
	@make all -C libft/
	@echo "$(G)<Built Library>$(E)"
endef

# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Recipes =====
%.o: %.c
	@echo  $(subst .c,.o, $(lastword $(subst /, , $<)))
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(call build_library)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLX) -o $@ $^
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

bonus: all

clean:
	@$(RM) $(OBJ)
	@echo "$(Y)<Cleaned Object files>$(E)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(Y)<Cleaned Names>$(E)"

re: fclean all

# ===== Custom Recipes =====
red: fclean docs all
ald: docs all

docs:
	@echo "$(G)<Generating Documentation...>$(E)"
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I includes/$$p.h src/$$p;\
		done
	@echo "$(G)<Updated Docs>$(E)"

test: docs all
	@echo "$(Y)<Running Test>$(E)"
	@./$(NAME)
	@echo "$(G)<Ended Test>$(E)"

leak: docs all
	@echo "$(Y)<Running Leak Test>$(E)"
	@colour-valgrind $(VFLAGS) ./$(NAME)

leaksup: docs all
	@echo "$(Y)<Creating Leak Suppressions>$(E)"
	@valgrind $(VFLAGS) --gen-suppressions=all ./$(NAME)

.PHONY: all re clean fclean test red docs

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;92m
V ?= \033[0;35m
E ?= \033[0m
