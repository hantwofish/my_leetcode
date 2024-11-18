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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>A;
        A.resize(queries.size(), 0);
        vector<int>B(words.size(), 0);
        for(int i =0 ; i< queries.size(); i++){
            A[i] =  getMinNum(queries[i]);
        }
        for(int i =0 ; i< words.size(); i++){
            B[i] =  getMinNum(words[i]);
        }

        vector<int>resu(queries.size(), 0);
        for(int i = 0;i< queries.size(); i++){
            int tempReus = 0;
            for(int j = 0; j< words.size();j++){
                if(A[i] < B[j]) {
                    tempReus++;
                }
            }
            resu[i] = tempReus;
        }
        return resu;
    }
private:
    int getMinNum(string str){
        sort(str.begin(), str.end());
        map<char, int>myMap;
        for(int i =0; i< str.size(); i++){
            myMap[str[i]]++;
        }
        return myMap.begin()->second;
    }
};

int mainFunc()
{
    Solution s1;

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