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
    int maxDepth(TreeNode* root) {
        int depth  = 0;
        queue<TreeNode*> queue_tree;
        if(root == nullptr) return 0;
        queue_tree.push(root);
        while(!queue_tree.empty()){
            int N = queue_tree.size();
            for(int i = 0; i< N; i++){
                TreeNode* it = queue_tree.front();
                if(it->left) queue_tree.push(it->left);
                if(it->right) queue_tree.push(it->right);
                cout << it->val << " " ;
                queue_tree.pop();
            }
            depth++;
        }

        cout << "depth= " << depth << endl;
        return depth;

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