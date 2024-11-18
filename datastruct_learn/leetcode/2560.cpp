#include"../STLCOMMON.h"



using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        dfs(nums, k, 0);
        // int resu = INT32_MAX;
        // for(int i = 0; i< resuArry.size(); i++){
        //     sort(resuArry[i].begin(), resuArry[i].end());
        //     int temp = *(resuArry[i].end()-1);
        //     resu = min(resu, temp);

        // }
        cout << "resu= " << output << endl;
        return output;
    }
    void dfs(vector<int>&nums, int k, int startindex)
    {
        if(temp.size() == k){
            // MyPrintOne(temp);
            sort(temp.begin(),temp.end());
            vector<int>onetemp =temp;
            sort(onetemp.begin(),onetemp.end());
            output = min(output, *(onetemp.end()-1));
            // resuArry.push_back(temp);
            return;
        }
        for(int i = startindex; i< nums.size();i++){
            temp.push_back(nums[i]);
            
            dfs(nums,k, i+2);

            temp.pop_back();
        }
    }
    
public:
    vector<int>temp;
    vector<vector<int>>resuArry;
    int output = INT32_MAX;
};



int main()
{
    Solution s1;
    vector<int> nums = {2,7,9,3,1};
    int k = 2;

    s1.minCapability(nums, k);


    

    cout << "hello word" << endl;
    return 0;
}