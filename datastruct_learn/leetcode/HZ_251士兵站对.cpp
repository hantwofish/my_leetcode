#include"../STLCOMMON.h"

using namespace std;

class Solution{
public:
    int GetminTimes(int N, vector<vector<int>>&nums)
    {
        return 990;
    }

public:
};

void GetData(int &N, vector<vector<int>>&nums)
{
    cin >> N;
    int x ;
    int y;
    for(int i = 0; i< N; i++){
        cin >> x >> y;
        nums[i][0] = x;
        nums[i][1] = y;
    }

}

int main()
{
    Solution s1;
    int N = 5;
    vector<vector<int>>nums = {
        {1,2},
        {2,2},
        {1,3},
        {3,-2},
        {3,3}
    };
    // MyPrintTwo(nums);
    // GetData(N, nums);
    MyPrintTwo(nums);
    int resu =s1.GetminTimes(N, nums);
    cout << "resu= " << resu  << endl;
    return 0;

}
