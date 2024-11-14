#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}


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
    bool isCompleteTree(TreeNode* root) {
        
        Bfs(root);

        return ans;
    }
    void Bfs(TreeNode* root)
    {
        queue<TreeNode*>que;
        que.push(root);
        bool exisEmpty = false;// 第一个空节点之后不能出现非空节点，否则 return false;
        while(!que.empty()){
            int n =que.size();
            
            for(int i = 0; i< n; i++){
                TreeNode* topVal = que.front();
                // if(topVal->left ) leftFill = true;

                if(topVal->left == nullptr && topVal->right){
                    ans = false;
                    return;
                }

                if(exisEmpty && topVal->left ){
                    ans = false;
                    return;
                }

                if(topVal->left == nullptr ){
                    exisEmpty = true;
                }

                if(exisEmpty && topVal->right ){
                    ans = false;
                    return;
                }

                if(topVal->right == nullptr ){
                    exisEmpty = true;
                }


                if(topVal->left) que.push(topVal->left);
                if(topVal->right) que.push(topVal->right);
                que.pop();
            }
        }
    }
private:
    bool ans = true;
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{
    std::cout << "[info] Starting timer for " << TIMEINTERVAL << " seconds" << std::endl << std::endl;
    std::thread timer_thread(timer_function, TIMEINTERVAL); // 设置计时器延时 TIMEINTERVAL 秒

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    timer_thread.join(); // 等待计时器线程完成
    std::cout << "[info] Timer thread finished" << std::endl;
    return 0;
}