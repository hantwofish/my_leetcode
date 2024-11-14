#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        que.push(root);
        vector<int>temp;

        while(!que.empty()){
            int numsize = que.size();
            temp.clear();
            for(int i= 0; i< numsize; i++){
                auto ittop = que.front();
                temp.push_back(ittop->val);
                que.pop();
                if(ittop->left) que.push(ittop->left);
                if(ittop->right) que.push(ittop->right);
            }
            resu.push_back(temp);
        }
        reverse(resu.begin(), resu.end());
        return resu;
    }
private:
    vector<vector<int>>resu;
    queue<TreeNode*>que;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}