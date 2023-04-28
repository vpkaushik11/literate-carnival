#!/bin/bash
lex lexical.l
yacc -d parser.y 
g++ y.tab.c -o parser.out
./parser.out