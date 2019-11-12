#!/bin/bash

./asm $1.s > temp
md5 $1.cor 
rm $1.cor
./vm_champs/asm $1.s
md5 $1.cor 
rm $1.cor
