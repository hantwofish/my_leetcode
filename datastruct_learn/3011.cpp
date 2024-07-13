//#include"../STLCOMMON.h"
//#include"../COMMONALO.h"
#include <iostream>
//#include <chrono>
//#include <thread>
//#include "../TREE.h"
#include <algorithm>
#include <vector>
#include <string>
#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    bool canSortArray(vector<int>& nums) {	
		int front = 0;
		int behind = front ;
		while( behind <= front  && front < nums.size() ){
			  	if(numOne(toBinary(nums[front]) ) == numOne(toBinary(nums[behind]))   ){
					front++;
					if( front ==  nums.size() ){
						sort(nums.begin() + behind, nums.begin() + front );
						break;

					}
					continue;

				}
				// 排序
				sort(nums.begin() + behind, nums.begin() + front );
					

				behind =  front;

		}
		
		for(int i = 0;	i <nums.size(); i++){
			cout << nums[i] <<" " ;
		}		
		cout << endl;		

		bool resu = true;
		for(int i = 1; i <nums.size(); i++){
			if(nums[i] <nums[i-1]) return false;
			
		}
			

		return true;        
    }

	int numOne(string str)
	{
		int resu = 0;
		for(int i = 0; i< str.size(); i++){
			if(str[i] == '1') resu++;
		}
		return resu;
	}

    int oneNumOf(int num)
	{
		int resu = 0;
		int val = 1;
		while(num != 0){
			if(num & val != 0) resu++;
			val << 1;
	
		}		
		return resu;
	
	}
	string toBinary(int num)
	{
		string r = "";
		while(num != 0){
		r += (num %2 == 0 ? "0" : "1");
		num /= 2;
	
		}	
		return r;
	}
	
};


int mainFunc()
{
    Solution s1;
    vector<int>nums = {8,4,2,30,15};
 	s1.canSortArray(nums);

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
