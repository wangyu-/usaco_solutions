all:
	g++ -o a.out main.cpp -DTEST -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-missing-field-initializers -ggdb -fsanitize=address
