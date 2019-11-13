#!/bin/bash

./asm $1.s > /dev/null
md5 $1.cor
rm $1.cor
./vm_champs/asm $1.s > /dev/null
md5 $1.cor
rm $1.cor
