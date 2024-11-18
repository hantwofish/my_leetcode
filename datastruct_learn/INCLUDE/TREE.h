#include<stdlib.h>
#include<stdio.h>
#include"./STLCOMMON.h"

/**
 * Definition for a binary tree node.
*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


/**
 * Definition for a binary tree node. */
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class TREEBFS {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> myque;
        myque.push(root);
        int cengnum = 0;
        while(!myque.empty()){
            int sizenume = myque.size();
            vector<TreeNode*>myvec;
           
            // 将相邻的加入队列
            for(int i = 0; i< sizenume; i++){
                TreeNode* topval = myque.front();
                if(topval->left != nullptr)  myque.push(topval->left);
                if(topval->right != nullptr)  myque.push(topval->right);
                myque.pop();
                cout << "topval= " << topval->val << endl;
                if(cengnum %2 ==1){
                    myvec.push_back(topval);
                }
            }
            if(cengnum % 2 ==1){
                for(int i = 0, j = myvec.size()-1; i < j ; i++,j--){
                    swap(myvec[i]->val, myvec[j]->val);
                }
            }


            cengnum++;
            
        }
        return root;
        
    }
};
 class TREEDFS {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }

    void dfs(TreeNode *root1, TreeNode *root2, bool isOdd) {
        if (root1 == nullptr) {
            return;
        }
        if (isOdd) {
            swap(root1->val, root2->val);
        }
        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
    }
};

