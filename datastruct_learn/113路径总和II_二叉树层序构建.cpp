#include"../STLCOMMON.h"
#include"../TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curResult = 0;
        vector<int> oneResult;
        DFS(root, oneResult, curResult, targetSum);


        return allResult;
    }

    // 当前节点为 一组可能的结果
    void DFS(TreeNode* curNode, vector<int> &oneResult,  int &curResult, int targeSum)
    {

        cout<< "DFS= curResult= " << curResult << endl;
        bool notFind = (find(allResult.begin(), allResult.end(), oneResult) == allResult.end());
        if( curResult  == targeSum ){
            if( notFind && (!oneResult.empty()) && (curNode == nullptr)){
                        cout << "curResult= " << curResult << "  curNode "<< curNode << endl;
                allResult.push_back(oneResult);
            }
        }

        if(curNode== nullptr){
            return;
        }


        // 判断当前节点
        if( curResult + curNode->val > targeSum ){
            return;
        }


        // 遍历左子树
        int curValue = curNode->val;
        cout << " int curValue= " <<  curValue << endl;
        curResult += curNode->val;
        oneResult.push_back(curNode->val);
        DFS(curNode->left, oneResult, curResult, targeSum);
        DFS(curNode->right, oneResult, curResult, targeSum);

        curResult -= curValue;
        oneResult.pop_back();



    }
public:
    vector<vector<int>> allResult;
};

TreeNode* GetOneNode(int val)
{
    if(val == 9999){
        return nullptr;
    }
    TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = val;
    root->left = root->right = nullptr;
    return root;
}


TreeNode* CreatOneTree( vector<int>&nums)
{
    queue<TreeNode*>que;
    if(nums.empty()){
        return nullptr;
    }
    TreeNode* root  = GetOneNode(nums[0]);
    que.push(root);

    int i =1;

    while(!que.empty()){
        if(i >= nums.size()){
            return root;
        }
        TreeNode* top = que.front();
        int temp = nums[i++];
        if(temp != 0){
            top->left = GetOneNode(temp);
            que.push(top->left);
        }
        if(i >= nums.size()){
            return root;
        }
        temp = nums[i++];
        if(temp != 0){
            top->right = GetOneNode(temp);
            que.push(top->right);
        }
        que.pop();
    }
    return root;
}

// 打印整个二叉树,中序遍历
#define KEY(n) (n ? n->val : -1)
void output(TreeNode *root)
{
    if(root == NULL) return;
    printf("(%d; %d,%d)\n",  
        root->val,
        KEY(root->left),
        KEY(root->right)
        );
    output(root->left);
    output(root->right);
}

void Clear(TreeNode* root)
{
    if(root ==  nullptr){
        return;
    }

    Clear(root->left);
    Clear(root->right);
    free(root);
}

int main()
{
    Solution s1;
    vector<int>nums= {1,2};
    TreeNode* root = CreatOneTree(nums);
    output(root);

    vector<vector<int>>resu =  s1.pathSum(root, 1);



    Clear(root);

    cout << "---end---" << endl;
    return 0;
}
