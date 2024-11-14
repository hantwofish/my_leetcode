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



class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        CapCity = capacity;
        
    }
    
    void push(int val) {
        int valdIndex = 0;
        if(stackIsFull(myVec, valdIndex) == true){
            stack<int>stk;
            stk.push(val);
            myVec.push_back(stk);
            if(stk.size () >= CapCity){
                vecFull.push_back(true);
            }else{
                vecFull.push_back(false);
            }
        }else{
            myVec[valdIndex].push(val);

            if(myVec[valdIndex].size () >= CapCity){
                vecFull[valdIndex] = true;
            }else{
                vecFull[valdIndex] = false;
            }
        }
    }
    bool stackIsFull(vector<stack<int>>&myVec, int &vailkStackIndex )
    {
        if(myVec.empty()) return true;
        for(int i = 0; i< myVec.size(); i++){
            if(vecFull[i] == false){
                vailkStackIndex = i;
                return false;
            } 
        }
        return true;
    }
    
    int pop() {
        for(int i = myVec.size()-1 ; i>=0 ; i--){
            if(!myVec[i].empty()){
                int topVal = myVec[i].top();
                myVec[i].pop();
                vecFull[i] = false;
                return topVal;
            }
        }
        return -1;
    }
    
    int popAtStack(int index) {
        if(index >= 0 && index <= myVec.size()-1){
            if(myVec[index].empty()){
                return -1;
            }else{
                int topVal = myVec[index].top();
                myVec[index].pop();
                vecFull[index] = false;
                return topVal;
            }
        }else{
            return -1;
        }
        return -1;
    }
private:
    int N = 100000;
    int CapCity = 0;
    vector<stack<int>>myVec;
    vector<bool>vecFull;
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