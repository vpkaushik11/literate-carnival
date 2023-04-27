#!/bin/bash
lex lexical.l
yacc -d parser.y
cc y.tab.c -o parser.out
./parser.out