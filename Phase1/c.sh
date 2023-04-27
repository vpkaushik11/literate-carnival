#!/bin/bash
lex lexicalanalyser.l
cc lex.yy.c -o lexical.out
./lexical.out 