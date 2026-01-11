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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is_same = sub_is_same(p, q);
        
        return is_same;
    }
    bool sub_is_same(TreeNode* tree1, TreeNode* tree2)
    {
        if(tree1 != nullptr && tree2 == nullptr){
            return false;
        }
        if(tree1 == nullptr && tree2 != nullptr){
            return false;
        }
        if(tree1 == nullptr && tree2 == nullptr ){
            return true;
        }
        if(tree1 != nullptr && tree2 != nullptr){
            if(tree1->val != tree2->val){
                return false;
            }
        }
        return sub_is_same(tree1->left, tree2->left) && sub_is_same(tree1->right, tree2->right);

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