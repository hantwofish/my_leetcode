

#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Spreadsheet {
public:
    Spreadsheet(int rows) {
        vec_array.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]- 'A';
        int row =  stoi( cell.substr(1) ); 
        cout << "setCell col = " << col << " row= " << row << endl;
        vec_array[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]- 'A';
        int row =  stoi( cell.substr(1) ); 
        cout << "resetCell  col = " << col << " row= " << row << endl;
        vec_array[row][col] = 0;
    }
    
    int getValue(string formula) {
        int all_length = formula.length();
        int add_index = 0;
        for(int i =0; i < formula.length(); i++){
            if(formula[i] == '+'){
                add_index =i;
                break;
            }
        }

        string str_X = formula.substr(1, add_index - 1);
        string str_Y = formula.substr(add_index+1);
        cout << "X= " << str_X << "  y= " << str_Y << endl;

        bool x_char = false;
        bool y_char = false;
        if(str_X[0] >= 'A' && str_X[0] <= 'Z'){
            x_char = true;
        }
         if(str_Y[0] >= 'A' && str_Y[0] <= 'Z'){
            y_char = true;
        }
        int resu = 0;
        if(x_char == true && y_char == true){
            resu = get_single_value(str_X) + get_single_value(str_Y);


        }else if(x_char == true && y_char == false){
            resu = get_single_value(str_X) + stoi(str_Y);

        }else if(x_char == false && y_char == true){
            resu = stoi(str_X) + get_single_value(str_Y) ; 

        }else if(x_char == false && y_char == false){
             resu = stoi(str_X) + stoi(str_Y) ; 
        }
        cout << " resu= " << resu << endl;
        return resu;
    }
private:    
    int get_single_value(string formula){
        int col = formula[0]- 'A';
        int row =  stoi( formula.substr(1) ); 
        cout << "resetCell  col = " << col << " row= " << row << endl;
        return vec_array[row][col];
    }
private:
    vector<vector<int>> vec_array;
};

int main()
{

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe