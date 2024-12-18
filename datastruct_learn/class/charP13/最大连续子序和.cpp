/*
https://blog.csdn.net/qq_21989927/article/details/107998410?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-107998410-blog-91354863.235%5Ev38%5Epc_relevant_default_base&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-107998410-blog-91354863.235%5Ev38%5Epc_relevant_default_base&utm_relevant_index=9
*/

#include"../../STLCOMMON.h"

using namespace std;


int CalMaxSumSeq(vector<int>&nums)
{
    // nums.insert(nums.begin(), 0);
    MyPrintOne(nums);
    int ans = nums[0];
    int sum = 0;
    int maxLength = 0;
    int startIndex = 0;
    for(int i = 0 ; i< nums.size(); i++){
        if( sum >= 0 ){
            sum += nums[i];
            maxLength += 1;
        }else{
            sum = nums[i];
            maxLength = 1;
            startIndex = i;
        }
        ans = max(ans, sum);
    }
    cout << "ans= " << ans << " startIndex= " << startIndex << " maxLength= " << maxLength << endl;



    return ans;

}

int main()
{
    vector<int>nums= {1, 0,-2, 10, -8, 9};
    int resu = CalMaxSumSeq(nums);
    cout << "resu= " << resu << endl;
    return 0;
}