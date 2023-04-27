#!/bin/bash
lex lexicalanalyser.l
yacc -d syntaxanalyser.y
cc y.tab.c -o syntax.out
./syntax.out