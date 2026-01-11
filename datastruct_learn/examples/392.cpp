#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;
// 示例 1：

// 输入：s = "abc", t = "ahbgdc"
// 输出：true
// 示例 2：

// 输入：s = "axc", t = "ahbgdc"
// 输出：false

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.length() && j < t.length()){
            char temp = s[i];
            while(j < t.length() && t[j] != temp){
                j++;
            }
            if(j >= t.length()) break;
             cout << "i= "<< i << " val= " << s[i] << " j= " << j << " " << t[j] << endl;
            if(s[i] == t[j]) {
                i++;
                j++;
            }else{
                break;
            }
        }
       
        if(i >= s.length()){
            return true;
        }   

        return false;


    }
};


int main()
{

    // string s = "abc"; string  t = "ahbgdc";
    string s = "axc"; string t = "ahbgdc";

    Solution s1;
    bool falg=  s1.isSubsequence(s,t);
    if(falg ) {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp