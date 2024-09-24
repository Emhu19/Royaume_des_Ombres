# CC = gcc
# CFLAGS = -lncurses -Wall -Wextra -g
#
# all: PROJET EXECUTION
#
# PROJET: ncurses.o code.o
# 	$(CC) -o PROJET ncurses.o code.o $(CFLAGS)
#
# ncurses.o: ncurses.c
# 	$(CC) $(CFLAGS) -c ncurses.c
#
# code.o: code.c
# 	$(CC) $(CFLAGS) -c code.c
#
# EXECUTION: PROJET
# 	./PROJET
#
# clean:
# 	rm -f PROJET *.o
CC = gcc
CFLAGS = -lncurses -Wall -Wextra -Werror -g

SRCS = main.c game.c player.c map.c combat.c utils.c ncurses_helper.c graphique.c
OBJS = $(SRCS:.c=.o)
EXEC = PROJET

all: $(EXEC) EXECUTION

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

EXECUTION: PROJET
	./PROJET

clean:
	rm -f $(OBJS) $(EXEC)


