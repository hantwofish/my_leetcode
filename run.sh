
#!/bin/bash
 
# 检查参数个数
if [ $# -ne 1 ]; then
    echo "nume is not ok"
    exit 1
fi
 
# 输出两个参数的和
# sum=$(($1 + $2))
# echo "The sum is: $sum"

filename=$1
rm -f test.exe
g++ --std=c++11 ${filename} -o main.exe && ./main.exe


