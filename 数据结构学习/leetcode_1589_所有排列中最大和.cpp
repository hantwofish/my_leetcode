#include "../STLCOMMON.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <set>
#include <unordered_set>

#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        sort(nums.begin(), nums.end());
        int resu = 0;
        do {
            int temp = calSum(nums, requests);
            resu = max(resu, temp);
        } while (next_permutation(nums.begin(), nums.end()));
        cout << "resu= " << resu << endl;
        return resu;
    }
    int calSum(vector<int> &nums, vector<vector<int>> &requests)
    {
        // 前缀和
        vector<int> temp = nums;
        temp.insert(temp.begin(), 0);
        vector<int> temSum(temp.size(), 0);
        for (int i = 1; i < temp.size(); i++) {
            temSum[i] += temSum[i - 1] + nums[i - 1];
        }

        int sumVal = 0;
        for (int i = 0; i < requests.size(); i++) {
            int left = requests[i][0] + 1;
            int right = requests[i][1] + 1;
            sumVal += (temSum[right] - temSum[left - 1]);
        }
        cout << "sumVal= " << sumVal << endl;
        return sumVal;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> requests = {{1, 3}, {0, 1}};
    int resu = s1.maxSumRangeQuery(nums, requests);
    switch (nums) {
    case nullptr:
        /* code */
        break;

    default:
        break;
    }

    cout << "hello" << endl;

    return 0;
}