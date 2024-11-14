#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(inorder.empty()) return nullptr;
        return makeTree(inorder, postorder);
    }
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size()==0) return nullptr;
        int val = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(val);

        int index= 0;
        for(index = 0; index< inorder.size(); index++){
            if(inorder[index] == val) break;
        }
        vector<int>inorder_front;
        vector<int>inorder_behind;
        vector<int>postorder_front;
        vector<int>postorder_behind;

        for(int i=0; i< index; i++){
            inorder_front.push_back(inorder[i]);
        }
        for(int i = index+1; i < inorder.size(); i++){
            inorder_behind.push_back(inorder[i]);
        }

        for(int i= 0; i< inorder_front.size(); i++){
            postorder_front.push_back(postorder[i]);
        }
        for(int i=postorder_front.size(); i < postorder.size()-1 ; i++){
            postorder_behind.push_back(postorder[i]);
        }


        root->left = makeTree(inorder_front, postorder_front);
        root->right = makeTree(inorder_behind, postorder_behind);
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