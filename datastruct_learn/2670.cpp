#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) 
    {
        vector<int>resu;
        for(int i= 0; i< nums.size(); i++){
            frontArray.clear();
            behindArray.clear();
            for(int j = 0; j<= i; j++){
                frontArray.insert(nums[j]);
            }
            for(int j = i+1; j< nums.size(); j++){
                behindArray.insert(nums[j]);
            }  
            int frontsize = frontArray.size();
            int behinsize = behindArray.size();
            resu.push_back(frontsize- behinsize);
        }
        return resu;
    }
    
private:
    set<int>frontArray;
    set<int>behindArray;
};

int main()
{
    vector<int>nums = {1,2,3,4,5};
    Solution s1;
    vector<int>resu = s1.distinctDifferenceArray(nums);
    MyPrintOne(resu);
    cout << "edm" << endl;

    return 0;
}