#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        Que.push(root);
        int depth = 0;
        vector<int>resu;
        while(!Que.empty()){
            resu.clear();
            depth++;
            int nums = Que.size();
            int leftvalu = -1;
            int rightval =-1;
            for(int i=0; i< nums; i++){
                auto it = Que.front();

                if(it->left) {
                    Que.push(it->left);
                    leftvalu = it->left->val;
                }
                if(it->right){
                    Que.push(it->right);
                    rightval = it->right->val;      
                }
                cout << " val= " << it->val << " left= " << leftvalu << " right= " << rightval << endl; 
                if((it->left && it->right && leftvalu == x && rightval == y) ||(it->left && it->right && leftvalu == y && rightval == x)){
                    return false;
                }
                resu.push_back(it->val);
                Que.pop();
            }
            if(depth <=1 ) continue; 
            if(find(resu.begin(),resu.end(), x) != resu.end() && find(resu.begin(),resu.end(), y) != resu.end())   {
                return true;
            }
        }
        return false;
    }
private:    
    queue<TreeNode*>Que;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}