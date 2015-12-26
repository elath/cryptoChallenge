#!/bin/bash

clang -Weverything -I"/home/bklippenstein/work/cryptoChallenge/include" base64.c ../../../tools/hextools.c -o base64
