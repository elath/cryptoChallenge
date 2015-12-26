#!/bin/bash

clang -Weverything -I"/home/bklippenstein/work/cryptoChallenge/include" fixedXOR.c ../../../tools/hextools.c -o fixedXOR
