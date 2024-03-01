#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if(nums.size() <2) return false;

        dp.resize(nums.size(), 0);
        // dp[0] = 1;
        // dp[1] = (nums[1] == nums[0]);

        for(int i= 0; i< nums.size(); i++){
            if(i == 1){
                if(nums[i] == nums[i-1]) {
                    dp[i] = 1;
                    continue;
                }
            }else if(i == 2){
                if((nums[i] == nums[i-1] && nums[i] == nums[i-2]) || (nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1)){
                    dp[i] = 1;
                }
                continue;
            }
            

            dp[i] = (i>=2 && dp[i-2] && nums[i] == nums[i-1]) || 
                    (i>=3 && dp[i-3] && nums[i] == nums[i-1] && nums[i] == nums[i-2]) || 
                    (i>=3 && dp[i-3] && nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1);
        }
        
        for(int i =0;i < dp.size(); i++){
            cout << dp[i] << " ";
        }
        cout << endl;

        bool flag = dp[nums.size()-1];  
        cout << "flag = " << flag << endl;
        return flag;      
    }
private:
    vector<bool>dp;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {4,4,4,5,6};
    s1.validPartition(nums);
    

    cout << "hell22o" << endl;
    return 0;
}