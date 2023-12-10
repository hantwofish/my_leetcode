#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        bool flag = false;
        for(int i = 0; i< gas.size(); i++){
            flag = isVaild(i, gas,cost);
            if(flag){
                cout << "i= "<< i << endl;
                return i;
            } 
        }
        return -1;

    }
    bool isVaild(int start,vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        int remainVal = gas[start];
        int needcost = cost[start];
        if(remainVal < needcost) return false;
        // 到达 i
        for(int i = start + 1; (i % n != start); i++ ){
           
            int index = i %n;
            remainVal = remainVal - needcost + gas[index];
            needcost = cost[index];
            if(remainVal < needcost) return false;
        }
        return true;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>gas = {2,3,4};
    vector<int> cost = {3,4,3};
    int resu = s1.canCompleteCircuit(gas,cost);
    cout << "reus= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}