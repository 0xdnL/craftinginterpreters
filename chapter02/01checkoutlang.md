# checkout some code and investigate

## go

> https://go.dev/doc/install/source

```sh
git clone https://go.googlesource.com/go goroot && cd goroot
git checkout go1.20.1 #<tag>
```

chapter02/go/goroot/src/cmd/compile/README.md

### 2 official Go compiler toolchains

- gc go compiler and tools
- gccgo, a more traditional compiler using the gcc backend
- both support the following instruction sets

```sh
amd64, 386                      # x86 instruction set, 64- and 32-bit
arm64, arm                      # ARM instruction set, 64-bit (AArch64) and 32-bit
loong64                         # 64-bit LoongArch instruction set
mips64, mips64le, mips, mipsle  # MIPS instruction set, big- and little-endian, 64- and 32-bit
ppc64, ppc64le                  # 64-bit PowerPC instruction set, big- and little-endian
riscv64                         # 64-bit RISC-V instruction set
s390x                           # IBM z/Architecture
wasm                            # WebAssembly
```

- both can target: AIX, Android, DragonFly BSD, FreeBSD, Illumos, Linux, macOS/iOS, NetBSD, OpenBSD, Plan 9, Solaris, and Windows OS
- first-class ports: darwin/amd64, darwin/arm64, linux/386, linux/amd64, linux/arm, linux/arm64, windows/386, windows/amd64

# python

```sh
curl -LO https://www.python.org/ftp/python/3.10.11/Python-3.10.11.tgz
tar xvzf Python-3.10.11.tgz
```

## php

```sh
git clone https://github.com/php/php-src.git --branch=master
```

## typescript

https://github.com/microsoft/TypeScript/blob/a4009a335a7299386cf1a6c7ba569ddfde07b247/src/compiler/scanner.ts#L44


## v8 (javascript)

download source
