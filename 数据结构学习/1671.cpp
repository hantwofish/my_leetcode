#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        NSIZE = N;
        maxdp.resize(N,1);
        mindp.resize(N,1);
        GetMaxDp(nums);
        GetMinDp(nums);
        int maxlen = 0;
        for(int i = 0; i < NSIZE;i++){
            if(maxdp[i] >=2 && mindp[i] >= 2){
                maxlen = max(maxlen, maxdp[i] + mindp[i] -1);
            }
        }

        return NSIZE - maxlen;
    }
    void GetMaxDp(vector<int>& nums)
    {
        for(int i= 0; i< NSIZE; i++){
            for(int j=0; j < i; j++){
                if(nums[j] < nums[i]){
                    maxdp[i]= max(maxdp[i], maxdp[j] +1);
                }
            }
        }
        MyPrintOne(maxdp);

    }
    void GetMinDp(vector<int>& nums)
    {
        for(int i= nums.size() -1; i >= 0; i--){
            for(int j= nums.size()-1; j> i; j--){
                if(nums[j] < nums[i]){
                    mindp[i] = max(mindp[i], mindp[j]+1);
                }
            }
        }
        MyPrintOne(mindp);


    }
private:
    vector<int>maxdp; // 以 nums[i] 为结尾的递增子序列
    vector<int>mindp; // 以 nums[i] 为开头的递减子序列
    int NSIZE = 0;
};

int main()
{
    Solution s1;
    vector<int>nums= {2,1,1,5,6,2,3,1};
    s1.minimumMountainRemovals(nums);
    

    cout << "hell22o" << endl;
    return 0;
}

/*
求出最长的连续递增子数组与最长的连续递减子数组
                             2 1 1 5 6 2 3 1
以nums[i]为结尾的递增子序列     1 1 1 2 3 2 3 1
以nums[i]为结尾的递增子序列     2 1 1 3 3 2 2 1
因为峰值不能在端点 所以 maxdp[i] >= 2 && mindp[i] >= 2

遍历所有峰值的位置，求出最长山峰长度

原先数组长度 - 最长山峰长度 = 要删除的数目
*/