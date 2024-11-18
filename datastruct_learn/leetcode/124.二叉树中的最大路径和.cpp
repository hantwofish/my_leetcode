#include"../STLCOMMON.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxGrain(root);
        return resu;
    }
    // 当前节点所能贡献的值
    int maxGrain(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int val = root->val;
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGrain(root->left), 0);
        int rightGain = max(maxGrain(root->right), 0);
        resu = max(resu, val+ leftGain + rightGain); // 左 根 右路径
        return max(val+leftGain, val+rightGain);
    }
public:
    int resu = INT32_MIN;
};

int main()
{
    Solution s1;
    

    cout << "hello2" << endl;
    return 0;
}