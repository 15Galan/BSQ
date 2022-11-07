norm:
	@clear
	@echo "- Código fuente -"
	@norminette -R CheckForbiddenSourceHeader src/*.c
	@echo ""
	@echo "- Librerías externas -"
	@norminette -R CheckForbiddenSourceHeader lib/*.h
	@echo ""

%:
	@clear
	@echo "Ejecutando TEST $@:\t$$(basename tests/test_$@.c '.c')\n"
	@cc tests/test_$@.c src/*.c lib/*.h -Wall -Werror -Wextra -o tests/test_$@.out
	@./tests/test_$@.out
	@rm tests/test_$@.out
