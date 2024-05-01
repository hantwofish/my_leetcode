#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 8

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}

class MyCompareMIN{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        if(a.second > b.second) {
            return true;
        }else if(a.second == b.second){
            return a.first > b.first;
        }
        
        return false;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long resu = 0;
        data = costs;
        while(k > 0){
            cout << "k= " << k << endl; 
            int startIndex = 0;
            int endIndex = data.size() -1;

            while(!myQue.empty()){
                myQue.pop();
            }
            for(int i = 0; i< candidates; i++){
                if(startIndex < data.size()) myQue.push({startIndex, data[startIndex]});
                startIndex++;
                if(endIndex >= 0) myQue.push({endIndex, data[endIndex]});
                endIndex--;
            }
            resu = resu + myQue.top().second;

            eraseNum(myQue.top().first);
            k--;
        }
        cout << resu << endl;
        return resu;
    }
private:
    void eraseNum(int eras_index)
    {
        // for(int i = 0; i< data.size(); i++){
        //     if(data[i] == eraseVal){
        //         data.erase(data.begin() + i);
        //     }
        // }
        data.erase(data.begin() + eras_index);
    }
private:
    vector<int>data;
    // priority_queue<int, vector<int>,greater<int>> myQue;
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMIN>myQue; // 小顶堆
};

int mainFunc()
{
    Solution s1;
    // vector<int>costs = {17,12,10,2,7,2,11,20,8};
    // int k = 3;
    // int  candidates = 4;
    vector<int>costs = {1,2,4,1};
    int k = 3;
    int  candidates = 3;
    s1.totalCost(costs,k ,candidates);
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