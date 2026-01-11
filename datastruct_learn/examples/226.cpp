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
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr){
            // swap_tree_2(root->left, root->right);
        } 
        
        return root;
    }
private:
    void swap_tree_2(TreeNode* root)
    {
        if(root == nullptr) return;

        if(root->left ){
            swap_tree_2(root->left);
        }
        if(root->right){
            swap_tree_2(root->right);
        }
        swap(root->left->val, root->right->val);
    }


    void swap_tree(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr){
            return;
        }
        if(left == nullptr && right != nullptr){

        }
        if(left != nullptr && right == nullptr){

        }
        int temp =  left->val;
        left->val = right->val;
        right->val =  temp;
        swap_tree(left->left, right->right);
        swap_tree(right->left, left->right);
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