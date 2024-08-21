
#!/bin/bash

filename=$1
# g++ --std=c++11 ./datastruct_learn/${filename} -o ./test.exe
# ./test.exe
g++ --std=c++11 ${filename} -o main.exe && ./main.exe
