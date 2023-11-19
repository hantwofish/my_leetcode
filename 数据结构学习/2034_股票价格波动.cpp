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

struct CmpByValueMax {
    bool operator()(const pair<int, int>&k1, const pair<int, int>&k2) const
    {
        if(k1.second > k2.second){ //降序排列
            return true;
        }else if (k1.second == k2.second) {
            return k1.first < k2.first;
        }
        return false;
    }
};
struct CmpByValueMin {
    bool operator()(const pair<int, int>&k1, const pair<int, int>&k2) const
    {
        if(k1.second < k2.second){ //升序排列
            return true;
        }else if (k1.second == k2.second) {
            return k1.first < k2.first;
        }
        return false;
    }
};


class StockPrice {
public:
    StockPrice() {
        curTime = 0;
    }

    
    void update(int timestamp, int price) {
        curTime = max(curTime, timestamp);
        // 是修改
        if( timeValuMap.find(timestamp)  != timeValuMap.end()){
            // 删除旧的
            int oldPrice = timeValuMap[timestamp];
            pair<int, int> temOld = make_pair(timestamp, oldPrice);
            if(MaxMap.find(temOld) != MaxMap.end()){
                cout << "max found" << endl;
            }else{
                cout << "not found" << endl;
            }
            if(MinMap.find(temOld) != MinMap.end()){
                cout << "max found" << endl;
            }else{
                cout << "not found" << endl;
            }
            MaxMap.erase(temOld);
            MinMap.erase(temOld);

        }


        // 更新新的
        timeValuMap[timestamp] = price;        
        pair<int, int> newTemp =  {timestamp, price};
        MaxMap.insert(make_pair(make_pair(timestamp, price),price));
        MinMap.insert(make_pair(make_pair(timestamp, price),price));
    }
    
    int current() {
        return timeValuMap[curTime];
    }
    
    int maximum() {
        auto it = MaxMap.begin()->first;
        cout<< "maximum index=  " <<MaxMap.begin()->first.first << " val= " << MaxMap.begin()->first.second << endl;
        return MaxMap.begin()->second;
    }
    
    int minimum() {
        cout<< "MinMap index=  " <<MinMap.begin()->first.first << " val= " << MinMap.begin()->first.second << endl;
        return MinMap.begin()->second;

    }
public:
    map<pair<int, int>, int, CmpByValueMax>MaxMap;// <time ,value>, value
    map<pair<int, int>, int, CmpByValueMin>MinMap;// <time ,value>, value

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