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
    bool isValidBST(TreeNode* root) {
        if(root== nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->left && root->left->val >= root->val) return false;
        if(root->right && root->right->val <= root->val) return false;

        if(all_small_val(root->left, root->val)  == false ) return false;
        if(all_big_val(root->right, root->val)  == false ) return false;

        return isValidBST(root->left) & isValidBST(root->right);
    }
    bool all_small_val(TreeNode* root, int val)
    {
        
        if(root == nullptr) return true;
        if(root->val >= val) return false;

        return all_small_val(root->left, val) & all_small_val(root->right, val);
    }
    bool all_big_val(TreeNode* root, int val)
    {
        
        if(root == nullptr) return true;
        if(root->val <= val) return false;

        return all_big_val(root->left, val) & all_big_val(root->right, val);
    }
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