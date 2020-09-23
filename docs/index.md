# Installation

1. Install all neccessary dependencies.

```
sudo apt-get -y install bison build-essential cmake flex git libedit-dev \
  libllvm3.7 llvm-3.7-dev libclang-3.7-dev python zlib1g-dev libelf-dev
```

2. Compile the `bcc` dependency.

```
make bcc
```

3. Compile *ebpf-crypto* binaries.

```
make
```
