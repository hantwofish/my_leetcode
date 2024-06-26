#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

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
;

void timer_function(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    // std::cout << "Timer expired after " << seconds << " seconds" << std::endl;
    
    cout << endl;
    cout << "[error] timer " <<  seconds << " is over exit " << endl;
    exit(1);
}



class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = dfs(root, 0);
        cout << "depth= " << depth << endl;
        return ans;
    }
    int dfs(TreeNode* node, int depth)
    {
        if(node == nullptr){
            maxDepth = max(maxDepth,depth);
            return depth;
        }
        int leftMaxDepth = dfs(node->left, depth+1);
        int rightMaxDepth = dfs(node->right, depth +1);
        if(leftMaxDepth == rightMaxDepth && leftMaxDepth == maxDepth){
            ans = node;
        }
        return max(leftMaxDepth, rightMaxDepth);
    }
private:
    TreeNode* ans;
    int maxDepth = -1;
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