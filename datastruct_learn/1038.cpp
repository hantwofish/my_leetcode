#include"../STLCOMMON.h"
#include"../TREE.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        MidSearch(root);
        calFrrontSum(nums);
        for(int i = 0; i< nums.size(); i++){
            mymap.insert({nums[i], i});
        }
        SeachFront(root);
        return root;
    }
    void SeachFront(TreeNode* root)
    {
        if(root  == nullptr) return;
        SeachFront(root->left);
        root->val = calSumByVal(root->val);
        SeachFront(root->right);
    }

    int getSumByforntsum(int i, int j)
    {
        if(i == 0) return frontsumArry[j];
        return frontsumArry[j] - frontsumArry[i-1];

    }
    int calSumByVal(int val)
    {
        int index = mymap[val];
        return getSumByforntsum(index, nums.size()-1);
    }
    void MidSearch(TreeNode* root)
    {
        if(root == nullptr) return;
        MidSearch(root->left);
        nums.push_back(root->val);
        MidSearch(root->right);
    }
    int calFrrontSum(vector<int>&nums)
    {
        frontsumArry.resize(nums.size(),0);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) {
                frontsumArry[i] = nums[0];
                continue;
            }
            frontsumArry[i] = frontsumArry[i-1] + nums[i];
        }
        
        return 0;
    }

public:
    vector<int>nums;
    vector<int>frontsumArry;
    unordered_map<int, int>mymap;// <val, index>
};


  

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}