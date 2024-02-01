#include"../STLCOMMON.h"
#include"../TREE.h"
/*
           root 
        /       \
        [p,q]

           root 
        /       \
                [p,q]
           root 
        /       \
        [p]      [q]
*/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        TreeNode* leftRoot = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightRoot = lowestCommonAncestor(root->right,p ,q);

        if(leftRoot == NULL)  // 不在左子树中，则在右子树中
            return rightRoot;
        if(rightRoot == NULL) // 不在右子树中，则在左子树中
            return leftRoot;      
        if(leftRoot && rightRoot) // p和q在两侧
            return root;        
        return nullptr;
    }
};

int main()
{
    Solution s1;
    // printf("%d\n", INT32_MAX - pow(10,9));
    // cout << INT32_MAX - pow(10,9) << endl;
    vector<int> rootVec = {3,5,1,6,2,0,8,INT32_MAX,INT32_MIN,7,4};
    int p = 5;
    int q = 1;
    
    
    cout << "end" << endl;
    return 0;
}