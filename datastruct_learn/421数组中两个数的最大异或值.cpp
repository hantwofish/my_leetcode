#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int resu = 0; 
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+ 1; j < nums.size();j++){
                resu =  max(resu, nums[i] ^ nums[j]);
            }
        }
        return resu;

    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    vector<int>nums = {3,10,5,25,2,8};
    int resu=  s1.findMaximumXOR(nums);
    cout << "resu= " << resu << endl;
    cout << "xor= "<< (3^5);
    

    cout << "hello" << endl;
    return 0;
}