#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution2{
public:
    // (x-1)^2+ (x-3)^2 根据二次曲线中轴取出最小点 (-b/2a)
    long long solve(int k, vector<int>&nums)
    {
        long long midNum= 0;
        long long sum = 0;
        for(int i = 0; i< nums.size();i++){
            sum += nums[i];
        }
        midNum = (sum/k);
        long long resu = 0;
        for(int i = 0; i < nums.size(); i++){
            resu += abs(nums[i]-midNum);
        }
        
        return resu;
    }


};

class Solution{
public:
    
    long long solve(int k, vector<int>&nums)
    {
        long long midNum= 0;
        long long resu = 0;
        sort(nums.begin(),nums.end());
        int N = nums.size();
        if(N % 2== 1){
            midNum = nums[N/2];
        }else{
            int temp1 = 0;
            int temp2 = 0;
            temp1 = nums[N/2-1];
            temp2 = nums[N/2];
            midNum = (temp1 + temp2) / 2;
        }

        int mid2=  nums[N/2];
        int resu2= 0;
        cout << "mid=  "<< midNum << " " << mid2<< endl;
        
        for(int i = 0; i < nums.size(); i++){
            resu += abs(nums[i]-midNum);
            resu2 += abs(nums[i]-mid2);
        }

        cout << "resu= " << resu << " " << resu2 << endl;
        
        return resu;
    }


};

void GetDataInit(int &k, vector<int>&nums)
{
    nums.clear();
    cin >> k;
    int temp;
    for(int i=0 ;i < k;i++){
        cin >> temp;
        nums.push_back(temp);
    }
}



int main()
{
    Solution s1;
    
    vector<int>nums={1, 3, 8, 9};
    int k = nums.size();
    // GetDataInit(k, nums);
    long long  resu = s1.solve(k, nums);
    cout  << resu << endl;

    // cout << "end" <<endl;
    return 0;
}