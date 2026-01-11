#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        char same_char = needle[0];
        vector<int>vec;
        for(int i = 0; i< haystack.size(); i++){
            if(haystack[i] == same_char){
                vec.push_back(i);
            }
        }
        MyPrintOne(vec);
        for(int i =  0; i < vec.size(); i++){
            cout << "vec= " <<  vec[i] << endl;
            if(is_same(haystack, needle, vec[i])){
                
                return vec[i];
            }
        }
        return -1;
        
    }
    bool is_same(string haystack, string needle, int index)
    {
        cout << "Index= " << index << endl;
        if(haystack.size() - index + 1 < needle.size()){
            return false;
        }
        for(int i = 0; i < needle.size(); i++){

            if(haystack[i + index] != needle[i]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
//    string haystack = "leetcode";
//    string needle = "leeto";
 string haystack = "mississippi";
   string needle = "issi";
   Solution s1;
   s1.strStr(haystack, needle);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp