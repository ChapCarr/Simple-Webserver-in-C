CC=gcc
CFLAGS=-Wall -Wextra -g

webserver: webserver.o launch.o
	$(CC) $(CFLAGS) $^ -o $@

webserver.o: webserver.c webserver.h
	$(CC) $(CFLAGS) -c $< -o $@

launch.o: launch.c webserver.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o webserver
