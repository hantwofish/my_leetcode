class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) 
    {
        // 前缀和，索引
        unordered_map<int,int> mapStor;
        int curSum = 0;
        int lengthArray = 0;
        pair<int, int>indexPair;

        for(int i =0 ;i < array.size(); i++){
            string temp = array[i];
            if( "A" <= temp && temp <= "Z"){
                curSum += 1;
            }else{
                // curSum -= 1;
            }
            if(find(mapStor.begin(),mapStor.end(),curSum) == mapStor.end()){ // not found
                // auto pair_1 = make_pair(curSum, i);
                // mapStor.insert(pair_1);
                // mapStor.insert({curSum,i});
            }else{
                // 取出索引
                // int storedIndex = mapStor[curSum];
                // if( storedIndex -(i+1)+ 1 > lengthArray ){
                //     lengthArray = storedIndex - (i+1) + 1;
                //     indexPair.first = i+ 1;
                //     indexPair.second = storedIndex;
                // }


            }

        }

        if(lengthArray == 0){
            return {};
        }

        vector<string> resu;
        for(int index = indexPair.first ; index <= indexPair.second ; index++){
            resu.push_back(array[index]);
        }

        return resu;
    }

public:
    vector<vector<int>>dtatimes;
}