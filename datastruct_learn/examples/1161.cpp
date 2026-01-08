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
// 二叉树层序遍历
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>treeQue;
        TreeNode* node = root;
        treeQue.push(node);
        vector<int>temp;
        while( !treeQue.empty() ){
            
            int que_length = treeQue.size();
            temp.clear();
            for( int i = 0; i< que_length ; i++){
                TreeNode* que_front = treeQue.front();
                if(que_front->left){
                    treeQue.push(que_front->left);
                }
                if(que_front->right){
                    treeQue.push(que_front->right);
                }
                cout << " " << que_front->val ;
                temp.push_back(que_front->val);
                treeQue.pop();
            }
            nums.push_back(temp);
            cout << endl;
            

        }

        MyPrintTwo(nums);
        int result_sum = INT32_MIN;
        int result_index= 0;
        for(int i = 0; i < nums.size(); i++){
            int tem_sum = 0;
            for(int j = 0; j < nums[i].size(); j++){
                tem_sum += nums[i][j];
            }

            if(tem_sum > result_sum){
                result_index = i;
            }

            result_sum = max( result_sum , tem_sum);
            

        }

        cout << "idnex = "<<  result_index << " sum = " << result_sum << endl;
        return result_index + 1;
    }

private:
    vector<vector<int>>nums;
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    Solution S1;
    S1.maxLevelSum(root);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe