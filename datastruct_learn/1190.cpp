#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    string reverseParentheses(string s) {
        string resu = "";
        for( int i = 0; i< s.size(); i++){
            char temp = s[i];
            if(temp =='('){
                stk.push('(');

            }else if(temp == ')'){
                string stkStr ="";
                while(!stk.empty() && stk.top() != '('){
                    stkStr = stk.top() + stkStr;
                    stk.pop();
                }
                if(!stk.empty() && stk.top()== '(') stk.pop();
               
                // 反转
                reverse(stkStr.begin(), stkStr.end());
                cout << "stkStr = " << stkStr << endl;
                // if(stk.empty()){
                //     cout << "return " << stkStr << endl;
                //     return resu;
                // }  
                 
                for(int i =0; i < stkStr.size(); i++){
                    stk.push(stkStr[i]);
                }
                

            }else{
                stk.push(temp);
            }
        }

        while(!stk.empty()){
            resu = stk.top() + resu;
            stk.pop();
        }
        cout << "resu =" << resu << endl;
        return resu;

    }
private:
    stack<char>stk;
};

int mainFunc()
{
    Solution s1;
    string s = "(u(love)i)";
    // string s = "x(abcd)z";
    // string s = "(abcd)";
    s1.reverseParentheses(s);

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}