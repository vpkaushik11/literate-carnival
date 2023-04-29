#!/bin/bash
lex lexer.l
yacc -d -v parser.y
gcc -w y.tab.c
./a.out<input1.c