#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

// 层序遍历
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> myque;
        myque.push(root);
        int cengnum = 1;
        while(!myque.empty()){
            int sizenume = myque.size();
            vector<TreeNode*>myvec;
            // 将相邻的加入队列
            for(int i = 0; i< sizenume; i++){
                TreeNode* topval = myque.front();
                if(topval->left != nullptr)  myque.push(topval->left);
                if(topval->right != nullptr)  myque.push(topval->right);
                myque.pop();
                cout << "topval= " << topval->val << endl;
                if(cengnum %2 ==1){
                    myvec.push_back(topval);
                }
            }
            if(cengnum % 2 ==1){
                for(int i = 0, j = myvec.size()-1; i < j ; i++,j--){
                    swap(myvec[i]->val, myvec[j]->val);
                }
            }


            cengnum++;
            
        }
        return root;
        
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}