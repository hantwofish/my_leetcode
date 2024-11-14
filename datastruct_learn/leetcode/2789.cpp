#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums_2) {
        vector<long long>nums(nums_2.begin(), nums_2.end());
        while(findOneChice(nums)){
            MyPrintOne(nums);
        }
        resu = nums[0];
        for(auto i : nums){
            resu = max(resu, i);
        }
        cout << "resu = " << resu << endl;
        return resu;
    }
private:
    bool findOneChice(vector<long long>&nums)
    {
        bool flag = false;
        int index  = -1;
        for(int i = 0; i< nums.size() -1; i++){
            if( nums[i] <= nums[i+1] ){
                flag = true;
                if(index == -1){
                    index = i;
                }
                if(i > index){
                    index = i;
                }
            }
        }
        if( flag  ){
            nums[index +1] = nums[index] + nums[index+1];
            nums.erase(nums.begin()+ index);
        }
        return flag;
    }
private:
    bool flag = false;
    long long resu = 0;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {34,95,50,12,25,100,21,3,25,16,76,73,93,46,18};
    s1.maxArrayValue(nums);
    

    cout << "hell22o" << endl;
    return 0;
}