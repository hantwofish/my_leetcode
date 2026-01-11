#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i< s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' ){
                temp += s[i];
            }
            if((s[i] >= 'A' && s[i] <= 'Z')){
                temp += (s[i] + 'a' -'A');
            }
            if(s[i] >= '0' && s[i] <= '9' ){
                temp += s[i];
            }
        }
        cout << "temp = " << temp << endl;
        for(int i = 0, j = temp.length()-1; i<temp.length() && j >=0; i++,j--){
            if(temp[i] != temp[j]){
                cout << temp[i] << " " << temp[j] << endl;
                return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution s1;
    string s = "A man, a plan, a canal: Panama";
    s1.isPalindrome(s);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp