#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>cha_stack;
        for(int i = 0; i< s.length(); i++){
            char cur_temp = s[i];
            if(is_Left(cur_temp)){
                cha_stack.push(cur_temp);
            }else{
                char front_char = cha_stack.top();
                cha_stack.pop();
                if(cur_temp == ')'){
                    if(front_char == '('){
                        continue;
                    }else {
                        return false;
                    }
                }else if(cur_temp == ']'){
                    if(front_char == '['){
                        continue;
                    }else {
                        return false;
                    }
                }else if(cur_temp == '}'){
                    if(front_char == '{'){
                        continue;
                    }else {
                        return false;
                    }
                }
            }
            
        }
        if(!cha_stack.empty()){
            return false;
        }
        return true;
    }
private:
    bool is_Left(char cur_temp)
    {
        if(cur_temp == '(' || cur_temp == '['|| cur_temp == '{' ){
            return true;
        }
        return false;
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