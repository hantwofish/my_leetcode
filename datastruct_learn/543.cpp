#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        recursion(root);
        return resu;
    }
    // 递归，定义以当前节点为拐点，最长路径长度
    int recursion(TreeNode* root)
    {
        // 叶子节点为 0
        if(root->left == nullptr && root->right == nullptr) return 0;
        int left = recursion(root->left) ;
        int right = recursion(root->right) ;
        resu =  max(resu, left + 1 + right +1);
        return left + 1 +right + 1;
    }
private:    
    int resu =0;
};