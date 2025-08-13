

模板函数
D:\my_leetcode\datastruct_learn\leetcode\00_00.cpp

# clear &&  g++ --std=c++11 00_00.cpp -o main.exe && ./main.exe
# cls;  g++ --std=c++11 2187.cpp -o main.exe ; .\main.exe
# del *.exe


代码开发在main 分支

开发前：pull
开发后：upload

新增分支: branch_learning



--------------------------
+++++++++++++++++++++++++++++++++++++++++++++++++ pull +++++++++++++++++++++++++++++++++++++++++++++++++
git checkout main
git pull origin main
git checkout home_learnig
git reset --hard origin/main
git push -f origin home_learnig

+++++++++++++++++++++++++++++++++++++++++++++++++ upload +++++++++++++++++++++++++++++++++++++++++++++++++
@echo off
setlocal enabledelayedexpansion
 
:: 获取当前日期和时间
for /f "tokens=2 delims==" %%I in ('wmic OS Get localdatetime /value') do set datetime=%%I
 
:: 格式化日期时间
set year=%datetime:~0,4%
set month=%datetime:~4,2%
set day=%datetime:~6,2%
set hour=%datetime:~8,2%
set minute=%datetime:~10,2%
set second=%datetime:~12,2%
set datetime=%year%-%month%-%day% %hour%:%minute%:%second%
 
:: 拼接字符串
set finalString=%datetime%--update
 
:: 打印字符串
echo %finalString%
 


git add .
echo %finalString%
git restore --staged *.sh
git restore --staged *.bat
git commit -m "%finalString%"
git push origin branch_learning

endlocal

