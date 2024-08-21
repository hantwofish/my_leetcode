#!/bin/bash

g++ main.c -c -Wall -g -o main.o
g++ main.o -o m_exe

g++ --std=c++11 00_00.cpp -o main.exe && ./main.exe