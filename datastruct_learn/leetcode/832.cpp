#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            int front = 0;
            int end = image[i].size() -1;
            while(front < end){
                swap( image[i][front], image[i][end] );
                front++;
                end--;
            }
        }
        for(int i = 0; i< image.size(); i++){
            for(int j = 0; j < image[i].size(); j++){
                if(image[i][j] == 0){
                    image[i][j] = 1;
                }else{
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
};

int mainFunc()
{
    Solution s1;

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}