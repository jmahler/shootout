
BIN=revstr1 revstr2

all: $(BIN)

%: %.c
	gcc -Wall -Wextra $< -o $@

clean:
	-rm -f $(BIN)
