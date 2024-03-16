cd 数据结构学习
# rm -rf *.exe

###########################
find . -name "*.exe" -exec rm {} \;
find . -name "tempCodeRunnerFile.cpp" -exec rm {} \;
#

###########################
rm -f test.exe
g++ --std=c++11 ./数据结构学习/lcr112.cpp -o ./test.exe
./test.exe

###########################
bash rm_exe.sh
git status
git add .
# git add *.cpp *.txt *.sh *.md *.h
# git restore --staged  *.json


git commit -m "stashx"
git push origin main 
git status
