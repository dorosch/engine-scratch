# Engine from scratch

Game engine from scratch to learn the basics of 3D graphics


## Install

```bash
$ sudo apt-get install -y libsdl2-dev
$ make
$ g++ main.cpp -L ./lib -lengine -I include -o main
$ LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH ./main
```
