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
    bool isSymmetric(TreeNode* root) {
        Search(root);
        MyPrintTwo(result);
        for(int i = 0 ; i< result.size(); i++){
            bool flag = vec_Is_equal(result[i]);
            if(flag == false)  return false;
        }
        
        return true;
    }
    bool vec_Is_equal(vector<int>nums)
    {
        int N = nums.size();
        if(N == 1){
            return true;
        }
        if(N %  2== 1) return false;
        for(int i = 0 ;i < N /2; i++){
            if(nums[i] != nums[N-1-i] ){
                return false;
            }
        }
        return true;
    }
    void Search(TreeNode* root)
    {
        queue<TreeNode* >myque;
        myque.push(root);
        vector<int>temp;
        // temp.push_back(root->val);
        // cout << root->val << " ";
        // result.push_back(temp);

        while(!myque.empty()){
            int N = myque.size();
            
            temp.clear();
            for(int i = 0 ; i < N; i++){
                auto it_front = myque.front();
                if(it_front == nullptr){
                    cout << "N" << " ";
                    temp.push_back(INVAL_VAL);
                    myque.pop();
                    continue;
                }
                cout << it_front->val << " ";
                temp.push_back(it_front->val);

                if(it_front->left && it_front->right){
                    myque.push(it_front->left);
                    myque.push(it_front->right);
                }
                if(it_front->left== nullptr && it_front->right){
                    myque.push(nullptr);
                    myque.push(it_front->right);
                }
                if(it_front->left && it_front->right == nullptr){
                    
                    myque.push(it_front->left);
                    myque.push(nullptr);
                }

                
                myque.pop();
            }
            result.push_back(temp);
        }

    
    }
private:
    vector<vector<int>>result;
    int INVAL_VAL = -200;
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    Solution s1;
    s1.isSymmetric(root);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp