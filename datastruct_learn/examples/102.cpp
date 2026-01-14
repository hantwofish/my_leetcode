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
    vector<vector<int>> levelOrder(TreeNode* root) {
             if(root == nullptr) return {};
        queue<TreeNode*> my_que;
        my_que.push(root);
        while(!my_que.empty()){
            temp.clear();
            int N = my_que.size();
            for(int i = 0; i < N; i++){
                TreeNode* it_frond = my_que.front();
                temp.push_back(it_frond->val);
                cout << it_frond->val << " ";
                if(it_frond->left) my_que.push(it_frond->left);
                if(it_frond->right) my_que.push(it_frond->right);
                my_que.pop();

            }
            result.push_back(temp);
        }        
        return result;
    }
private:
    vector<int>temp;
    vector<vector<int>>result;
    vector<int>result_Out;
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