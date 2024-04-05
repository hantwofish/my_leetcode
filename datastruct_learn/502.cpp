#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
bool CMP(pair<int,int>& a, pair<int,int>& b)
{
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        return a.second > b.second;
    }
    return false;
}

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        for(int i= 0; i< profits.size(); i++){
            vec.push_back({capital[i] ,profits[i]});
        }
        sort(vec.begin(), vec.end(),CMP);
        
        for(int i = 0 ; i< vec.size(); i++){
            cout << " " << vec[i].first <<  " -> " << vec[i].second << endl;
        }


        int cur_w = w;
        int chose_index = 0;
        for(int i = k; i > 0; i--){
            if(vec.empty() ||   cur_w < vec[0].first){
                return cur_w;
            }
            for(int j = 0; j < vec.size(); j++){
                if(vec[j].first <= cur_w &&  vec[j].second > vec[0].second){
                    chose_index = j;
                }
            }
            cur_w += vec[chose_index].second;

            vec.erase(vec.begin() + chose_index);
        }
        cout << "cur_w= " << cur_w << endl;
        return cur_w;
    }
private:
    vector<pair<int,int>>vec;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    int k = 1, w = 2;
    vector<int> profits = {1,2,3}; 
    vector<int> capital = {1,1,2};
    s1.findMaximizedCapital(k,w, profits, capital);

    
    

    cout << "hell22o" << endl;
    return 0;
}