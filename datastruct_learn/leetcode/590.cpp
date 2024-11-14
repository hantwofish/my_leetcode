#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"

using namespace std;

class Solution{
public:
    TreeNode* buildTree(vector<int>&pre,vector<int>&mid)
    {
        preOrderArray = pre;
        midOrderArray = mid;
        return makeTree(pre,mid);
    }

    // root 对应的前序遍历序列, 中序遍历序列
    TreeNode* makeTree(vector<int>&leftArray, vector<int>&rightArray)
    {
        if(leftArray.size()==0) return nullptr;

        TreeNode* root = new TreeNode(leftArray[0]);
        if(leftArray.size()==1) return root;

        int root_val = leftArray[0];

        vector<int>left_arry_front;
        vector<int>left_arry_behind;



        // 从中序序列中拆除前一段与后一段
        int index = 0;
        for(index = 0; index< rightArray.size(); index++){
            if(rightArray[index] == root_val){
                break;
            }
        }

        vector<int>right_arry_front;
        vector<int>right_arry_begind;
        for(int i =0; i<index; i++){
            right_arry_front.push_back(rightArray[i]);
        }
        for(int i= index+1; i< rightArray.size(); i++){
            right_arry_begind.push_back(rightArray[i]);
        }


        for(int i =1; i<= right_arry_front.size(); i++){
            left_arry_front.push_back(leftArray[i]);
        }
        for(int i= left_arry_front.size() +1; i< leftArray.size(); i++){
            left_arry_behind.push_back(leftArray[i]);
        }

        root->left =makeTree(left_arry_front, right_arry_front);
        root->right = makeTree(left_arry_behind, right_arry_begind);
       

        return root;
    }
private:   
    vector<int>preOrderArray;
    vector<int>midOrderArray;
};



int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}