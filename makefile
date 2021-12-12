# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/12 11:13:41 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := push_swap

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror\
			#-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
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
	echo "debug is < $(DEBUG) >"
	@$(call log, $(V), Builing Library, ...)
	@make all -C libft/ DEBUG="$(DEBUG)"
	@$(call log, $(G), Built Library)
endef
# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Recipes =====
%.o: %.c
	@echo  $(subst .c,.o, $(lastword $(subst /, , $<)))
	@$(CC) $(CFLAGS) $(INC) $(DEBUG) -c -o $@ $<

$(NAME): $(OBJ)
	echo $(CFLAGS)
	@$(call build_library)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLX) -o $@ $^
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

color:
	@$(call log, Y, abc)

bonus: all

clean:
	@$(RM) $(OBJ)
	@$(call log, $(V), Cleaned Object files)

fclean: clean
	@$(RM) $(NAME)
	@$(call log, $(Y), Cleaned Names)

re: fclean all

# ===== Custom Recipes =====
red: fclean docs all
ald: docs all

debug: DEBUG = -g
debug: all

docs:
	@$(call log, $(V), Generating Docs,...)
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I includes/$$p.h src/$$p;\
		done
	@$(call log, $(G), Updated Docs)

test: docs all
	@$(call log, $(Y), Running Test,...)
	@./$(NAME)
	@$(call log, $(G), Ended Test)

leak: docs all
	@$(call log, $(Y), Running Leak Test,...)
	@colour-valgrind $(VFLAGS) ./$(NAME)

leaksup: docs all
	@$(call log, $(Y), Creating Leak Suppressions,...)
	@valgrind $(VFLAGS) --gen-suppressions=all ./$(NAME)

.PHONY: all re clean fclean test red docs debug

# ===== Colors =====
Y ?= \033[0;33m
G ?= \033[0;92m
V ?= \033[0;35m
E ?= \033[0m
CNAM ?= for $(Y)$(strip $(NAME)$(E))

define log
	printf "$($(strip $(1)))<$(strip $(2))\
			$(CNAM)$($(strip $(1)))$(strip $(3))>$(E)\n"
endef