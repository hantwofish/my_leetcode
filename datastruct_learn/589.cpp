#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;


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


class Solution {
public:
    vector<int> preorder(Node* root) {
        backtracing(root);
        return resu;
    }
    void backtracing(Node* root)
    {
        if(root == nullptr) return;
        resu.push_back(root->val);
        for(int i=0;i< root->children.size(); i++){
            backtracing(root->children[i]);
        }
    }
private:
    vector<int>resu;
};