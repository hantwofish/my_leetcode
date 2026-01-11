#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size(); // 发表了N篇。 h <= N . 有h篇的引用次数都 >= h
        for(int h = N; h >= 0; h--){
            int big_h = 0;
            for(int i =  0; i < citations.size(); i++){
                if(citations[i] >= h) {
                    big_h++;
                }
            }
            if(big_h >= h){
                return h;
            }

        }
        return 0;
    }
};

int main()
{

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp