#Arguments
CC=g++
output=main

compile:
	$(CC) -o $(output) main.cpp headers/* -std=c++98

