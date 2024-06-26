#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isOk(root->left, root->right);
    }
    bool isOk(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr && right != nullptr) return false;
        if(left != nullptr && right == nullptr) return false;
        if(left->val != right->val) return false;
        return isOk(left->left, right->right) && isOk(left->right, right->left);
    }
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}