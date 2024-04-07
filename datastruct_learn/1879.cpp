#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

        printVec(nums1, nums2);
        return resu;
    }
    void printVec(vector<int>& nums1, vector<int>& indexarry)
    {
        sort(indexarry.begin(),indexarry.end());
        do
        {
            MyPrintOne(indexarry);
            getOrResu(nums1,  indexarry);
        } while (next_permutation(indexarry.begin(), indexarry.end()));
    }
    void getOrResu(vector<int>& nums1, vector<int>& nums2)
    {
        int res =0;
        for(int i= 0; i< nums1.size(); i++){
            res += (nums1[i] xor nums2[i]);
        }
        resu = min(res, resu);

    }
private:
    int resu = INT32_MAX;
};


int main()
{
    Solution s1;
    vector<int>nums1 = {65022,  4657711,8572489,3336640};
    vector<int>nums2 = {6030101,8828015,59043,  6529065};
    int resu= s1.minimumXORSum(nums1,nums2);
    cout << "resu= " << resu << endl;
    
    

    cout << "hell22o" << endl;
    return 0;
}