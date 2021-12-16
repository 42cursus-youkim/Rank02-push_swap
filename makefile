# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/16 11:52:24 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := push_swap

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror
RM       := rm -rf

PRE      := src/
INC      := -I includes/ -I libft/includes
LIBFT    := libft/libft.a

# ===== Test & Debugging =====
DFLAGS	 := -g3 -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --show-reachable=no \
			--suppressions=./libft/macos.supp
VSFLAGS  := --show-reachable=yes --error-limit=no --gen-suppressions=all \
			# --log-file=./mlx.supp

HGEN     := hgen #../hgen/src/run.py
TPARAM   := $(shell ruby -e "puts (1..16).to_a.shuffle.join(' ')")
#2 16 4 6 3 14 1 11 15 5 7 12 10 9 8 13
TEST	 := ./$(NAME) $(TPARAM)
# ===== Packages =====
PKGS     := engine utils quicksort

engineV    := push_swap engine checks #TODO: remove
utilsV     := opers opers_util visualize
quicksortV := smolsort quicksort number_utils quicksort_utils #partition

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)$(pkg)/$(file).c\
		)\
	)
endef

define build_library
	@$(call log, G, Building $(CU)$(LIBFT)$(V))
	@make all -C libft/ DFLAGS="$(DFLAGS)"
	@$(call log, G, Built $(CU)$(LIBFT)$(V))
endef

# ===== Sources & Objects & Includes =====
SRC      = $(call choose_modules, $(PKGS))
OBJ      = $(SRC:%.c=%.o)

# ===== Rules =====
%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	@$(call build_library)
	@$(CC) $(CFLAGS) $(INC) -o $@ $^
	@$(call log, V, Linked Object files,\
		\n\twith flag $(R)$(DFLAGS)$(E)$(CFLAGS))
	@echo "$(G)<<$(NAME)>>$(E)"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(call log, R, Cleaned Object files)

fclean: clean
	@$(RM) $(NAME)
	@$(call log, R, Cleaned Names)

re: fclean all

# ===== Custom Rules =====
red: fclean docs all cls
ald: docs all cls

docs:
	@$(call log, V, Generating Docs,...)
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I includes/$$p.h src/$$p;\
		done
	@$(call log, G, Updated Docs)

test: docs all cls
	@$(call log, Y, Running Test, \n\twith param $(R)$(TPARAM)$(E))
	@$(TEST)
	@$(call log, G, Ended Test)

viz: docs all cls
	@$(call log, Y, Running Visual Test, \n\twith param $(R)$(TPARAM)$(E))
	@python3 ./pyviz.py $(TPARAM)
	@$(call log, G, Ended Visual Test)

leak: docs all cls
	@$(call log, Y, Running Leak Test,...)
	@colour-valgrind $(VFLAGS) $(TEST)

supp: docs all cls
	@$(call log, Y, Creating Leak Suppressions,...)
	@valgrind $(VFLAGS) --gen-suppressions=all $(TEST)

.PHONY: all re clean fclean test red docs

# ===== Colors =====
cls:
	@set -e; clear

R  ?= \033[0;91m
WU ?= \033[4;37m
C  ?= \033[0;96m
CU ?= \033[4;36m
Y  ?= \033[0;33m
YU ?= \033[4;33m
G  ?= \033[0;92m
V  ?= \033[0;35m
E  ?= \033[0m
CNAM ?= for $(YU)$(strip $(NAME)$(E))

define log
	printf "$($(strip $(1)))<$(strip $(2))\
			$(CNAM)$($(strip $(1)))$(strip $(3))$($(strip $(1)))>$(E)\n"
endef
