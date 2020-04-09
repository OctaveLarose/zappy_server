# EPITECH PROJECT, 2018
# PSU_zappy_2018
# File description
# Makefile for zappy

NAME_SERV	=	zappy_server

INC			=	-I include

CFLAGS		+=	-W -Wall -Wextra $(INC) -lm
#CFLAGS		+= -g

LDFLAGS		=	-lcriterion -lgcov

CC			=	gcc

RM			=	rm -f

### SERVER
SRC_DIR_SERV	=	server/

SRC_SERV_MAIN	=	main.c

SRC_SERV_COMMON	=	run_zappy.c							\
					get_args/get_args.c					\
					get_args/options_func.c				\
					get_args/options_names_func.c		\
					init/zappy.c						\
					init/server.c						\
					init/game/game.c					\
					init/game/world.c					\
					init/game/link_tiles.c				\
					init/game/teams.c					\
					clock/clock_tick.c					\
					clock/check_for_timeouts.c			\
                    tools/usage.c						\
                    tools/error/int.c					\
                    tools/error/ptr.c					\
                    tools/error/print.c					\
                    tools/array_tools.c					\
                    tools/buffer.c						\

SRC_SERV_NETWORK=	network/select_server.c				\
                    network/rfds/manage_rfds.c			\
                    network/rfds/handle_client.c		\
                    network/rfds/give_player_to_client.c\
                    network/rfds/parse_command.c		\
                    network/wfds/set_wfds.c				\
                    network/wfds/manage_wfds.c			\
                    network/wfds/manage_wfds_ai.c		\
                    network/wfds/manage_wfds_graph.c	\
                    network/client/accept.c				\
                    network/client/create.c				\
                    network/client/add.c				\
                    network/client/get.c				\
                    network/client/delete.c				\
                    network/client/reset_client_timer.c	\
                    network/send/respond_to_client.c	\
                    network/send/send_info_to_graphical.c\
                    network/send/add_to_init_graph_response.c\
                    network/send/send_init_info_to_graph.c\
                    network/recv/recv_client_info.c		\
                    circular_buffer/init_buffer.c		\
                    circular_buffer/add_to_buffer.c		\
                    circular_buffer/read_from_buffer.c	\
                    circular_buffer/has_command.c		\

SRC_SERV_GAME	=	game/update/update_game.c			\
       				game/update/set_player_command.c	\
       				game/update/execute_player_commands.c\
       				game/update/check_if_game_won.c		\
       				game/map/spawn_food.c				\
       				game/map/get_tile.c					\
       				game/map/add_player_to_tile.c		\
       				game/map/move_player_to_tile.c		\
       				game/map/get_player.c				\
       				game/map/get_nbr_players.c			\
       				game/map/remove_player_from_tile.c	\
       				game/map/remove_resources_from_tile.c\
       				game/map/get_dir.c					\
       				game/inventory/transfer_item.c		\
       				game/inventory/get_resource.c		\
       				game/inventory/check_ritual_resources.c\
       				game/team/get_team.c				\
       				game/team/add_player.c				\
       				game/team/get_player.c				\
       				game/team/remove_player.c			\
       				game/team/get_nbr_players.c			\
       				game/player/add.c					\
       				game/player/append.c				\
       				game/player/get.c					\
       				game/player/check.c					\
       				game/player/delete.c				\
       				game/commands/command_list.c		\
       				game/commands/move.c				\
       				game/commands/look.c				\
       				game/commands/look_tile.c			\
       				game/commands/inventory.c			\
       				game/commands/broadcast.c			\
       				game/commands/connect_nbr.c			\
       				game/commands/fork.c				\
       				game/commands/eject.c				\
       				game/commands/take_set.c			\
       				game/commands/incantation.c			\
       				game/log/move_log.c					\
       				game/log/spawn_log.c				\
       				game/log/take_log.c					\
       				game/log/kill_log.c					\
       				game/log/hatch_log.c				\
       				game/log/incantation_log.c			\

SRC_SERV 		=	$(SRC_SERV_COMMON) $(SRC_SERV_NETWORK) $(SRC_SERV_GAME)

OBJS_SERV		=	$(addprefix $(SRC_DIR_SERV), $(SRC_SERV:.c=.o)) \
					$(addprefix $(SRC_DIR_SERV), $(SRC_SERV_MAIN:.c=.o))
### END SERVER

### UNIT TESTS
NAME_UT		=	unit_tests

SRC_UT_DIR	=	tests/

SRC_UT		=	tests_get_args.c			\
				tests_zappy.c				\
				tests_world.c				\
				tests_spawn_food.c			\
				tests_client.c				\
				tests_c_buffer.c			\
				tests_cbuf_has_command.c	\
				tests_log.c					\
				tests_tools.c				\
				tests_errors.c				\
				tests_inventory.c			\
				tests_parse_command.c		\
				commands/tests_move.c		\
				commands/tests_look.c		\
				commands/tests_connect_nbr.c\
				commands/tests_fork.c		\
				commands/tests_take_set.c	\
				commands/tests_broadcast.c	\
				commands/tests_incantation.c\
				commands/tests_eject.c		\

OBJS_UT		=	$(addprefix $(SRC_DIR_SERV), $(SRC_SERV:.c=.o)) \
				$(addprefix $(SRC_UT_DIR), $(SRC_UT:.c=.o))
### END UNIT TESTS

all:		$(NAME_SERV)

$(NAME_SERV):	$(OBJS_SERV)
				$(CC) $(OBJS_SERV) -o $(NAME_SERV) $(CFLAGS)

tests_run:	CFLAGS += --coverage
tests_run:	fclean $(OBJS_UT)
			$(CC) -o $(NAME_UT) $(OBJS_UT) $(CFLAGS) $(LDFLAGS)
			./$(NAME_UT)

clean:
			$(RM) $(OBJS_SERV) $(OBJS_UT)

fclean: 	clean
			$(RM) $(NAME_SERV) $(NAME_UT)
			find . -type f -name '*.gcno' -delete
			find . -type f -name '*.gcda' -delete

re:		fclean all

.PHONY:	all zappy_ai zappy_server clean fclean re tests_run
