COMP = cc
FLAGS = -Wall -Wextra -Werror
SRC = ./src
CFILES = *.c
LIB = ./lib
OUTNAME = bsq

all: $(files)
	$(COMP) $(FLAGS) $(SRC)/$(CFILES) -I$(LIB) -o $(OUTNAME)
