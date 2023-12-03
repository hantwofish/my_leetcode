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
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int N = 1010;
        tripinfo.resize(N, 0);
        for(int i = 0; i < trips.size(); i++){
            int num = trips[i][0];
            int from = trips[i][1];
            int todes = trips[i][2];
            for(int j = from; j <= todes -1 ; j++){
                tripinfo[j] += num;
                if(tripinfo[j] > capacity){
                    return false;
                }
            }
        }
        return true;
    }
public:
    vector<int>tripinfo;
};

int main()
{
    Solution s1;
    vector<vector<int>>trips = {{2,1,5},{3,3,7}};
    int capacity = 5;
    bool resu = s1.carPooling(trips, capacity);
    cout << "resu = " << resu << endl;
    

    // cout << "hello" << endl;
    return 0;
}