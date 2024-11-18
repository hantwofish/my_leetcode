#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class MyCompareMAX{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.first < b.first;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        dp.resize(nums.size()+ 1, INT32_MIN);
        dp[0] = nums[0];
        myQueue.push({dp[0], 0});

        for(int i = 1; i< nums.size(); i++){
            // for(int j = 1; j <= k; j++ ){
            //     if(i -j < 0) {
            //         continue;
            //     }
            //     dp[i] = max(dp[i], dp[i-j]);
            // }
            while(i - myQueue.top().second > k) {
                myQueue.pop();
            }
            // dp[i] += nums[i];
            dp[i] = myQueue.top().first + nums[i];
            myQueue.push({dp[i], i}); 
        }
        MyPrintOne(dp);
        return dp[nums.size()-1];
    }
private:
    vector<int>dp;
    // 优先队列中二元组 {dp[i], i}
    // priority_queue<pair<int,int>>myQueue; //大顶堆
    priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMAX>myQueue;// 大顶堆
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {1,-1,-2,4,-7,3}; 
    int k = 2;
    int resu =  s1.maxResult(nums,k);

    

    cout << "resu= " << resu << endl;
    return 0;
}