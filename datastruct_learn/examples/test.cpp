#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

#define IN 1
#define OUT 0


class ETf_jijin{

public:
    void updat_today_price(double peice)
    {
        today_price = peice;
    }
    void in_or_out_record( double price,double num, bool is_in)
    {
        in_out_map[is_in].push_back({price, num});
    } 
    void print_total_Cal()
    {
        int in_times = in_out_map[IN].size();
        int out_times = in_out_map[OUT].size();

        cout << "in_times= " << in_times << " out_times= " << out_times << endl;
        int chi_Cang_fenshu = 0; // 当前持仓份数
        double chengben_price = 0; // 当前每股持仓价格

        double in_cost_origin = 0; // 累计买入成本；
        double out_get = 0; // 卖出累计金额

        double in_Cost_rate_num = 0 ;// 买入佣金

        double profile = 0; // 利润 = 卖出累计金额 + 当前持仓金额 - 累计买入成本；

        cout << "------------------------------交易-买入---------------" << endl;
        for(int i = 0; i< in_out_map[IN].size(); i++){
            double in_price  = in_out_map[IN][i].first;
            int in_fenshu = in_out_map[IN][i].second;
            double in_val = in_price * in_fenshu ;

            double diff_num = 0.5;
            if(in_val >= 10000){
                diff_num = in_val * (5.0 / 10000);  
            }else{
                diff_num = 0.5;
            }
            cout << "i= " << i << " 买入价格=  " << in_price << " 买入份数 =  " << in_fenshu  <<"买入花费 " << in_val << " 佣金= " << diff_num << endl;

            chi_Cang_fenshu += in_fenshu;
            buy_num.push_back(in_val);
            in_cost_origin += (in_val) ;
            in_Cost_rate_num += diff_num; 
        }

        chengben_price = (in_cost_origin + in_Cost_rate_num) /chi_Cang_fenshu;

        cout << "买入花费 =  " << in_cost_origin << " 佣金= " << in_Cost_rate_num << " 持仓份数= " << chi_Cang_fenshu << " 持仓每股成本单价=" << chengben_price << endl;

        cout << "------------------------------交易-卖出---------------" << endl;
        in_Cost_rate_num = 0;
        for(int i = 0; i< in_out_map[OUT].size(); i++){
            int in_fenshu = in_out_map[OUT][i].second;
            double in_price  = in_out_map[OUT][i].first;
            double out_val = in_price * in_fenshu ;

            double diff_num = 0.5;
            if(out_val >= 10000){
                diff_num = out_val * (5.0 / 10000);  
            }else{
                diff_num = 0.5;
            }

            chi_Cang_fenshu -= in_fenshu;
            solue_num.push_back(out_val - diff_num);
            cout << "i= " << " out_val= " << out_val << " 佣金：" << diff_num << endl;
            out_get += (out_val) - diff_num; 
        }
        cout << "卖出总得到 =  " << out_get << " 当前持仓份数= " << chi_Cang_fenshu << " 持仓金额= " << (chi_Cang_fenshu * today_price) << endl;


        double chi_cang_profile =  (today_price - chengben_price) * chi_Cang_fenshu;
        cout << "持仓利润= " << chi_cang_profile << endl;

        cout << "--总买入卖出交易--" << endl;
        double total_in = 0;
        double total_out = 0;
        cout << "IN: " ;
        for(int i = 0;i < buy_num.size(); i++){
            cout << buy_num[i] << " ";
            total_in +=buy_num[i];
        }
        cout << endl;
         cout << "OUT: " ;
        for(int i = 0;i < solue_num.size(); i++){
            cout << solue_num[i] << " ";
            total_out +=solue_num[i];
        }
        cout << endl;

        cout << "清仓利润= " << (total_out - total_in) + chi_Cang_fenshu * today_price  << endl;
        
    }

    void cal_profile(double price1, double price2, int num)
    {
        double pro =  (price2 - price1) * num;
        double up_rate = (price2 - price1) * 100 / price1;
        double down_rate = (price1 - price2) * 100 / price2;
        cout  << up_rate << "%  " << down_rate << "% "<< endl;
        cout  << price1 << " -> " << price2 << " num= " << num << " pro=" << pro << endl;

        // cout << ""
        

    }
private:
    const double COST = 0.5; // 固定金额0.5
    unordered_map<bool, vector< pair<double,double>> > in_out_map;

