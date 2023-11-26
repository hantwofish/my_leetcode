#include "../STLCOMMON.h"
#include "../TREE.h"

using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs_search(root);
        // int resu  =0;
        // for(int i = 0; i< allPath.size(); i++){
        //     if(isVaild(allPath[i])){
        //         // cout << "i= " << i <<  endl;
        //         resu++;
        //     }
        // }
        return reresu;
    }
    bool isVaild(vector<int>&temp)
    {

        vector<int>nums = temp;
        sort(nums.begin(), nums.end());
        string tempstr = vec_to_str(nums);
        if(mymap.find(tempstr) != mymap.end()){
            return mymap[tempstr];
        }

        stack<int>stk;
        for(int i = 0; i< nums.size(); i++){
            int cur = nums[i];
            if(stk.empty()){
                stk.push(cur);
            }else {
                if(stk.top()==cur){
                    stk.pop();
                }else{
                    stk.push(cur);
                }
            }    
        }
        bool flag = (stk.size()<=1);
        mymap.insert({tempstr, flag});

        return flag;

    }
    string vec_to_str(vector<int>nums)
    {
        string str= "";
        for(int i = 0; i < nums.size(); i++){
            str = str + to_string(nums[i]) + "_";
        }
        return str;
    }
    void dfs_search(TreeNode* cur)
    {
        if(cur == nullptr){
            return;
        }
        if(cur->left == nullptr && cur->right == nullptr){
            oneSearch.push_back(cur->val);
            // allPath.push_back(oneSearch);
            if(isVaild(oneSearch)){
                reresu++;
            }
            // MyPrintOne(oneSearch);
            oneSearch.pop_back();
            
            return;
        }
        oneSearch.push_back(cur->val);
        //遍历所有相邻的
        if(cur->left){
            dfs_search(cur->left);
        }
        if(cur->right) dfs_search(cur->right);
        oneSearch.pop_back();

    }
public:
    vector<int>oneSearch;
    // vector<vector<int>> allPath;
    int reresu = 0;
    unordered_map<string, bool> mymap;
};

void freeTree(TreeNode *root)
{
    if(root ==NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
    return;
}

vector<int>g_font_Vec;
// 前序遍历，根左右
void front_view(TreeNode* root)
{
    if(root == nullptr){
        return;
    }
    g_font_Vec.push_back(root->val);
    front_view(root->left);
    front_view(root->right);
    return;
}
int main()
{
    Solution s1;
    // [    2,
    // 3,      1,
    // 3,1,  null,1]
    TreeNode* root = new TreeNode(2);
    TreeNode* one_1 = new TreeNode(3);
    TreeNode* one_2 = new TreeNode(1);
    TreeNode* two_1 = new TreeNode(3);
    TreeNode* two_2 = new TreeNode(1);
    TreeNode* two_4 = new TreeNode(1);
    root->left = one_1;
    root->right = one_2;
    one_1->left = two_1;
    one_1->right = two_2;
    one_2->left = nullptr;
    one_2->right = two_4;


    // front_view(root);
    // MyPrintOne(g_font_Vec);
    int resu = s1.pseudoPalindromicPaths(root);

    freeTree(root);

    

    cout << "resu= " << resu  << endl;
    return 0;
}