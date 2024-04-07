#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int resu = INT32_MIN;
        for(int i=  0; i < nums.size()/2 ; i++){
            int j = nums.size() -1 - i;
            resu = max(resu, nums[i]+nums[j]);
        }

        cout << "resu= " << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>nums=  {3,5,2,3};
    s1.minPairSum(nums);
    
    cout << "hell22o" << endl;
    return 0;
}