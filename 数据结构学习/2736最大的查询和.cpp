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
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        vector<int> resu(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            string str = vetToStr(queries[i]);
            if (myMap.find(str) != myMap.end()) {
                resu[i] = myMap[str];
                continue;
            }
            resu[i] = calOnetime(nums1, nums2, queries[i]);
            myMap.insert({str, resu[i]});
        }

        // MyPrintOne(resu);
        return resu;
    }
    // 对于一次查询找到最大的值
    int calOnetime(vector<int> &nums1, vector<int> &nums2, vector<int> onequeries)
    {
        int n = nums1.size();
        pair<int, int> oneChoic({-1, -1}); // index , val
        for (int i = 0; i < n; i++) {
            if (nums1[i] >= onequeries[0] && nums2[i] >= onequeries[1]) {
                if (nums1[i] + nums2[i] > oneChoic.second) {
                    oneChoic.second = nums1[i] + nums2[i];
                    oneChoic.first = i;
                }
            }
        }
        return oneChoic.second;
    }
    string vetToStr(vector<int> vec)
    {
        string str = "";
        for (int i = 0; i < vec.size(); i++) {
            str = str + to_string(vec[i]) + "_";
        }
        return str;
    }

public:
    unordered_map<string, int> myMap;
};

void getInputData(int &n, vector<int> &nums)
{
}

int main()
{
    Solution s1;
    vector<int> nums1 = {4, 3, 1, 2};
    vector<int> nums2 = {2, 4, 9, 5};
    vector<vector<int>> queries = {{4, 1}, {1, 3}, {2, 5}};
    s1.maximumSumQueries(nums1, nums2, queries);

    cout << "hello" << endl;
    return 0;
}