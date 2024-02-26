#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        frontSearch(root);
        int sum =0;
        for(int i =0; i< vec.size(); i++){
            if(vec[i] >= low && vec[i] <= high){
                sum += vec[i];
            }
        }
        return sum;
    }

    void frontSearch(TreeNode* root)
    {
        if(root == nullptr) return;
        frontSearch(root->left);
        vec.push_back(root->val);
        frontSearch(root->right);
    }
private:    
    vector<int>vec;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}