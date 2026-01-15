#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.length();
        data.resize(numRows, vector<char>(N/3,' '));
        int cur_row = 0;
        int cur_col = 0;
        int i = 0;
        while(i < N){

            for(int row = 0; row < numRows; row++){
                data[row][cur_col] = s[i++];
            }
            cur_col++;
            // data[]

        }
    }
private:
    vector<vector<char>>data;
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