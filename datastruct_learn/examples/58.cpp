#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:

    int lengthOfLastWord(string s) {
        if(s.length() ==1){
            return 1;
        }
        int N = s.length();
        int start_Inde = N-1;
        int end_Index= N -1;
        while(end_Index >= 0 && s[end_Index] == ' '){
            end_Index--;
        }

        start_Inde = end_Index;
        while(start_Inde >= 0 && s[start_Inde] != ' '){
            start_Inde--;
        }
        start_Inde++;
        cout << " start_Inde= " << start_Inde << endl;

        return end_Index - start_Inde +1;
    }
};

int main()
{
    Solution s1;
    string s = "Hello World";
    s1.lengthOfLastWord(s);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp