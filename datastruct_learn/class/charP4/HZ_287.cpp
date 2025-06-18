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

class Solution{
public:
    int getMinCount(vector<int>&nums,int k)
    {
        sort(nums.begin(),nums.end());
        int total= 0;
        while(nums.size()>=2){
            sort(nums.begin(),nums.end());
            int top1= nums[0];
            int top2= nums[1];
            total += (top1 + top2);
            // auto index = find(nums.begin(),nums.end(), top1);
            nums.erase(nums.begin());
            nums.erase(nums.begin());
            nums.push_back(top1 + top2);

        }
        return total;
    }

};

void getData(vector<int>&nums,int& k)
{
    nums.clear();
    cin >>k;
    int data;
    for(int i = 0;i < k; i++){
        cin >> data;
        nums.push_back(data);
    }
    
}

int main()
{
    Solution s1;
    vector<int>nums= {1,2,9};
    int k = nums.size();
    getData(nums,k);
    int resu = s1.getMinCount(nums,k);
    cout  << resu << endl;
    return 0;

}