#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        vector<int>indexarry;
        for(int i = 0; i< nums1.size(); i++){
            indexarry.push_back(i);
        }

        int cursum = 0;
        for(int j= 0; j < nums1.size(); j++){
            cursum += nums1[j];
        }
        if(cursum <= x){
            return 0;
        }


        int resu = INT32_MAX;
        do
        {
            // MyPrintOne(indexarry);
            int times = calchangetimes(nums1,nums2, indexarry, x);
            resu = min(resu, times);
            
        } while (next_permutation(indexarry.begin(), indexarry.end()));

        return (resu == INT32_MAX ? -1 : resu);
        

    }
private:
    int calchangetimes(vector<int>nums1, vector<int>&nums2, vector<int>&indearry, int x)
    {
        int times = INT32_MAX;
        int cursum = 0;
        for(int i = 0 ; i < indearry.size(); i++){
            cursum = 0;
            int curindex = indearry[i];
            for(int j = 0; j< nums1.size(); j++){
                nums1[j] = nums1[j] + nums2[j];
            }
            nums1[curindex]  =0;
            for(int j= 0; j < nums1.size(); j++){
                cursum += nums1[j];
            }
            if(cursum <= x){
                MyPrintOne(indearry);
                cout << "i= " << i << endl;
                return (i+1);
            }

        }
        return times;
    }
};




int main()
{
    Solution s1;
    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = {1,2,3}; 
    int x = 4;
    int resu = s1.minimumTime(nums1,nums2,x);
    cout << "resu= " << resu << endl;

    

    cout << "hell22o" << endl;
    return 0;
}