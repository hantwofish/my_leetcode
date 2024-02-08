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
                if((leftvalu == x && rightval == y) ||(leftvalu == y && leftvalu == x)){
                    return false;
                }
                resu.push_back(it->val);
            }
            if(depth <=1 ) continue; 
            if(find(resu.begin(),resu.end(), leftvalu) != resu.end() && find(resu.begin(),resu.end(), rightval) != resu.end())   {
                return true;
            }



        }

    }
private:    
    queue<TreeNode*>Que;
}

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}