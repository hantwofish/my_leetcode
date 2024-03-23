#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumpDistance = INT32_MIN;
        for(int i= 0; i< nums.size(); i++){

            maxJumpDistance = max(maxJumpDistance, i + nums[i]);
            if(maxJumpDistance <= i){
                return false;
            }
        }
        return maxJumpDistance >= nums.size()-1;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}