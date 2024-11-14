#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int resu = INT32_MAX;
        for(int i =0 ; i < nums.size() -2; i++){
            for(int j= i + 1; j < nums.size() - 1; j++){
                for(int k = j+ 1; k < nums.size(); k ++){
                    if(nums[i] < nums[j] && nums[k] < nums[j]){
                        resu = min(resu, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        if(resu == INT32_MAX){
            return -1;
        }
        return resu;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}