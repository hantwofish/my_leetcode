#include"../STLCOMMON.h"
using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        spaceNum =n;
        string temp(spaceNum,'.');
        vector<string>oneResult(spaceNum, temp);


        DFS(0, 0, oneResult);

        return  allResult;
    }

    // 当前棋盘是否合法
    bool isVaild(vector<string>& platm)
    {
        int n = platm.size();
        // 检查行
        for(int i = 0; i< n; i++){
            string tem = platm[i];
            int Qnum= 0;
            for(int j = 0; j < tem.size();j++){
                if(tem[j] == 'Q'){
                    Qnum++;
                    if(Qnum >=2){
                        return false;
                    }
                }
            }
        }
        
        // 检查列
        for(int i = 0; i< n; i++){ // 列
            int Qnum= 0;
            for(int j = 0; j < n;j++){ // 行
                if(platm[j][i] == 'Q'){
                    Qnum++;
                    if(Qnum >=2){
                        return false;
                    }
                }
            }
        }

        // 检查正斜行 
        for(int i = 0; i< spaceNum; i++){
            int row = i;
            int col = 0;
            int QuNum = 0;
            while(row >= 0 && col < spaceNum){
                if(platm[row][col] == 'Q'){
                    QuNum++;
                    if( QuNum >=2 ){
                        return false;
                    }
                }
                row--;
                col++;

            }
        }

        int i = spaceNum-1; // 行
        for(int j = 1; j < spaceNum; j++){
            int row = i;
            int col = j;
            int QuNum = 0;
            while(row >= 0 && col < spaceNum){
                if(platm[row][col] == 'Q'){
                    QuNum++;
                    if( QuNum >=2 ){
                        return false;
                    }
                }
                row--;
                col++;

            }
        }

        // 检查反斜行
        for(int i = 0; i< spaceNum; i++){
            int row = i;
            int col = 0;
            int QuNum = 0;
            while(row < spaceNum && col < spaceNum){
                if(platm[row][col] == 'Q'){
                    QuNum++;
                    if( QuNum >=2 ){
                        return false;
                    }
                }
                row++;
                col++;

            }
        }

        i = 0;
        for(int j = 1; j < spaceNum; j++){
            int row = i;
            int col = j;
            int QuNum = 0;
            while(row < spaceNum && col < spaceNum){
                if(platm[row][col] == 'Q'){
                    QuNum++;
                    if( QuNum >=2 ){
                        return false;
                    }
                }
                row++;
                col++;

            }
        }

        return true;

    }
    void DFS(int curRow, int col, vector<string>&oneResult)
    {
        cout << "curRow= " << curRow << " col= " << col << endl;
        MyPrintOne(oneResult);


        if(curRow >= spaceNum ){
            allResult.push_back(oneResult);
            return;
        }

        // 往下一列放置皇后
        for(int i = col; i < spaceNum; i++){
            oneResult[curRow][i] = 'Q';
            if(isVaild(oneResult)){
                DFS(curRow + 1, 0, oneResult);
                oneResult[curRow][i] = '.';
            }else{
                oneResult[curRow][i] = '.';
            }
        }
        
        // DFS(curRow+1, 0, oneResult);

        // 往当前行当前列放置皇后
        // oneResult[curRow][col] = 'Q';
        // if( isVaild(oneResult) ){
        //     cout << " isVaild(oneResult) " << endl;
        //     DFS(curRow+1, 0, oneResult);
        // }
        // oneResult[curRow][col] = '.';

    }

public:
    vector<vector<string>> allResult;
    int spaceNum ;
};

int main()
{
    Solution s1;
    int N = 8;
    vector<vector<string>> resu = s1.solveNQueens(N);

    cout << "---end----" << endl;
    MyPrintTwo(resu);
    cout << "---end----" << endl;
    return 0;
}