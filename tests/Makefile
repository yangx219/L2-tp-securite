SRC= $(wildcard *.c)
TESTS=$(basename $(SRC))

all: $(SRC)

$(SRC): $(SRC_OBJ)
	@$(CC) $(CFLAGS) -o $(basename $@) $@ $^ -I../src $(LFLAGS)
	@./$(basename $@) 2>&1

.PHONY: clean all $(SRC)

clean:
	@rm -rf *.o *~ $(TESTS)
