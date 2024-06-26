#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>

#define TIMEINTERVAL 3

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
        int leftEnd = 0;
        int rightFront = costs.size()-1;

        visited.resize(costs.size(), 0);
        for(int i = 0; i < candidates && i < costs.size(); i++){
            myQue.push({i, costs[i]});
            visited[i] = 1;
            leftEnd = max(leftEnd, i);
        }
        for(int i= costs.size()- 1; i>= costs.size() - candidates && i >= 0; i--){
            if(visited[i] == 1) continue;
            myQue.push({i, costs[i]});
            visited[i] = 1;
            rightFront = min(rightFront, i);
        }
        // cout << "leftEnd= " << leftEnd << " rightFront= " << rightFront << endl;



        while(k > 0){
            // if(myQue.empty()) break;
            // cout << "k= " << k << endl;
            const int topIndex = myQue.top().first;
            // cout << topIndex << " -> " << costs[topIndex] << endl;
            myQue.pop();
            resu = resu + (long long)(costs[topIndex]);
            // cout << "top=" << myQue.top().first << endl;

            int curIndex = topIndex;
            if(topIndex <= leftEnd){
                curIndex = leftEnd;
                while(curIndex < rightFront &&  visited[curIndex] == 1){
                    curIndex++;
                }
                if(curIndex > leftEnd && curIndex != topIndex && curIndex < rightFront){
                    myQue.push({curIndex, costs[curIndex]});
                    // cout << "push index "<< curIndex << endl;
                    leftEnd = curIndex;
                    visited[curIndex] = 1;
                }
                
            }else{
                curIndex = rightFront;
                while(curIndex >leftEnd &&  visited[curIndex] == 1){
                    curIndex--;
                }

                if(curIndex < rightFront && curIndex != topIndex && curIndex > leftEnd){
                    myQue.push({curIndex, costs[curIndex]});
                    // cout << "push index "<< curIndex << endl;
                    rightFront = curIndex;
                    visited[curIndex] = 1;
                }
            }


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
    vector<int>visited;
    // priority_queue<int, vector<int>,greater<int>> myQue;
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMIN>myQue; // 小顶堆
};

int mainFunc()
{
    Solution s1;
    vector<int>costs = {69,10,63,24,1,71,55,46,4,61,78,21,85,52,83,77,42,21,73,2,80,99,98,89,55,94,63,50,43,62,14};
    int k = 21;
    int  candidates = 31;
    // vector<int>costs = {1,2,4,1};
    // int k = 3;
    // int  candidates = 3;
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