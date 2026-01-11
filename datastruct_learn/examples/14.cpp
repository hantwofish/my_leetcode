#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        int min_Len = INT32_MAX;
        for(int i = 0; i < N;i++){
            int lenth = strs[i].length();
            min_Len = min(min_Len, lenth);
        }
        int index = 0;
        for(index = 0; index < min_Len; index++ ){
            if(index_equal( strs, index) == false){
                break;
            } 
        }
        

        string sub_Str= strs[0].substr(0, index);
        cout << " sub_Str= " << sub_Str << endl;
        return sub_Str;
    }
    bool index_equal(vector<string>& strs, int inde) 
    {
        for(int i = 0; i< strs.size(); i++){
            if(strs[i][inde] != strs[0][inde]){
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