# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 14:12:20 by youkim            #+#    #+#              #
#    Updated: 2021/12/21 09:44:31 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Target & FLAGS =====
NAME     := libft.a

CC       := gcc
CFLAGS   := -Wall -Wextra -Werror #-std=c99
DFLAGS	 := #-g3 #-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes \
			--suppressions=./macos.supp
AR       := ar -rcs
RM       := rm -f

PRE      := src/
INC      := -I includes/

HGEN     := hgen
TEST     := test

# ===== Packages =====
PKGS     := math string system linked

mathV    := \
	comp_num comp_char comp_val		\
	conv ybinary yqsort yvector

systemV  := \
	yexit yalloc ysyscall ylog ygnl

stringV  := \
	new_ystr new_ystrjoin new_ysplit\
	del_ystr mod_ystr comp_ystr		\

linkedV  := \
	alloc_ydeque mod_ydeque			\
	new_ylist comp_ylist 			\
#new_ydeque

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),			\
		$(foreach file, $($(pkg)V),	\
			$(PRE)y$(pkg)/$(file).c	\
		)							\
	)
endef

# ===== Sources & Objects & Includes =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Rules =====
%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@$(call log, V, Archived Object files,\
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
red: fclean docs all
ald: docs all

docs:
	@$(call log, V, Generating Docs,...)
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I includes/y$$p.h src/y$$p;\
		done
	@$(call log, G, Updated Docs)

testdry: docs all
	@$(call log, Y, Preparing Test,...)
	@$(CC) $(DFLAGS) $(INC) $(NAME) $(TEST).c -o test
	@$(call log, G, Compiled Test)

test: testdry cls
	@$(call log, Y, Running Test,...)
	@./$(TEST)
	@$(call log, G, Ended Test)

leak: docs all cls
	@$(call log, Y, Running Leak Test,...)
	@$(CC) $(DFLAGS) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test
#$(shell ruby -e "puts (1..11).to_a.shuffle.join  (' ')")
leaksup: docs all cls
	@echo "$(Y)<Creating Leak Suppressions>$(E)"
	@$(CC) $(DFLAGS) $(INC) $(NAME) tests/test.c -o test
	@valgrind $(VFLAGS) --gen-suppressions=yes ./test
	@rm test

.PHONY: all re clean fclean test red docs

# ===== Miscs =====
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
CNAM ?= for $(CU)$(strip $(NAME)$(E))

define log
	printf "$($(strip $(1)))<$(strip $(2))\
			$(CNAM)$($(strip $(1)))$(strip $(3))$($(strip $(1)))>$(E)\n"
endef

