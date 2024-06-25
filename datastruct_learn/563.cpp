#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "TREE.h"

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
    int findTilt(TreeNode* root) {
        updateTree(root);
        return resu;
    }

    void updateTree(TreeNode* root)
    {
        if(root == nullptr) return;
        root->val = abs(DFSSUM(root->left)-  DFSSUM(root->right));
        resu += root->val;
        updateTree(root->left);
        updateTree(root->right);
    }

    int DFSSUM(TreeNode* cur) // 定义以当前节点的总和
    {
        if(cur == nullptr) return 0;

        
        int left = DFSSUM(cur->left);
        int right = DFSSUM(cur->right);

        return cur->val + left + right;

    }
public:
    int resu = 0;
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