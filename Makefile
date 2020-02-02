##
## EPITECH PROJECT, 2018
## makefil
## File description:
## do useful things
##

#---------MESSAGE---------#

GRAS = \033[1m

BACK = \033[0m

ROUGE = \033[31;1m

BLEU = \033[34;1m

#---------FLAG---------#

SFML = -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window 

MATH = -lm

FLAG = -Wall -Wextra -Werror

VALGRIND = -g3

INCLUDE = -I SRC/include

RENAME = -o $(NAME)

FLAGS = $(SRC) $(SFML) $(VALGRIND) $(RENAME)

#---------FILES---------#

SRC =	SRC/main.cpp
NAME = repareMyGameJam

#---------RULES---------#

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(BLEU)[$(ROUGE) MAKEFILE $(BLEU)]$(BACK) $(GRAS)Compilation in progress..."
	@sleep 0.4s
	@echo -e "$(BLEU)[$(ROUGE) MAKEFILE $(BLEU)]$(BACK) $(GRAS)Compilation of $(NAME)"
	@sleep 0.4s
	@$(foreach var,$(SRC), echo -e "$(BLEU)[$(ROUGE) MAKEFILE $(BLEU)]$(BACK) $(GRAS)Compilation of" $(var); sleep 0.5s;)
	@g++ $(FLAGS)
	@echo -e "$(BLEU)[$(ROUGE) MAKEFILE $(BLEU)]$(BACK) $(GRAS)Compilation done !"

clean:
	@rm -f $(OBJ)
	@rm -rf objects/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

start:
	@echo -e "$(BLEU)[$(ROUGE) MAKEFILE $(BLEU)]$(BACK) $(GRAS)Launch with Makefile !"
	@./$(NAME)