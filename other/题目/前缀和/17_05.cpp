#include"../STLCOMMON.h"

using namespace std;


class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) 
    {
        // 前缀和，索引
        unordered_map<int,int> mapStor;
        vector<int> arraySum(array.size()+1, 0);
        // 区间为左闭右开[left,right)
        // sum[i] = [0, i)
        for(int i = 0; i< array.size(); i++){
            int diff = 0;
            diff = ( ('A' <= array[i][0] && array[i][0] <= 'Z')||('a' <= array[i][0] && array[i][0] <= 'z')) ?  1 : -1;
            arraySum[i+1] = arraySum[i] + diff;
        }
        int beginIndex= 0;
        int endinDex = 0;
        for(int i =0 ; i < arraySum.size(); i++){
            int tempSum = arraySum[i];
            auto resu= mapStor.find(tempSum);
            if(resu == mapStor.end()){
                mapStor[arraySum[i]] = i;
            }else if(i - resu->second > endinDex - beginIndex){
                beginIndex = resu->second;
                endinDex = i;
            }

            
        }
        return {array.begin()+ beginIndex, array.begin()+ endinDex};
    }
};

class Solution2 {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int n = array.size(), s[n + 1]; // 前缀和
        s[0] = 0;
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + (array[i][0] >> 6 & 1) * 2 - 1;

        int begin = 0, end = 0; // 符合要求的子数组 [begin,end)
        unordered_map<int, int> first;
        for (int i = 0; i <= n; ++i) {
            auto it = first.find(s[i]);
            if (it == first.end()) // 首次遇到 s[i]
                first[s[i]] = i;
            else if (i - it->second > end - begin) // 更长的子数组
                begin = it->second, end = i;
        }
        return {array.begin() + begin, array.begin() + end};
    }
};

class Solution3 {
public:
    vector<string> findLongestSubarray(vector<string>& array) 
    {
        // 前缀和，索引
        unordered_map<int,int> mapStor;
        vector<int> arraySum(array.size()+1, 0);
        // 区间为左闭右开[left,right)
        // sum[i] = [0, i)
        for(int i = 0; i< array.size(); i++){
            int diff = 0;
            diff = ( ('A' <= array[i][0] && array[i][0] <= 'Z')||('a' <= array[i][0] && array[i][0] <= 'z')) ?  1 : -1;
            arraySum[i+1] = arraySum[i] + diff;
        }
        int beginIndex= 0;
        int endinDex = 0;
        for(int i =0 ; i < arraySum.size(); i++){
            int tempSum = arraySum[i];
            auto resu= mapStor.find(tempSum);
            if(resu == mapStor.end()){
                mapStor[arraySum[i]] = i;
            }else if(i - resu->second > endinDex - beginIndex){
                beginIndex = resu->second;
                endinDex = i;
            }

            
        }
        return {array.begin()+ beginIndex, array.begin()+ endinDex};
    } 
};

class Solution4 {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int N = array.size();
        vector<int>frontSum(N+1,0);
        for(int i = 0;i < array.size(); i++){
            if(IsChar(array[i])){
                frontSum[i+1] = frontSum[i] + 1; 
            }else{
                frontSum[i+1] = frontSum[i] - 1; 
            }
        }
        MyPrintOne(frontSum);
        int frontIndex = 0;
        int seconIndex = 0;
        int maxLength = 0;
        unordered_map<int,int> sumMap;
        for(int i = 0; i< frontSum.size() ; i++){
            int curSum = frontSum[i]; //[0,i]的和。左右均闭合
            auto it = sumMap.find(curSum);
            if(it == sumMap.end()){
                sumMap.insert({curSum,i});
            }else if( i - it->second > maxLength  ){
                maxLength = i - it->second;
                frontIndex = it->second + 1;
                seconIndex = i;
            }
        }

        vector<string> resu;
        if(maxLength == 0){
            return resu;
        }
        for(int  i = frontIndex -1; i<= seconIndex -1 ; i++){
            resu.push_back(array[i]);
        }
        return resu;
        //return {array.begin()+(frontIndex-1), array.begin()+(seconIndex)};
    }

    bool IsChar(string str)
    {
        if("A" <= str && str <= "Z"){
            return true;
        }else if("a" <= str && str <= "z"){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    Solution4 s1;
    vector<string> array = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    vector<string> resu = s1.findLongestSubarray(array);
    MyPrintOne(resu);

    int sum = 0;
    for(int i =0 ;i < resu.size(); i++){
        string temp = resu[i];
        if( ( ('A' <= temp[0] && temp[0] <= 'Z')||('a' <= temp[0] && temp[0] <= 'z'))){
            sum += 1;
        }else{
            sum -= 1;
        }
    }
    cout << " ++++=sum=  " << sum  << endl;
    return 0;
}
/*
https://leetcode.cn/problems/find-longest-subarray-lcci/solution/bi-zhao-yan-jing-xue-shu-li-hua-qian-zhu-5gyy/


*/

