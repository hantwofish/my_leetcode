#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    bool validPalindrome(string s) {
        int front = 0;
        int end =  s.size()-1;
        string str = s;
        if(s.size() == 1) return true;
        bool deleFlag = false;
        while(front < end){
            if(s[front] == s[end]){
                front++;
                end--;
            }else{ // 不相等
                cout << "front= " << front << " end= " << end << endl;
                bool flag1 = isVaild( s.erase( front,1 ));
                bool flag2 = isVaild( str.erase( end ,1));
                return flag1 | flag2;
            }

        }
        return true;

    }
    bool isVaild(string str)
    {
        int i = 0;
        int j = str.size()-1;
        while(i < j){
            if(str[i] == str[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;
    string num  = "abc";
    cout << s1.validPalindrome(num) << endl;
    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}