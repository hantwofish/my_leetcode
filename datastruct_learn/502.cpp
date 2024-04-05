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

class MyCompareMAX{
public:
    bool operator()(pair<int , int>a , pair<int , int>b){
        return a.second < b.second;
    }
};

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
        int cur_index =  0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompareMAX>maxQue;// 大顶堆 按照利润排序
        for(cur_index = 0; cur_index < vec.size(); cur_index++){
            if(vec[cur_index].first <= cur_w){
                maxQue.push(vec[cur_index]);
            }else{
                break;
            }   
        }

        for(int i = k; i > 0; i--){
            if(maxQue.empty()){
                return cur_w;
            }
            
            
            cur_w += maxQue.top().second;
            maxQue.pop();

            for(;cur_index < vec.size(); cur_index++){
                if(vec[cur_index].first <= cur_w){
                    maxQue.push(vec[cur_index]);
                }else{
                    break;
                }
            }

            
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