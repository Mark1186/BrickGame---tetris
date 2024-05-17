CC=gcc
FLAGS=-Wall -Werror -Wextra
INC=-Isrc/
CFLAGS=$(FLAGS) -c -g --std=c11 $(INC)
LFLAGS=$(FLAGS) -lncurses
DIR_GUARD=@mkdir -p $(@D)
OS = $(shell uname)
VALGRIND_FLAGS=valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all

UNAME_M := $(shell uname -m)
ifeq ($(UNAME_M),x86_64)
    ARCH := x86_64
else ifeq ($(UNAME_M),arm64)
    ARCH := arm64
else
    $(error "Unsupported architecture")
endif

ifeq ($(ARCH),arm64)
    CFLAGS += -arch arm64
    LFLAGS += -arch arm64
endif

ifeq ($(OS),Linux)
    det_OS = -lcheck -lm -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lm -lpthread
endif

all: 
	$(CC) $(FLAGS) brick_game/tetris/backend.c brick_game/tetris/file_read.c brick_game/tetris/file_write.c gui/cli/*.c *.c -lncurses -o out/tetris.out
	./out/tetris.out 

TETRIS_SRC = $(wildcard brick_game/tetris/*.c *.c)

TETRIS_OBJ = $(TETRIS_SRC:.c=.o)

tetris.a: $(TETRIS_OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

game:
	$(CC) $(FLAGS) brick_game/tetris/backend.c brick_game/tetris/file_read.c brick_game/tetris/file_write.c gui/cli/*.c *.c --std=c11 -lncurses -o out/tetris.out
	./out/tetris.out

out/tetris: $(OBJECTS)
	$(DIR_GUARD)
	$(CC) $(OBJECTS) $(LFLAGS) -o out/tetris

test: clean
	$(CC) $(LFLAGS) brick_game/tetris/backend.c brick_game/tetris/tests.c --coverage -o test_result $(det_OS)
	./test_result

valgrind: test
	CK_FORK=no $(VALGRIND_FLAGS) -s ./test_result

gcov_report: test
	@lcov -t "brick_game_check" -o tetris.info -q -c -d .
	@genhtml -o report/ tetris.info
	@open report/index.html
	@rm -rf *.gcno *gcda *.gcov *.info test_result

style_fix:
	clang-format -style=Google -i *.c *.h brick_game/tetris/*.c gui/cli/*.c

style_check:
	clang-format -style=Google -n *.c *.h brick_game/tetris/*.c gui/cli/*.c

dvi:
	mkdir -p dvi/
	pandoc -s -o dvi/TETRIS.tex TETRIS.md
	latex -output-directory=dvi -output-format=dvi -interaction=nonstopmode TETRIS.tex

pdf:
	latex -output-directory=dvi -output-format=pdf -interaction=nonstopmode dvi/TETRIS.tex

dist: install
	mkdir -p ../dist
	cp -R out/tetris.out ../dist
	cp ../README.md ../README_RUS.md TETRIS.md ../dist
	cp KA.png ../dist
	cd ../dist && tar -cvzf tetris.tgz *
	cd ../dist && rm -rf tetris.out README.md README_RUS.md TETRIS.md KA.png
	echo "The build was successfully archived"
	rm -rf out/ *.o tetris brick_game/tetris/*.o

install: uninstall tetris.a
	mkdir out/
	gcc $(FLAGS) brick_game/tetris/backend.c brick_game/tetris/file_read.c brick_game/tetris/file_write.c gui/cli/*.c *.c tetris.a -lncurses -o out/tetris.out
	rm -rf tetris.a

uninstall:
	rm -rf out/ *.o tetris brick_game/tetris/*.o

clean:
	rm -rf out/* *.gcno test_result report *.gcda