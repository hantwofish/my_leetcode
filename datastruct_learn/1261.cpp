#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class FindElements {
public:
    FindElements(TreeNode* root) {
        rootTemp =root;
        root->val = 0;
        vec.push_back(0);
        DFS(root);
    }
    
    bool find(int target) {
        // vec.clear();
        // Search(rootTemp);

        // for(auto i: vec){
        //     cout << "val= " << i << endl;
        // }

        if(  std::find(vec.begin(), vec.end(), target) != vec.end()  ){
            return true;
        }
        return false;
    }
    void Search(TreeNode* root)
    {
        if(root == nullptr) return;
        vec.push_back(root->val);
        Search(root->left);
        Search(root->right);
    }

    void DFS(TreeNode* root)
    {
        if(root == NULL) {
            return;
        }
        // cout << "root->val= " << root->val << endl;
        if(root->left) {
            root->left->val = 2 * root->val + 1;
            vec.push_back(root->left->val);
        }
        if(root->right){
            root->right->val = 2 * root->val + 2;
             vec.push_back(root->right->val);
        }
        DFS(root->left);
        DFS(root->right);
    }
private:
    TreeNode* rootTemp;
    vector<int>vec;
};

int main()
{
    // Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}