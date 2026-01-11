#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

#define N 100

class Mystring{
 
    Mystring(char* input, int length)
    {
        data  = new char(length);
        string_length = length;

    }
    ~Mystring()
    {
        delete data;
    }

public:
    void add_string(char* string1, int length1, char* string, int length2)
    {
        char* old_data = data;
        char* new_data = data;
        if(length1 + length2 > string_length){
            new_data = new char(length1 + length2);
            delete old_data;
            data = new_data;
        }

        for(int i = 0; i < length1; i++){
            data[i] = string1[i];
        }
        for(int j = length1 ; j < length1 + length2; j++){
            data[j] = string[j];
        }
        
    }
    int sub_string( char ** start_pointer ,int start_index, int end_index)
    {   
        if( end_index > string_length ){
            end_index = string_length -1;
        }
        if(start_index < 0){
            start_index = 0;
        }
        *start_pointer = data + start_index;


        return end_index - start_index  + 1;
    }
private:
    char* data;
    int string_length;

    
}



int main()
{

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp