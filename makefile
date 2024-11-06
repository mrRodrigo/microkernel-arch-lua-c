macos:
	@echo "Building for Mac OS"
	#brew install lua
	gcc -o core src/core/core.c main.c -I/opt/homebrew/Cellar/lua/5.4.7/include/lua  -L/opt/homebrew/Cellar/lua/5.4.7/lib -llua
	./core hello
