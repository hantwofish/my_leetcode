#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int>dp(N,1); // 以nums[i] 结尾的递增子序列（nums[i] 必须选到）
        vector<int>pre(N,-1);
        for(int i = 0; i< nums.size(); i++){
            for(int j= 0; j < i ; j++){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        pre[i] = j;
                    }
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            cout << "i= " << i << " " << dp[i] <<  endl;
        }

        MyPrintOne(pre);

        sort(dp.begin(),dp.end());
        return *(dp.end()-1);

    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums={10,9,2,5,3,7,101,18};
    int resu = s1.lengthOfLIS(nums);
    cout << "resu= " << resu <<  endl;

    

    cout << "hell22o" << endl;
    return 0;
}