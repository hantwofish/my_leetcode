
#include"../STLCOMMON.h"
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int resu = 0;
        for(int i= 0; i< nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++ ){
                if(nums[i] + nums[j] < target){
                    resu++;
                }
            }
        }
        return resu;
        
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {-1,1,2,3,1}; 
    int target = 2;
    int resu =  s1.countPairs(nums,target);
    cout << "resu= " << resu << endl;

}