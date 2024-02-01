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
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size(); i++){
            mymap[nums[i]]++;
            if(mymap[nums[i]] == 3) {
                mymap.erase(nums[i]);
            }

        }
        auto it = mymap.begin();
        return it->first;

    }

public:
    unordered_map<int,int>mymap;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}