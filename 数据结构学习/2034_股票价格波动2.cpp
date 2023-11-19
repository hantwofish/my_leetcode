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

class MyCompareMAX{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second < b.second;
    }
};
class MyCompareMIN{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second > b.second;
    }
};



class StockPrice {
public:
    StockPrice() {
        curTime = 0;
    }

    
    void update(int timestamp, int price) {
        curTime = max(curTime, timestamp);
        timeValuMap[timestamp] = price;  
        maxQue.push({timestamp,price});
        minQue.push({timestamp,price});
    }
    
    int current() {
        return timeValuMap[curTime];
    }
    
    int maximum() {
        // auto it = MaxMap.begin()->first;
        // cout<< "maximum index=  " <<MaxMap.begin()->first.first << " val= " << MaxMap.begin()->first.second << endl;
        while(!maxQue.empty()){
            int stamp = maxQue.top().first;
            int vale = maxQue.top().second;
            if(vale != timeValuMap[stamp]){
                maxQue.pop();
            }else{
                break;
            }
        }
        return maxQue.top().second;
    }
    
    int minimum() {
        while(!minQue.empty()){
            int stamp = minQue.top().first;
            int vale = minQue.top().second;
            if(vale != timeValuMap[stamp]){
                minQue.pop();
            }else{
                break;
            }
        }
        return minQue.top().second;

    }
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMAX>maxQue;// 大顶堆
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMIN>minQue; // 小顶堆

    map<int, int>timeValuMap;
    int curTime;
};


void getInputData(int& n, vector<int>&nums)
{

    

    
}

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}