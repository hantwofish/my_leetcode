import matplotlib.pyplot as plt

# # 数据
# x = [12.03, 12.04, 12.05]
# y = [1.3076, 1.2706, 1.2096]

# # 创建图表
# plt.plot(x, y, marker='*', linestyle='--') 


# # 添加标题和标签
# plt.title("input-output")
# plt.xlabel("time axis")
# plt.ylabel("value axis")

# # 显示图表
# plt.show()


# # 示例数据
# x = [1, 2, 3, 4, 5]
# y = [10, 20, 25, 30, 40]

# # 绘制折线图，部分点设置为圈号标记
# plt.plot(x, y, marker='*', linestyle='-', color='blue', label='yyy')
# plt.plot(x, y, marker='o', markersize=10, markerfacecolor='red', linestyle='-', color='blue', label='xxxx')

# plt.title("部分数据点设置为圈号标记")
# plt.xlabel("X")
# plt.ylabel("Y")
# plt.legend()
# plt.show()

# 示例数据
# # 数据
x = [12.03, 12.04, 12.05, 12.17, 12.19]
y = [1.3076, 1.2706, 1.2096, 1.2578, 1.2345]

# 绘制折线图，部分点设置为叉号标记
plt.plot(x, y, marker='o', linestyle='-', color='blue', label='input')
# plt.plot([x[2], x[4]], [y[2], y[4]], marker='x', markersize=10, markerfacecolor='red', linestyle='none', color='red', label='output')

plt.title("cord")
plt.xlabel("time")
plt.ylabel("cost")
plt.legend()
plt.show()



# you-get --playlist -o E:\ https://www.bilibili.com/video/BV1SMe3zjEPj/?spm_id_from=333.1387.favlist.content.click&vd_source=089c30965b1a20cea28e1699e381e5f6