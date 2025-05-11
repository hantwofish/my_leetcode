

# 下载并解压源码包
wget http://www.tortall.net/projects/yasm/releases/yasm-1.3.0.tar.gz
tar -zxvf yasm-1.3.0.tar.gz
cd yasm-1.3.0

# 编译安装
./configure --enable-shared
make && sudo make install

yasm --version  # 输出应为 1.3.0 或更高版本


# 下载 FFmpeg 官方二进制包（以 5.0 版本为例）
wget https://www.ffmpeg.org/releases/ffmpeg-5.0.tar.gz
tar -xzf ffmpeg-5.0.tar.gz
cd ffmpeg-5.0

# 编译安装（需安装依赖库）
./configure --enable-shared --prefix=/usr/local/ffmpeg
 -- 或者使用下面命令,禁用x86
#./configure --enable-shared --disable-x86asm --prefix=/usr/local/ffmpeg 
make && sudo make install

# 添加环境变量
echo 'export PATH=/usr/local/ffmpeg/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
# 创建配置文件并写入库路径（需 root 权限）
echo "/usr/local/ffmpeg/lib" | sudo tee /etc/ld.so.conf.d/ffmpeg.conf

# 更新动态链接器缓存
sudo ldconfig
# 验证安装
ffmpeg -version


#you-get -o /home/ xxxurl
#https://www.bilibili.com/video/BV1HHfNYgEaH/?spm_id_from=333.1007.tianma.2-1-4.click&vd_source=089c30965b1a20cea28e1699e381e5f6


