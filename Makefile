CC = gcc
CFLAGS = -Wall -Werror -g -pedantic -DLINUX -D_GNU_SOURCE
SRCMODULES = counter.c
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

exe: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

run: exe
	@./exe

test: run clean

ifneq (clean, $(SRCMODULES))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean:
	@rm -f *.o exe
