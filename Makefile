CFLAGS += -std=c17 -Wall -Wextra -O3
CXXFLAGS += -std=c++17 -Wall -Wextra -O3

OUT = readall_c readall_cpp readall_go readall_rs

all: $(OUT)

clean:
	$(RM) $(OUT)

.PHONY: all clean

%: %.go
	go build $^

%: %.hs
	ghc -o $@ $^

%: %.rs
	rustc -O -o $@ $^

rand.data:
	head -c 1G /dev/urandom >$@
