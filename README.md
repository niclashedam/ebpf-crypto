# ebpf-crypto

ebpf-crypto is a eBPF module for automatically encrypting and decrypting data stored on an NVME device.
ebpf-crypto is in active development, and as such, there are not guarantee on the stability of the program.

## Installation

To install ebpf-crypto, first clone this repository.

```
git clone https://github.com/niclashedam/ebpf-crypto
```

Install dependencies needed to compile *ebpf-crypto*.

```
make deps
```

Download the newest instance of the kernel and compile necessary modules. This will take 5-10 minutes depending on your connection.

```
make kernel-src
```

Compile *ebpf-crypto*.

```
make
```

## Usage

To start ebpf-crypto, go to the root of the repository and run.

```
sudo LD_LIBRARY_PATH=lib64/:$LD_LIBRARY_PATH ./src/ebpf-crypt
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GPLv3](https://choosealicense.com/licenses/gpl-3.0/)
