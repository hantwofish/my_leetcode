#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include"../TREE.h"


using namespace std;

class PointCmp{
public:
    bool  operator()(const tuple<int, int,int> &A, const tuple<int, int,int> &B) const // const 不可少, 对于Pair需要将多种情况都讨论
    {
        if(get<1>(A) < get<1>(B) ){
            return true;
        }else if(get<1>(A) == get<1>(B)) {
            if( get<0>(A) < get<0>(B)){
                return true;
            }else if(get<0>(A) == get<0>(B)){
                return get<2>(A) < get<2>(B);
            }
        }else{
            return false;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        que.push({root,{0,0}});
        map<int,vector<int>>myMap;

        while(!que.empty()){
            int quesize = que.size();
            auto ittop = que.front();
           
            int left_index = ittop.second.first;
            int right_index = ittop.second.second;
            int temp_val = ittop.first->val;
            myset.insert({left_index, right_index, temp_val});
            cout << "myset.size= " << myset.size() << endl;


            cout<< "vla= " << ittop.first->val << "(" << ittop.second.first << " " << ittop.second.second << " )" << endl;
            if(ittop.first->left) que.push({ittop.first->left, {ittop.second.first + 1, ittop.second.second -1}});
            if(ittop.first->right) que.push({ittop.first->right, {ittop.second.first + 1, ittop.second.second +1}});
            que.pop();
        }

        auto it = myset.begin();
        while(!myset.empty()){
            it = myset.begin();
            int left_index= get<0>(*it);
            int right_index= get<1>(*it);
            int value = get<2>(*it);
            myMap[right_index].push_back(value);
            myset.erase(it);
        }
        

        
        vector<vector<int>>resu;
        while(!myMap.empty()){
            auto it = myMap.begin();
            resu.push_back(it->second);
            myMap.erase(it->first);
        }

        return resu;
    }
private:
    queue<pair<TreeNode*, pair<int,int>>>que;
    multiset<tuple<int,int,int>> myset;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}