#!/bin/bash
lex lexical.l
yacc -d parser2.y
cc y.tab.c -o parser.out
./parser.out