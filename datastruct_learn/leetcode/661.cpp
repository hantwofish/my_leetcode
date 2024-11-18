#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int N = img.size();
        int M = img[0].size();
       vector<vector<int>>resu(N, vector<int>(M, 0));
        cout << "n = " << resu.size() << " " << resu[0].size() << endl;

       for(int i = 0; i< img.size();i++){
        for(int j = 0 ; j < img[0].size();j++){
            // cout << "i= " << i <<  " j = " << j << endl;
            resu[i][j] = CalNum(img, i,j);
        }
       }
       MyPrintTwo(resu) ;
       return resu;
    }
    
    bool isValild(vector<vector<int>>& img, int row, int col)
    {
        int N = img.size();
        int M = img[0].size();
        if(row >= 0 && row < N && col >=0 && col < M){
            // cout << " isValild true " << row << " " << col <<endl;
            return true;
        }
        // cout << " isValild fasle " << row << " " << col <<endl;
        return false;
    }

    int CalNum(vector<vector<int>>& img, int row, int col)
    {
        int times = 0;
        int resu = 0;

        int r = row -1;
        int c = col -1;
        if(isValild(img,r , c)){
            // cout<< "34 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }
        r = row -1;
        c = col + 0;
        if(isValild(img,r , c)){
            // cout<< "41 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row -1;
        c = col + 1;
        
        if(isValild(img,r , c)){
            // cout<< "42 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row + 0;
        c = col - 1;
        if(isValild(img,r , c)){
            // cout<< "43 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row + 0;
        c = col + 0;
        if(isValild(img,r , c)){
            // cout<< "44 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row + 0;
        c = col + 1;
        if(isValild(img,r , c)){
            // cout<< "45 r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row +1;
        c = col -1;
        if(isValild(img,r , c)){
            // cout<< "345r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row + 1;
        c = col + 0;
        if(isValild(img,r , c)){
            // cout<< "rrr r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }

        r = row +1;
        c = col +1;
        if(isValild(img,r , c)){
            // cout<< "rrrb r= " << r << " c= " << c << endl;
            times++;
            resu+= img[r][ c];
        }
        if(times == 0) return 0;
        return resu / times;
    }

};

int main()
{
   Solution s1;
   cout << "main" << endl;
   vector<vector<int>> data ={
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5}
   };
   s1.imageSmoother(data);

   

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe