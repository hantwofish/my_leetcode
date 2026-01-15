#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int result = INVALID_VAL;
        for(int i =01; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                result = min(result, abs(nums[i]- nums[j]));
            }
            

        }
        return result;
    }
    void dfs(TreeNode* root)
    {
        if(root == nullptr) return;
        cout << root->val << " ";
        nums.push_back(root->val);
        int val = root->val;
        int lef_val = INVALID_VAL;
        int righ_val = INVALID_VAL;
        if(root->left) lef_val= root->left->val;
        if(root->right) righ_val= root->right->val;

        if( root->left != nullptr || root->right != nullptr){
            min_diff = min(min_diff, min( abs(val - lef_val), abs( val - righ_val) ) );
        }
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
private:
    int min_diff = INT32_MAX / 2;
    int INVALID_VAL = INT32_MAX / 2;
    vector<int>nums;
};

int main()
{

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp