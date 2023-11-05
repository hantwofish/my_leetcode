#include"../STLCOMMON.h"
#include"../TREE.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        TracCengView(root);
        return root;
    }
    // 前序遍历 根左右
    void DFS(Node* root)
    {
        if(root == NULL){
            return;
        }
        cout << root->val << " ";
        DFS(root->left);
        DFS(root->right);
    }
    // 层序遍历
    void TracCeng(Node* root)
    {
        if(root == NULL){
            return;
        }
        queue<Node*>que;
        que.push(root);
        while( !que.empty() ){
            Node* topNode = que.front();
            if(topNode->left) que.push(topNode->left);
            if(topNode->right) que.push(topNode->right);
            cout << topNode->val << " ";
            que.pop();
        }
        cout << endl;
    }
    void TracCengView(Node* root)
    {
        if(root == NULL){
            return;
        }
        queue<Node*>que;
        que.push(root);
        while( !que.empty() ){
            int n = que.size();
            Node* last = NULL;
            for(int i = 0 ; i < n; i++){
                Node* topNode = que.front();
                que.pop();
                if(topNode->left) que.push(topNode->left);
                if(topNode->right) que.push(topNode->right);
                if(i != 0){
                    last->next = topNode;
                }
                last = topNode;
            }
        }
        cout << endl;
    }
};




int main()
{
    Solution s1;
    Node* l1_1 = new Node(1);
    Node* l2_1 = new Node(2);
    Node* l2_2 = new Node(3);
    Node* l3_1 = new Node(4);
    Node* l3_2 = new Node(5);
    Node* l3_3 = new Node(7);
    l1_1->left  = l2_1;
    l1_1->right = l2_2;

    l2_1->left = l3_1;
    l2_1->right = l3_2;
    l2_2->right = l3_3;

    s1.DFS(l1_1);
    cout << endl;
    s1.TracCeng(l1_1);

    Node* root = s1.connect(l1_1);





    cout << "hello" << endl;
    return 0;
}