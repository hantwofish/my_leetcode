#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        temp.clear();
        myset.insert(temp);
        dfs(nums,0);
        cout << "++++++ " << endl;
        vector<vector<int>>resu;
        auto it = myset.begin();
        while (it!= myset.end())
        {
            vector<int>temp = *it;
            // MyPrintOne(temp);
            resu.push_back(temp);
            it++;
        }
        return resu;

    }

    void dfs(vector<int>&nums, int cur)
    {
        if(cur >= nums.size()){
            // myset.insert(temp);
            return;
        }
        // temp.push_back(nums[cur]);
        // myset.insert(temp);
        // MyPrintOne(temp);
        for(int j = cur  ; j< nums.size(); j++){
            temp.push_back(nums[j]);
            // MyPrintOne(temp);
            vector<int>tempvalue = temp;
            sort(tempvalue.begin(),tempvalue.end());
            myset.insert(tempvalue);
            dfs(nums, j + 1);
            temp.pop_back();
        }
        // temp.pop_back();

    }
public:
    set<vector<int>>myset;
    vector<int>temp;
};

int main()
{
    Solution s1;
   vector<int>nums= {1,2,3};
   s1.subsetsWithDup(nums);

    

    cout << "hell22o" << endl;
    return 0;
}