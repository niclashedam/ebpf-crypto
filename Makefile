CLANG = clang

EXECABLE = src/ebpf-crypto
BPFCODE = src/bpf_program

BPFTOOLS = ubuntu-src/samples/bpf
BPFLOADER = $(BPFTOOLS)/bpf_load.c

CCINCLUDE += -I/kernel-src/tools/testing/selftests/bpf

LOADINCLUDE += -Iubuntu-src/samples/bpf
LOADINCLUDE += -Iubuntu-src/tools/lib
LOADINCLUDE += -Iubuntu-src/tools/perf
LOADINCLUDE += -Iubuntu-src/tools/include
LIBRARY_PATH = -Llib64
BPFSO = -lbpf

.PHONY: clean bpfload build deps

deps:
	sudo apt update
	sudo apt install -y build-essential git make libelf-dev clang strace tar bpfcc-tools linux-headers-$(uname -r) gcc-multilib
	test -e ubuntu-src || git clone --depth 1 git://kernel.ubuntu.com/ubuntu/ubuntu-focal.git ubuntu-src
	cd ubuntu-src/tools/lib/bpf && make && make install prefix=../../../../

clean:
	rm -f src/*.o src/*.so $(EXECABLE)

build: ${BPFCODE.c} ${BPFLOADER}
	$(CLANG) -O2 -target bpf -c $(BPFCODE:=.c) $(CCINCLUDE) -o ${BPFCODE:=.o}

bpfload: build
	clang -o $(EXECABLE) -lelf $(LOADINCLUDE) $(LIBRARY_PATH) $(BPFSO) \
        $(BPFLOADER) -DHAVE_ATTR_TEST=0 src/loader.c

$(EXECABLE): bpfload

.DEFAULT_GOAL := $(EXECABLE)