    double today_price = 0; // 每股今日报价
    vector<double>buy_num;
    vector<double>solue_num;


};

class GuPiao{

public:
    void updat_today_price(double peice)
    {
        today_price = peice;
    }
    void in_or_out_record(double num, double price, bool is_in)
    {
        today_price = price;
        in_out_map[is_in].push_back({price, num});
        
        double mai_ru_cheng_ben = 0; // 买入成本
        double chi_cang_fen_shu = 0; // 持仓份数
        
        double profile_rate = 0; // 利润率
        double li_run = 0;
        double mai_chu_dedao = 0;


        for(int i = 0; i< in_out_map[IN].size(); i++){
            chi_cang_fen_shu += (in_out_map[IN][i].second * in_out_map[IN][i].first * (1- buyrate)) / in_out_map[IN][i].first;
            // cout << in_out_map[IN][i].first << " " <<  in_out_map[IN][i].second << endl;
            mai_ru_cheng_ben += (in_out_map[IN][i].first * in_out_map[IN][i].second); 
        }

        for(int i = 0; i< in_out_map[OUT].size(); i++){
            chi_cang_fen_shu -= in_out_map[OUT][i].second;
            mai_chu_dedao += ((in_out_map[OUT][i].first * in_out_map[OUT][i].second)) * (1- outrate); 
        }

        cout << "_______________________" << endl;
        cout << "持仓份数=" << chi_cang_fen_shu << " 当前价格=" << today_price << " 卖出得到=" << mai_chu_dedao << " 当前估值= " << chi_cang_fen_shu * today_price << endl;
        cout << "买入成本=" << mai_ru_cheng_ben << " 利润=" << chi_cang_fen_shu * today_price + mai_chu_dedao - mai_ru_cheng_ben << endl;
        

    
        
        
        // double cost_val = chi_cang_fen_shu * today_price;
        
        // cout << chi_cang_fen_shu << " * " << (mai_ru_cheng_ben / chi_cang_fen_shu) << " = " << mai_ru_cheng_ben << endl;
        // cout << cost_val - mai_ru_cheng_ben << " rate= " << (cost_val - mai_ru_cheng_ben) / mai_ru_cheng_ben * 100 << "%" << endl;

    }

private:
    const double buyrate = 0.001; // 0.1%
    const double outrate = 0.005; // 0.5%

    // const double buyrate = 0; // 0.%
    // const double outrate = 0; // 0%
    unordered_map<bool, vector< pair<double,double>> > in_out_map;
    double today_price = 0; // 今日股价


};
// i= 99
// _______________________
// 持仓份数=500 当前价格=7.8 卖出得到=390000 当前估值= 3900
// 买入成本=384305 利润=9595
// _______________________
// 持仓份数=1000 当前价格=7.61 卖出得到=390000 当前估值= 7610
// 买入成本=388110 利润=9500

int main()
{
     

    // GuPiao gong_shang_yin_hang; // 601398 工商银行

    // gong_shang_yin_hang.in_or_out_record(1000, 34.12, IN);

    // for(int i= 1; i <= 90;i ++){
    //     cout << "i= " << i << endl;
    //     gong_shang_yin_hang.in_or_out_record(500, 35.65, OUT);
    //     gong_shang_yin_hang.in_or_out_record(500, 34.12, IN);
    // }
    // gong_shang_yin_hang.in_or_out_record(1000, 7.81, OUT);

    cout << "---------start ------------------" << endl;

    ETf_jijin e1;
    
    e1.in_or_out_record(1.491, 1000, IN);
    e1.in_or_out_record(1.501, 100, IN);
    e1.in_or_out_record(1.502, 100, IN);

    e1.in_or_out_record(1.516, 600, OUT);



    double today_price = 1.497;
    e1.updat_today_price(today_price);
    e1.print_total_Cal();



    cout << "[info] main end ..." << endl << endl;

    e1.cal_profile(1.494, 1.62, 600);

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 鎷疯礉鏂囦欢锛�./file_run.sh 00_00.cpp
// 杩愯鏂囦欢  ./file_copy.sh  00_00.cpp