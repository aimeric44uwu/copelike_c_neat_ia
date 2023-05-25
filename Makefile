##
## EPITECH PROJECT, 2022
## neat_ia
## File description:
## Makefile
##

PROGNAME		=		my_copelia

OBJ				=		$(SRC:.c=.o)

SRC				=		src/graphical_motor.c						\
						src/error_occured.c 						\
						src/create_car.c 							\
						src/init.c 									\
						src/draw_elements.c 						\
						src/close_programm.c 						\
						src/check_for_wall.c 						\
						src/event.c 								\
						                                            \
						src/utils.c 								\
						src/utils_2.c 								\



# MAKEFILE

WARNING			=		-Wall -Wextra -Wshadow

LIB_CSFML		=		-lcsfml-window -lcsfml-graphics -lcsfml-system \
						-lcsfml-audio

INCLUDE_DIR 	=		-I ./include

CFLAGS			=		$(INCLUDE_DIR) $(LIB_CSFML) $(WARNING) -lm

SRC_TEST		=		$(filter-out src/main.c,$(SRC))

CC				=		gcc -g

all: $(PROGNAME)

$(PROGNAME):	$(OBJ)
		@$(CC) $(OBJ) $(LIB_CSFML) -o $(PROGNAME) $(CFLAGS)
		@if [ -f $(PROGNAME) ]; then \
			echo -e "\033[92m\nFile succesfully compiled\n\033[0m" ; \
		fi

clean:
		@rm -f $(OBJ)

fclean:			clean
		@rm -f $(PROGNAME)

re:		fclean all
		@rm -f $(OBJ)
