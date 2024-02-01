#include"../STLCOMMON.h"

using namespace std;
typedef struct Node {
    int key;
    Node* lchild;
    Node* rchild;
} Node;


#define KEY(n) (n ? n->key : -1)

Node *getNewNode(int key)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}


// 释放所有节点
void clear(Node *root)
{
    if(root == NULL){
        return;
    }
    // 递归释放左子树’
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return;
}


// 打印整个二叉树,中序遍历
void output(Node *root)
{
    if(root == NULL) return;
    printf("(%d; %d,%d)\n",  
        root->key,
        KEY(root->lchild),
        KEY(root->rchild)
        );
    output(root->lchild);
    output(root->rchild);
}


// 向二叉搜索树中插入一个节点，返回插入节点后的二叉树的根节点
Node *insert(Node* root, int key)
{
    if(root == NULL){
        return getNewNode(key);
    }
    if(key < root->key){
        root->lchild =  insert(root->lchild, key);
    }else if(key > root->key){
        root->rchild = insert(root->rchild, key);
    }else{
        return root;
    }

    return root;
}


Node *predecessor(Node *root)
{
    Node *temp = root->lchild;
    while(temp ->lchild ){
        temp = temp->lchild;
    }
    return temp;
}

// 删除 值为key 的节点，返回删除节点后二叉搜素树的根节点
Node *erase(Node *root, int key)
{
    if(root == NULL){
        return root;
    }
    if(key < root->key){ // 则key 在左子树
        root->lchild =  erase(root->lchild, key);
    }else if(key > root->key){ // 则 key 在右子树
        root->rchild =  erase(root->rchild, key);
    }else{ // 相等情况，则此节点为要删除的节点
        // 如果为叶子节点，直接删除
        if(root->lchild == NULL && root->rchild == NULL){
            free(root);
            return NULL;
        }else if(root->lchild == NULL || root->rchild == NULL){ // 出度为1
            Node *temp = root->lchild ? root->lchild : root ->rchild;
            free(root);
            return temp;
        }else{ // 出度为2
            // 先找到中序遍历的前一个节点：
            Node* temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, key);
        }

    }


    return root;

}

void PintTree(Node* root)
{
    if(root == NULL){
        return;
    }
    if(root ->lchild){
        PintTree(root->lchild);
    }
    printf("%d ", root->key);
    if(root->rchild){
        PintTree(root->rchild);
    }
}

int main()
{
    vector<int> nums = {3,2,4,6,8,5,1};
    Node *root = NULL;
    for(int  i = 0; i < nums.size(); i++){
        root = insert(root, nums[i]);
    }
    output(root);
    PintTree(root);


    return 0;
}