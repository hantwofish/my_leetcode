#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return resu;
    }
    void dfs(TreeNode* cloned, TreeNode* target)
    {
        if(cloned == NULL) return;
        if(cloned->val ==  target->val) {
            resu = cloned;
        }
        dfs(cloned->left, target);
        dfs(cloned->right, target);
    }

private:
    TreeNode* resu;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}