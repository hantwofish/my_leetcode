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
        for(int i = 0; i < nums.size(); i++){
            int start = nums[i];
            int end = start + N -1;
            int temp_tiems = 0;
            for(int j = i ; j < nums.size(); j++ ){
                if(nums[j] >= start && nums[j] <= end){
                    temp_tiems++;
                }
            }
            cout << "i= "<< i << " temp_tiems= " << temp_tiems << endl;
            maxChoose = max(maxChoose, temp_tiems);
        }
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