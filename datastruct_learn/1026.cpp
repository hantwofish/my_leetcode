#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"



using namespace std;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxval_left =  dismax(root->left);
        int maxval_right = dismax(root->right);
        int min_left =  dismin(root->left);
        int min_right =  dismin(root->right);

        cout << "val= " <<  root->val << " maxleft= "<< maxval_left << " maxright= " << maxval_right << " minleft= " << min_left << " minright= " << min_right << endl;
        int max_val =  max(maxval_left, maxval_right);
        int min_val = min(min_left, min_right);
        resu = max(resu, max(abs(root->val - max_val), abs(root->val - min_val)));
        return resu;
    }
private:
    int dismax(TreeNode* root)
    {
        if(root == nullptr) return INT32_MIN;
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        int maxval = INT32_MIN;
        maxval = max(maxval, root->val);
        int left_max = INT32_MIN;
        if(root->left){
            left_max =  dismax(root->left);
            maxval= max(maxval,left_max);
        }

        int right_max = INT32_MIN;
        if(root->right){
            right_max  = dismax(root->right);
            maxval = max(maxval, right_max );
        }
        cout << " val= " << root->val << " leftmax= " << left_max << " rightmax= " << right_max << endl;
        if(right_max != INT32_MIN){
            resu = max(resu,abs(root->val - right_max));
        }
        if(left_max != INT32_MIN){
            resu = max(resu, abs(root->val - left_max));
        }
        return maxval;
    }
    int dismin(TreeNode* root)
    {
        if(root == nullptr) return INT32_MAX;
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        int minval = INT32_MAX;
        minval = min(minval, root->val);
        int left_min = INT32_MAX;
        if(root->left){
            left_min = dismin(root->left);
            minval= min(minval, left_min);
        }
        int right_min = INT32_MAX;
        if(root->right){
            right_min = dismin(root->right);
            minval = min(minval, right_min);
        }
        cout << " val= " << root->val << " leftmin= " << left_min << " rightmin= " << right_min << endl;
         if(right_min != INT32_MAX){
            resu = max(resu,abs(root->val - right_min));
        }
        if(left_min != INT32_MAX){
            resu = max(resu, abs(root->val - left_min));
        }
        return minval;
    }
private:
    int resu = INT32_MIN;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}