#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;
// 给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。

// 请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：

// mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
// maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        frontSearch(root);
        vector<vector<int>>resu;
        for(int i = 0; i< queries.size(); i++){
            resu.push_back({bindFindMin(queries[i]), bindFindMax(queries[i])});
        }
        return resu;
    }
    int bindFindMin(int val)
    {
        int leftBound = 0;
        int rightBound = vec.size()-1;
        if(val < vec[leftBound]){
            return -1;
        }

        int resu = 0;
        while(leftBound <= rightBound){
            int mid = leftBound + (rightBound - leftBound) /2;
            if( vec[mid] == val ) {
                return vec[mid];
            }else if(vec[mid] > val){
                rightBound = mid -1;
            } else if(vec[mid] < val){
                resu = max(resu, mid);
                leftBound = mid +1;
            }
        }
        return vec[resu];
    }
    int  bindFindMax(int val)
    {
        int leftBound = 0;
        int rightBound = vec.size()-1;
        if(val > vec[rightBound]){
            return -1;
        }

        int resu = vec.size()-1;
        while(leftBound <= rightBound){
            int mid = leftBound + (rightBound - leftBound) /2;
            if( vec[mid] == val ) {
                return  vec[mid];
            }else if(vec[mid] > val){
                resu = min(resu, mid);
                rightBound = mid -1;
            } else if(vec[mid] < val){                
                leftBound = mid +1;
            }
        }
        return vec[resu];
    }

    void frontSearch(TreeNode* root)
    {
        if(root == nullptr) return;
        frontSearch(root->left);
        vec.push_back(root->val);
        frontSearch(root->right);
    }
private:    
    vector<int>vec;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}