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
    string reverseWords(string s) {
        int front = 0; 
        int end = front + 1;
        while(end < s.length()){
            while(end < s.length() && s[end] != ' ') end++;

            reverseStr(s, front, end -1);

            front = end + 1;
            end = front + 1;
        }
        cout << "resu= " << s << endl;
        return s;
    }
private:
    void reverseStr(string &s, int i , int j)
    {
        while(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        cout << "reverseStr=   " << s << endl;
    }
};

int mainFunc()
{
    Solution s1;
    string str = "Let's take LeetCode contest";
    s1.reverseWords(str);

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