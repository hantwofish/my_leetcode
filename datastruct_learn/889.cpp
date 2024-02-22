#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.empty()) return nullptr;
        return makeTree(preorder,postorder);
    }
    TreeNode* makeTree(vector<int>& preorder, vector<int>& postorder)
    {
        if(preorder.size()==0) return nullptr;
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        vector<int>pre_front;
        vector<int>pre_behind;
        vector<int>post_front;
        vector<int>post_behind;

        int index = 1;
        for(index = 1; index < preorder.size(); index++){
            pre_front.push_back(preorder[index]);
            post_front.push_back(postorder[index-1]);
            set<int>pre_front_set(pre_front.begin(),pre_front.end());
            set<int>pos_front_set(post_front.begin(),post_front.end());
            if(pre_front_set == pos_front_set){
                cout << "index= " << index << endl;
                break;
            } 
        }

        for(int i= pre_front.size()+1; i< preorder.size(); i++){
            pre_behind.push_back(preorder[i]);
        }

        for(int i= post_front.size(); i< postorder.size() -1; i++){
            post_behind.push_back(postorder[i]);
        }

        root->left = makeTree(pre_front,post_front);
        root->right = makeTree(pre_behind, post_behind);
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