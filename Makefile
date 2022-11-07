norm:
	@clear
	@echo "- Código fuente -"
	@norminette -R CheckForbiddenSourceHeader src/*
	@echo ""
	@echo "- Librerías externas -"
	@norminette -R CheckForbiddenSourceHeader lib/*
	@echo ""
	
test:
	@clear
	cc tests/*.c src/*.c lib/*.h -Wall -Wextra -Werror
	@ ./a.out
	@rm a.out
