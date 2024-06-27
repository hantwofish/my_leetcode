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




// 两次中序遍历，第一次保存结果，第二次更新
class Solution {
public:
    void recoverTree(TreeNode* root) {
        midTracing(root);
        sort(nodeVec.begin(),nodeVec.end());
        cout << " ------" << endl;
        midTracing2(root);
        return;
    }
    void midTracing(TreeNode* root)
    {
        if(root == nullptr) return;

        midTracing(root->left);

        cout << "val = " << root->val << endl;
        nodeVec.push_back(root->val);
        midTracing(root->right);
    }

    void midTracing2(TreeNode* root)
    {
        if(root == nullptr) return;

        midTracing2(root->left);

        cout << "val = " << root->val << endl;
        if(root->val != nodeVec[index]){
            cout << "root val = " << root->val << " " << nodeVec[index] << endl;
            root->val = nodeVec[index];
            
        }
        index++;
        midTracing2(root->right);
    }
private:    
    vector<int>nodeVec;
    int index = 0;
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