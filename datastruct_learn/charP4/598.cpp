#include"../../STLCOMMON.h"
#include"../../TREE.h"

using namespace std;

class Solution {
public:
    vector<int> preorder(Node* root) {
        tracing(root);
        return resu;
    }
    void tracing(Node *root)
    {
        if(root == NULL){
            return;
        }
        resu.push_back(root->val);
        for(int i = 0; i< (root->children).size();i++){
            tracing((root->children)[i]);
        }
        return;
    }
public:
    vector<int>resu;
};

int main()
{
    Solution s1;

    cout << "main End" << endl;
    return 0;
}