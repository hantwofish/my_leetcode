#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>resu;
        vector<int>temp;
        if(root == nullptr) return {};
        que.push(root);
        int times = 0;
        while(!que.empty()){
            temp.clear();
            int timesize = que.size();
            for(int i= 0; i< timesize; i++){
                auto it = que.front();
                temp.push_back(it->val);
                if(it->left) que.push(it->left);
                if(it->right) que.push(it->right);
                que.pop();
            }
            if(times % 2 == 1){
                reverse(temp.begin(), temp.end());
            }
            resu.push_back(temp);
            times++;
        }
        
        return resu;


    }
private:
    queue<TreeNode*>que;
};