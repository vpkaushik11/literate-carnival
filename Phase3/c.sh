#!/bin/bash
lex lexicalanalysis.l
yacc -d syntaxanalysis.y 
g++ y.tab.c -o semantic.out
./semantic.out