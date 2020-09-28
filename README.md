# ebpf-crypto

ebpf-crypto is a eBPF module for automatically encrypting and decrypting data stored on an NVME device.
ebpf-crypto is in active development, and as such, there are not guarantee on the stability of the program.

## Installation

To install ebpf-crypto, first clone this repository.

```
git clone https://github.com/niclashedam/ebpf-crypto
```

Download and install needed dependencies.

```
make deps
```

Compile ebpf-crypto.

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
[Apache 2.0](https://choosealicense.com/licenses/apache-2.0/)
