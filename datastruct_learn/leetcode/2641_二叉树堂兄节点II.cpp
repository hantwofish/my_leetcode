#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root ==  nullptr){
            return root;
        }
        Que.push(root);
        QueSum.push(root);
        while(!Que.empty()){
            int sumTemp = 0;
            int num = QueSum.size();
            cout << "QueSum.size()+= " << QueSum.size() << endl;
            for(int i = 0; i< num; i++){
                auto top = QueSum.front();
                cout << "top " << top->val << endl;
                if(top->left) {
                    QueSum.push(top->left);
                    sumTemp += top->left->val;
                } 
                if(top->right){
                    QueSum.push(top->right);
                    sumTemp += top->right->val;                    
                }
                QueSum.pop();                
            }
            cout << "sumTemp= " << sumTemp << endl;

            for(int i = 0; i< num; i++){
                auto top = Que.front();
                cout << top->val << endl;
                int lefetValue = 0;
                int rightValue = 0;
                if(top->left) {
                    Que.push(top->left);
                    lefetValue = top->left->val;
                } 
                if(top->right){
                    Que.push(top->right);
                    rightValue = top->right->val;
                }  
                if(top->left){
                    top->left->val = sumTemp -  lefetValue - rightValue;
                } 
                if (top->right) {
                   top->right->val = sumTemp -  lefetValue - rightValue;
                }
                
                Que.pop();
            }
        }
        root->val = 0;
        return root;
    }
private:
    queue<TreeNode*> Que;
    queue<TreeNode*> QueSum;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell2cddd 2o" << endl;
    return 0;
}