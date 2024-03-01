#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>resu(nums.size(), 0);
        for(int i= 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    nums[i]++;
                }
            }
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