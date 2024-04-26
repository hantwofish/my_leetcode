#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        FrontVisitedAll(root);
        // PrintMap();

        int tiems = BfsVisited(start);
        return tiems -1;
    }
    int BfsVisited(int start)
    {
        int time = 0;
        queue<int>myQue;
        set<int>Visited;

        int opTimes = 0;
        myQue.push(start);
        Visited.insert(start);

        while( !myQue.empty()){
            int N =myQue.size();
            opTimes++;
            for(int i= 0; i< N; i++){
                // 相邻的入队
                int frontVal = myQue.front();
                vector<int>neighHord = figureData[frontVal];
                for(int j = 0 ; j < neighHord.size(); j++){
                    if(Visited.find(neighHord[j]) != Visited.end()) continue; // is visited 
                    myQue.push(neighHord[j]);
                    Visited.insert(neighHord[j]);
                }
                // 出队
                myQue.pop();
            }
        }
        return opTimes;
    }

    void FrontVisitedAll(TreeNode* root)
    {
        if(root == nullptr){
            return;
        }
        // cout << root->val << endl;
        if(root->left){
            figureData[root->val].push_back(root->left->val);
            figureData[root->left->val].push_back(root->val);
        }
        if(root->right){
            figureData[root->val].push_back(root->right->val);
            figureData[root->right->val].push_back(root->val);
        }
        FrontVisitedAll(root->left);
        FrontVisitedAll(root->right);
    }
    void PrintMap()
    {
        auto it = figureData.begin();
        while(it != figureData.end()){
            cout << it->first << " | " ;
            vector<int>temp = it->second;
            for(int i = 0; i< temp.size(); i++){
                cout << temp[i] << " ";
            }
            cout << endl;
            it++;
        }
    }
private:
    unordered_map<int, vector<int>>figureData;
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}