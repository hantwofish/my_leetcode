#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        set<int>set_nums(nums.begin(), nums.end());
        nums.clear();
        auto it = set_nums.begin();
        while(it != set_nums.end()){
            nums.push_back(*it);
            it++;
        }
        cout << " nums.size= " << nums.size() << endl;

        int maxChoose = 0;
        for(int i = 0, j = i; i < nums.size(); i++){
            while(j <nums.size() && nums[j] <= nums[i] + N -1 ){
                j++;
            }
            maxChoose = max(maxChoose, j - i);
        }
        /*
            while 循环要快于 for
            for(int i = 0, j = i; i < nums.size(); i++){ 快于
                for(int i = 0; i < nums.size(); i++){
                    j = i;
                }
        */
        cout << " main resu= "<<  N- maxChoose << endl;
        return N- maxChoose;
    }
};

int main()
{
    Solution s1;
    // vector<int>nums = {1,10,100,1000};
    // vector<int>nums = {1,2,3,5,6};
    vector<int>nums = {4,5,8,8,9,9};
    s1.minOperations(nums);
    
    

    cout << "hell22o" << endl;
    return 0;
}