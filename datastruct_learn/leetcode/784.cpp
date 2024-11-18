#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

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
    vector<string> letterCasePermutation(string s) {
        backTracing(0, "", s);
        return resu;
    }
    void backTracing(int cur_index, string cur_s, string s)
    {
        if(cur_index >= s.length()){
            resu.push_back(cur_s);
            cout << "  cur_s = " << cur_s << endl;
            return;
        }
        if(s[cur_index] >= '0' && s[cur_index] <= '9'){
            backTracing(cur_index + 1, cur_s + s[cur_index], s);
            return;
        }
        // 为字母有小写大写两种情况
        bool isBigFlag = true;
        if(s[cur_index] >= 'a' && s[cur_index] <= 'z'){
            isBigFlag = false;
        }

        backTracing(cur_index + 1, cur_s + s[cur_index], s);
        char temp;
        if(isBigFlag){
             temp = s[cur_index] + ('a' - 'A');
        }else{
             temp = s[cur_index] + ('A' - 'a');
        }
        backTracing(cur_index + 1, cur_s + temp, s);


    }
private:
    vector<string> resu;
};;

int mainFunc()
{
    Solution s1;
    string s = "3z4";
    s1.letterCasePermutation(s);

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