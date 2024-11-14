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



class Solution {
public:
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        if(root == nullptr) return {};
        vector<int>curpth;
        curpth.push_back(root->val);
        backTracing(root, curpth, root->val, target);

        return result;
    }
private:
    vector<vector<int>>result;
    // 当位于此节点的时候需要做什么，当前 cur_val 已是包含此节点值
    void backTracing(TreeNode* cur_node, vector<int>cur_path, int cur_val, int target)
    {
        if(cur_val == target && cur_node->left == nullptr && cur_node->right == nullptr){
            MyPrintOne(cur_path);
            result.push_back(cur_path);
        }

        // 处理左子树 
        if(cur_node->left){

            cur_val += cur_node->left->val;
            cur_path.push_back(cur_node->left->val);
            backTracing(cur_node->left, cur_path, cur_val, target);
            cur_val -= cur_node->left->val;
            cur_path.pop_back();
        }

        // 处理右子树
        if(cur_node->right){

            cur_val += cur_node->right->val;
            cur_path.push_back(cur_node->right->val);
            backTracing(cur_node->right, cur_path, cur_val, target);
            cur_val -= cur_node->right->val;
            cur_path.pop_back();
        }

        
    }
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