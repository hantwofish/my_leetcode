#include"../STLCOMMON.h"
// #include"../COMMONALO.h"


using namespace std;

struct CmpByValueMax {
    bool operator()(const pair<int, int>&k1, const pair<int, int>&k2) const
    {
        if(k1.second < k2.second){ //升序排列
            return true;
        }else if (k1.second == k2.second) {
            return k1.first < k2.first;
        }
        return false;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
         allnum = n * m;
        figuredata.resize(allnum, vector<int>(allnum,MAXVALUE));
        for(int i = 0; i< n; i++){
            for(int j= 0; j < m; j++){
                get4dif(heights, i,j);
            }
        }
        MyPrintTwo(figuredata);

        CalAllDistance(0, figuredata, allnum);

        return distance_arr[allnum-1] ;
    }
    void get4dif(vector<vector<int>>& heights, int i, int j)
    {
        pair<int,int>left = make_pair(i, j-1);
        pair<int,int>right = make_pair(i, j+1);
        pair<int,int>front= make_pair(i-1, j);
        pair<int,int>behind = make_pair(i+1, j);
        if(isVaild(left)){
            int cur =  i*m +j;
            int endinde = left.first * m + left.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[left.first][left.second]);
        }
        if(isVaild(right)){
            int cur =  i*m +j;
            int endinde = right.first * m + right.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[right.first][right.second]);
        }
        if(isVaild(front)){
            int cur =  i*m +j;
            int endinde = front.first * m + front.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[front.first][front.second]);
        }        
        if(isVaild(behind)){
            int cur =  i*m +j;
            int endinde = behind.first * m + behind.second;
            figuredata[cur][endinde] = abs(heights[i][j] - heights[behind.first][behind.second]);
        }
    }
    bool isVaild(pair<int,int>pr)
    {
        if( pr.first < 0 || pr.first >= n  ) return false;
        if( pr.second < 0 || pr.second >= m  ) return false;
        return true;
    }
    void CalAllDistance(int start_index, vector<vector<int>>&figureInfo, int n)
    {
        distance_arr.resize(n, MAXVALUE);
        flag_arr.resize(n,false);
        prenode.resize(n, -1);

        for(int i = 0 ; i< n;i++){
            distance_arr[i] = figuredata[start_index][i];
            flag_arr[i] =  false;
            if(distance_arr[i] == MAXVALUE){
                prenode[i] = -1;
            }else {
                prenode[i] = start_index;
            }
        }
        distance_arr[start_index] = 0;
        flag_arr[start_index] = true; // 加入s 集合

        for(int i =0 ; i < n; i++){
            if(flag_arr[i] == true) continue;
            mymap.insert({{i, distance_arr[i]},i});
        }




        for(int i = 1; i< n; i++){ // 一共需要遍历次数，

            // 从 v-s 集合中找 dis 中最小的值,以及节点 t
            int tempvalue = MAXVALUE;
            int tempindex = start_index;
            // for(int j = 0; j < n ;j++){
            //     if(flag_arr[j] == true) continue; // 在 s 集合中

            //     if(distance_arr[j] < tempvalue){
            //         tempvalue = distance_arr[j];
            //         tempindex = j;
            //     }
            // } // 找最小替换成优先队列
            if(!mymap.empty()){
                pair<int, int>topvale = (*mymap.begin()).first;
                tempindex = topvale.first;
                tempvalue = topvale.second;
                cout << "index=  "  << tempindex << " value= " << tempvalue << endl;
                
            }else{
               return;
            }
            


            // if(tempindex == start_index) return; // 没有找到，不联通
            // 将最小的加入的 S集合
            flag_arr[tempindex] = true;
            mymap.erase({tempindex,tempvalue});

            // 对 s 集合松弛操作
            for(int j = 0; j < n ; j++){
                // if(figureData[tempindex][j] == MAXVALUE) continue;
                // int newpathvale = distance_arr[tempindex] + figuredata[tempindex][j];
                int newpathvale = max(distance_arr[tempindex], figuredata[tempindex][j]); // 定义新路径的值
                if( !flag_arr[j] && newpathvale < distance_arr[j]){
                    mymap.erase({j,distance_arr[j]});
                   mymap[{j,newpathvale}] = newpathvale;
                    distance_arr[j] = newpathvale;
                    prenode[j] = tempindex;
                    
                    
                }
            }
        }
        MyPrintOne(distance_arr);
    }
public:
    vector<vector<int>>figuredata;
    int n;
    int m;
    int allnum;
    vector<vector<int>>minDistance;
    int MAXVALUE = 0x3f3f3f3f;
    vector<int>distance_arr;
    vector<bool>flag_arr;
    vector<int>prenode;
    map<pair<int,int>,int, CmpByValueMax>mymap; // key ,vale ,key
    

};


int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<vector<int>> heights = {
        {1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}
        };
    s1.minimumEffortPath(heights);

    

    cout << "hell22o" << endl;
    return 0;
}