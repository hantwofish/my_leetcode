#include<iostream>
#include <time.h>
#include<queue>
#include"../../STLCOMMON.h"
using namespace std;

#define MAX_NODE 10

typedef struct Node{
    int value;
    Node *left;
    Node *right;

}Node;

Node* createNode(int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void clear(Node *root)
{
    if(root ==NULL){
        return;
    }
    clear(root->left);
    clear(root->right);
    return;
}

Node* insert(Node *root, int key)
{
    if(root == nullptr){
        return createNode(key);
    }
    if(rand() % 2) {
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;

}

void BFS(Node* root)
{
    queue<Node*> myQue;
    myQue.push(root);
    while(!myQue.empty()){
        Node* topFront = myQue.front();
        cout << "root " << topFront-> value << endl;
        if(topFront->left){
            cout << "    " << topFront-> left->value << "(left)" << endl;
            myQue.push(topFront->left);
        }
        if(topFront->right){
            cout << "    " << topFront-> right->value << "(right)" << endl;
            myQue.push(topFront->right);
        }
        myQue.pop();
    }
    return;

}

vector<int>font_Vec;
// 前序遍历，根左右
void front_view(Node*root)
{
    if(root == nullptr){
        return;
    }
    font_Vec.push_back(root->value);
    front_view(root->left);
    front_view(root->right);
    return;
}
//中序遍历，左根右
vector<int>mid_vec;
void mid_view(Node*root)
{
    if(root == nullptr){
        return;
    }

    mid_view(root->left);
    mid_vec.push_back(root->value);
    mid_view(root->right);
    return;

}
//后序遍历，左右根
vector<int>behind_vec;
void behind_view(Node*root)
{
    if(root == nullptr){
        return;
    }

    behind_view(root->left);
    behind_view(root->right);
    behind_vec.push_back(root->value);
    return;
}

int main()
{
    srand(time(0));
    Node *root = NULL;
    for (int i = 0; i < MAX_NODE; i++) {
        root = insert(root, rand() % 50);
    }
    BFS(root);
    front_view(root);
    mid_view(root);
    behind_view(root);

    MyPrintOne(font_Vec);
    MyPrintOne(mid_vec);
    MyPrintOne(behind_vec);
    clear(root);
    cout << "end"<< endl;
    return 0;
}