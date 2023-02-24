SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: objs

objs: $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<  $(LFLAGS)

.PHONY: clean all

clean:
	@(rm -rf *.o *~)
