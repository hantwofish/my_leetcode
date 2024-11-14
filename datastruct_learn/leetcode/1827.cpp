#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int times = 0;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] > nums[i-1]){
                continue;
            }
            int target = nums[i-1] + 1;
            
            times += (target - nums[i]);
            nums[i] = target;
        }
        cout << " tiems= " << times << endl;
        return times;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,5,2,4,1};
    s1.minOperations(nums);
    
    

    cout << "hell22o" << endl;
    return 0;
}