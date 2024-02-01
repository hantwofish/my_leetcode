#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0); // 定义以 i 结尾的 =最大值
        for(int i = 0; i< n; i++){
            if(i == 0) {
                dp[i] = nums[i];
                continue;
            }
            dp[i] = max(nums[i], dp[i-1]* nums[i]);
        }
        int resu = INT32_MIN;
        for(int i =0 ; i < n;i++){
            cout << "i= " << dp[i] << endl;
            resu = max(resu,dp[i]);
        }
        // cout << "resu= " << resu << endl;
        return resu;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0); // 定义以 i 结尾的 =最大值
        vector<int>dpmax(n+1,0);
        vector<int>dpmin(n+1,0);
        for(int i = 0; i< n; i++){
            if(i == 0) {
                dp[i] = nums[i];
                dpmax[i] = nums[i];
                dpmin[i] = nums[i];
                continue;
            }
            dpmax[i] = max(max(nums[i],dpmax[i-1]*nums[i]),dpmin[i-1]*nums[i]);
            dpmin[i] = min(min(nums[i],dpmin[i-1]*nums[i]),dpmax[i-1]*nums[i]);
            dp[i] = max(dpmax[i], dp[i-1]);
        }
        int resu = INT32_MIN;
        for(int i =0 ; i < n;i++){
            cout << "i= "<< i << " " << dp[i] << endl;
            resu = max(resu,dp[i]);
        }
        cout << "resu= " << resu << endl;
        return resu;
    }
};




int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {-2,3,-4};
    s1.maxProduct(nums);
    

    cout << "hell22o" << endl;
    return 0;
}