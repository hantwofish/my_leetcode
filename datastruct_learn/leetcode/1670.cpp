#include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        data.insert(data.begin(),val);
    }

    void pushMiddle(int val) {
        int N = data.size();
        int midIndex = 0;
        if(N % 2== 0){
            midIndex = (N/2 + 1) -1;
        }else{
            midIndex = ((N + 1)/2)-1;
        }
        auto it = data.begin()+ midIndex;

        data.insert(it, val);
    }

    void pushBack(int val) {
        data.push_back(val);
    }

    int popFront() {
        if(data.empty()) return -1;
        auto it = data.begin();
        int temp = *it;
        data.erase(it);
        return temp;
    }

    int popMiddle() {
        if(data.empty()) return -1;
        int N = data.size();
        int midIndex = 0;
        if(N % 2== 0){
            midIndex = (N/2)-1;
        }else{
            midIndex = ((N + 1)/2)-1;
        }

        auto it =  data.begin()+ midIndex;
        int temp = *it;
        data.erase(it);
        return temp;
    }

    int popBack() {
        if(data.empty()) return -1;
        int temp = *(data.end()-1);
        data.pop_back();
        return temp;
    }
public:
    vector<int>data;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}