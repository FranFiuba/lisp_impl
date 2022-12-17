# Lisp Implementation

A toy lisp implementation in C

## pre-requisites

### ubuntu 

sudo apt-get install libedit-dev 

### mac-os

brew install libedit

## compilation

cc -std=c99 -Wall main.c lib/mpc.c -ledit -lm -o parsing
