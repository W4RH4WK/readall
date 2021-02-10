CFLAGS += -std=c17 -Wall -Wextra -O3
CXXFLAGS += -std=c++17 -Wall -Wextra -O3

OUT = readall_c readall_cpp readall_go readall_hs readall_rs

all: $(OUT)

clean:
	$(RM) $(OUT)

run: $(OUT) rand.data
	@for exe in $(OUT); do \
		\time --format "%C\t%e\t%M" ./$$exe <rand.data >/dev/null; \
	done | column -t

.PHONY: all clean run

%: %.go
	go build $^

%: %.hs
	ghc -o $@ $^

%: %.rs
	rustc -O -o $@ $^

rand.data:
	head -c 1G /dev/urandom >$@
