#!/bin/bash

./asm $1.s
hexdump $1.cor > temp
md5 $1.cor 
rm $1.cor
./vm_champs/asm $1.s
hexdump $1.cor > temp2
md5 $1.cor 
rm $1.cor
