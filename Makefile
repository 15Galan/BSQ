COMP = cc
FLAGS = -Wall -Wextra -Werror
SRC = ./src
CFILES = *.c
LIB = ./lib
OUTNAME = bsq
NORM = norminette -R CheckForbiddenSourceHeader 

all: $(files)
	$(COMP) $(FLAGS) $(SRC)/$(CFILES) -I$(LIB) -o $(OUTNAME)

norm:
	@clear
	@echo "- Código fuente -"
	@$(NORM) $(SRC)/$(CFILES)
	@echo ""
	@echo "- Librerías externas -"
	@$(NORM) $(LIB)/*.h
	@echo ""
