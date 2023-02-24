export CC= gcc
export CFLAGS= -W -Wall -ansi -pedantic -g -std=c99
export LFLAGS= -lgmp -lcrypto
SRC_C= $(wildcard src/*.c)
export SRC_OBJ= $(abspath $(SRC_C:.c=.o))

all: src tests

.PHONY: clean src tests

src:
	@(cd src && $(MAKE) all)

tests: src
	@(cd tests && $(MAKE) all)

clean:
	@rm -rf *~
	@(cd src && $(MAKE) $@)
	@(cd tests && $(MAKE) $@)
