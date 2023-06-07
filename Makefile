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
						                                            \
						src/init_element/init.c 					\
						src/init_element/init_text_element.c 		\
						                                            \
						src/draw_elements/draw_elements.c 			\
						src/draw_elements/draw_lidar.c  			\
						src/draw_elements/lidar_graphic.c 			\
						src/draw_elements/draw_fps.c 				\
						                                            \
						src/close_programm.c 						\
						src/check_for_wall.c 						\
						                                            \
						src/handle_events/keyboard/keyboard_pressed.c 		\
						src/handle_events/keyboard/keyboard_released.c 		\
						src/handle_events/car_command.c				\
						src/handle_events/event.c 					\
						src/handle_events/mouse.c 					\
						src/handle_events/exec_car_command/car_backward.c 	\
						src/handle_events/exec_car_command/car_forward.c 	\
						src/handle_events/exec_car_command/car_speed_max.c 	\
						src/handle_events/exec_car_command/car_speed_min.c 	\
						src/handle_events/exec_car_command/current_speed.c 	\
						src/handle_events/exec_car_command/current_wheel.c 	\
						src/handle_events/exec_car_command/get_info_lidar.c \
						src/handle_events/exec_car_command/info_simtime.c \
						src/handle_events/exec_car_command/sim_not_started.c \
						src/handle_events/exec_car_command/start_simulation.c \
						src/handle_events/exec_car_command/stop_simulation.c \
						src/handle_events/exec_car_command/unknown_command.c \
						src/handle_events/exec_car_command/wheel_dir.c \
						                                            \
																	\
						src/actions.c 								\
						src/read_input.c   							\
						                                            \
						src/utils_folder/utils.c 					\
						src/utils_folder/utils_2.c 					\



# MAKEFILE

WARNING			=		-Wall -Wextra -Wshadow

LIB_CSFML		=		-lcsfml-window -lcsfml-graphics -lcsfml-system \
						-lcsfml-audio

INCLUDE_DIR 	=		-I ./include

CFLAGS			=		$(INCLUDE_DIR) $(LIB_CSFML) $(WARNING) -lm -lncurses

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
