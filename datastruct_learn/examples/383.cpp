#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>my_map;
        for(int i = 0; i < magazine.size(); i++){
            my_map[magazine[i]]++;
        }
        for(int i = 0 ; i< ransomNote.size(); i++){
            char temp = ransomNote[i];
            if(my_map[temp] <= 0){
                return false;
            }else{
                my_map[temp]--;
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