COMP = cc
FLAGS = -Wall -Wextra -Werror
SRC = ./src
CFILES = *.c
LIB = ./lib
OUTNAME = bsq

all: $(files)
	$(COMP) $(FLAGS) $(SRC)/$(CFILES) -I$(LIB) -o $(OUTNAME)

norm:
	@clear
	@echo "- Código fuente -"
	@norminette -R CheckForbiddenSourceHeader src/*.c
	@echo ""
	@echo "- Librerías externas -"
	@norminette -R CheckForbiddenSourceHeader lib/*.h
	@echo ""
