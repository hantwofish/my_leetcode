#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class MyCompareMIN{
public:
    bool operator()(vector<int>a , vector<int>b){
        return a[0]+a[1] > b[0]+b[1];
    }
};

class Solution2 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>nums;
        for(int i= 0; i< nums1.size(); i++){
            for(int j= 0; j< nums2.size(); j++){
                minQue.push({nums1[i],nums2[j]});
            }
        }
        vector<vector<int>>resu;
        int cnt = k;
        while(!minQue.empty() && cnt >0){
            // auto it = minQue.top();
            resu.push_back(minQue.top());
            minQue.pop();
            
            cnt--;
        }
        

        return resu;
        
    }
private:
    vector<vector<int>> sortvector(vector<vector<int>>&nums, int k)
    {
        for(int i = 0; i< nums.size(); i++){
            for(int j= i+1; j < nums.size(); j++){
                int sumi = nums[i][0] + nums[i][1];
                int sumj = nums[j][0] + nums[j][1];
                if(sumj < sumi){
                    swap(nums[i],nums[j]);
                }
            }
        }
        for(int i= 0; i< nums.size(); i++){
            cout << "(" << nums[i][0]<< "," << nums[i][1] << ")" << endl;
        }
        vector<vector<int>>resu;
        for(int i=0; i< k && i < nums.size(); i++){
            resu.push_back(nums[i]);
        }
        return resu;

    }
private:

    priority_queue<vector<int>,vector<vector<int>>,MyCompareMIN>minQue;// 小顶堆
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); //小顶堆
        // visited.resize(nums1.size(), vector<bool>(nums2.size(),false));


        for(int i= 0; i < nums1.size();i++){
            pq.push({i,0});
            // visited[i][0] = 1;
            set.insert(to_string(i)+"_"+"0");
        }
        int cnt = k;
        vector<vector<int>>resu;
        while( !pq.empty() && cnt >0){
            auto topval = pq.top();
            pq.pop();
            resu.push_back({nums1[topval.first], nums2[topval.second]});
            
            cnt--;

            int row_cur = topval.first;
            int col_cur = topval.second;
            // cout << "row_cur= " << row_cur << " col_cur=" << col_cur << endl;
            int row_next = topval.first +1;
            int col_next = topval.second +1;
            if(col_next < nums2.size() && 
                // visited[row_cur][col_next] == 0
                (set.find(to_string(row_cur)+"_"+to_string(col_next)) == set.end())
                )
                {
                    pq.push({row_cur,col_next});
                    // visited[row_cur][col_next] = 1;
                    set.insert(to_string(row_cur)+"_"+to_string(col_next));
                    
            }
            if(row_next < nums1.size() &&  
                // visited[row_next][col_cur] == 0
                (set.find(to_string(row_next)+"_"+to_string(col_cur)) == set.end())
                ){
                    pq.push({row_next,col_cur});
                    // visited[row_next][col_cur] = 1;
                    set.insert(to_string(row_next)+"_"+to_string(col_cur));
                    
            }
        }
        return resu;
        
    }
private:
    // priority_queue<vector<int>,vector<vector<int>>,MyCompareMIN>minQue;// 小顶堆
    vector<vector<bool>> visited;
    unordered_set<string> set;

};
int main()
{
    Solution s1;
    vector<int> nums1 ={1,2,4,5,6};
    vector<int> num2 = {3,5,7,9};
    int k =4;
    vector<vector<int>> res = s1.kSmallestPairs(nums1,num2,k);
    MyPrintTwo(res);

    

    cout << "hell22o" << endl;
    return 0;
}