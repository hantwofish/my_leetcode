#include"../STLCOMMON.h"
#include"../COMMONALO.h"



using namespace std;

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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        que.push(root);
        vector<int>temp;
        while(!que.empty()){
            temp.clear();
            int timesize =que.size();
            
            for(int i= 0; i< timesize; i++){
                auto it = que.front();
                temp.push_back(it->val);
                que.pop();

                vector<Node*> _children = it->children;
                for(int j =0; j < _children.size(); j++){
                    if(_children[j]) que.push(_children[j]);
                } 
            }
            resu.push_back(temp);

        }
        return resu;
    }
private:
    queue<Node*> que;
    vector<vector<int>>resu;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}