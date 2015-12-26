#!/bin/bash

clang -lm -Weverything -I"/home/bklippenstein/work/cryptoChallenge/include" \
sbXOR.c\
 ../../../tools/statstools.c\
 ../../../tools/hextools.c\
 -o sbXOR
