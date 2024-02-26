#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;
bool CMP(int& a, int& b)
{
    return a > b;
}

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root ==nullptr) return 0;
        que.push(root);
        while(!que.empty()){
            int nsize = que.size();
            long long temp =0;
            for(int i = 0; i< nsize; i++){
                auto ittop = que.front();
                temp += ittop->val;
                if(ittop->left ) que.push(ittop->left);
                if(ittop->right) que.push(ittop->right);
                que.pop();
            }
            vecArray.push_back(temp);
        }
        sort(vecArray.begin(),vecArray.end(),greater<int>());
        if(vecArray.size() < k){
            return vecArray[vecArray.size()-1];
        }
        return vecArray[k-1];
        
    }
private:
    vector<long long>vecArray;
    queue<TreeNode*>que;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}