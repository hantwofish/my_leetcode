#include"STLCOMMON.h"
#include"tree.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {


        return 0;
    }
};

int main()
{
    Solution S1;
    TreeNode CurRoot(3);
    TreeNode Cur2_1(3);
    TreeNode Cur2_2(3);
    TreeNode Cur3_3(3);
    TreeNode Cur3_4(3);

    TreeNode *root = &CurRoot;
    root->left = Cur2_1;
    root->right = Cur2_2;



    cout << "end   hh" << endl;
}