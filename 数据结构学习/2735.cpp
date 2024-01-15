#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        N = nums.size();
        isvisited.resize(N,false);
        int resu = 0;
        MyPrintOne(nums);

        int index_1 = getminvaletoindex(nums);
        resu += nums[index_1];

        isvisited[index_1] = true;
        while( !isvisitedAll()){
            int index_min = getminvaletoindex(nums);
            if(nums[index_min] <= x){
                resu += nums[index_min];
                isvisited[index_min] = true;
            }else if(isselect(nums,x)){
                index_min = getminvaletoindex(nums);
                resu += nums[index_min];
                isvisited[index_min] = true;
            }else{
                resu += x;
                numsrighttrant(nums);
                MyPrintOne(nums);
                index_min = getminvaletoindex(nums);
                resu += nums[index_min];
                isvisited[index_min] = true;

            }
        }
        cout << "resu= " << resu << endl;
        return resu;


        
    }
private:
    bool isselect(vector<int>&nums,int x)
    {
        int minindex = getminvaletoindex(nums);
        int cost = nums[minindex];
        
        vector<int>temp = nums;
        numsrighttrant(temp);
        int minindex2 = getminvaletoindex(temp);
        int cost2 = temp[minindex2] + x;

        if(cost < cost2){
            return true;
        }
        return false;


    }
    void numsrighttrant(vector<int>&nums)
    {
        int n = nums.size();
        int temp = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            nums[i+1] = nums[i];
        }
        nums[0] = temp;
    }

    bool isvisitedAll()
    {
        for(int i = 0; i < N; i++){
            if(isvisited[i] == false){
                return false;
            }
        }
        return true;
    }
    int getminvaletoindex(vector<int>& nums) 
    {
        int resu = INT32_MAX;
        int index = -1;
        for(int i = 0; i< N; i++){
            if(isvisited[i]==false && nums[i] < resu){
                resu = nums[i];
                index = i;
            }
        }
        cout << "index= " << index << endl;
        return index;
    }
private:
    vector<bool>isvisited;
    int N;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int> nums = {31,25,18,59};
    int x = 27;
    s1.minCost(nums,x);

    

    cout << "hell22o" << endl;
    return 0;
}