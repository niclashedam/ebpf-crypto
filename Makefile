CC = g++
CFLAGS = -O -Wall -I ./bcc/build/src/cc -I ./bcc/src/cc/api/ -I ./bcc/src/cc/
LIBS = -L./bcc/build/src/cc -lbcc -lbcc_bpf

.PHONY: bcc

all: enc

bcc:
	sudo apt-get -y install bison build-essential cmake flex git libedit-dev \
  	libllvm7 llvm-7-dev libclang-7-dev python zlib1g-dev libelf-dev libfl-dev

	git submodule init
	git submodule update

	mkdir bcc/build; cd bcc/build && \
	cmake .. && \
	make

enc: src/enc.cc
	$(CC) $(CFLAGS) -o build/enc src/enc.cc $(LIBS)

clean:
	rm -f src/*.o build/*
