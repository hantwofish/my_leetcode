#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>s_2_t;
        unordered_map<char, char>t_2_s;
        int  N = s.length();
        for(int i = 0; i< N; i++){
            char temp1=  s[i];
            char temp2 = t[i];
            s_2_t[temp1] = temp2;
            t_2_s[temp2] = temp1;
            
        }
        for(int i = 0; i< N; i++){
            char temp1=  s[i];
            char temp2 = t[i];
            if(s_2_t[temp1] != temp2 || t_2_s[temp2] != temp1){
                return false;
            }
        }

        return true;
        
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