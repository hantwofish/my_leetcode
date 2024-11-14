#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        midSerch(root);
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < vec.size(); i++){
            // if(vec[i] >= k) return false;
            for(int j = i+1; j < vec.size(); j++){
                if(vec[i] + vec[j] == k) return true;
                // if(vec[i] + vec[j] > k)  break;;
            }
        }
        return false;

    }
private:
    vector<int>vec;
    void midSerch(TreeNode *root)
    {
        if(root == nullptr) return;
        midSerch(root->left);
        vec.push_back(root->val);
        midSerch(root->right);
    }
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}