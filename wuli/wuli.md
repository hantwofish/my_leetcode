## 物理学上册
### 第一章：质点运动学

+ 质点

+ 位置矢量：
$
\overrightarrow{r}=x\overrightarrow{i}+y\overrightarrow{j}+z\overrightarrow{k}
$
$
\text{大小：}\left| \overrightarrow{r} \right|=\sqrt{x^2+y^2+z^2}
$
$
\text{方向：}\cos \alpha =\frac{x}{\left| \overrightarrow{r} \right|}, \cos \beta =\frac{y}{\left| \overrightarrow{r} \right|}\,\,, \cos \gamma =\frac{z}{\left| \overrightarrow{r} \right|}
$
运动方程：
$ \overrightarrow{r}\left( t \right) =x\left( t \right) \overrightarrow{i}+y\left( t \right) \overrightarrow{j}+z\left( t \right) \overrightarrow{k} $

位移：
$$
\varDelta r=\overrightarrow{r_B}-\overrightarrow{r_A}
$$

圆周运动：

1-3 相对运动


2-1 牛顿定律

2-4 牛顿定律的应用举例
![alt text](image-31.png)
![](img/2025-06-20-16-14-09.png)



3-1 质点和质点系的动量定理
`动量定理`： 在给定的时间间隔内，外力作用在质点上的冲量($I=\int_{t1}^{t2}{\overrightarrow{F}dt}$)，等于质点在此时间内动量的增量($m\overrightarrow{v_2}-m\overrightarrow{v_1}$)

$$
I=\int_{t1}^{t2}{\overrightarrow{F}dt}=m\overrightarrow{v_2}-m\overrightarrow{v_1}
$$

`质点系动量定理`：作用于系统的合外力的冲量=系统动量的增量

3-4 动能定理

4-1 刚体的定轴转动
刚体：在外力作用下，形状和大小都不会变化的物体。
刚体的运动形式：平动和转动




### 电磁学

库伦定律
$$
\overrightarrow{F}=\frac{1}{4\pi \epsilon _0}\frac{q_1q_2}{r^2}\overrightarrow{e_r}
$$
方向：同性相斥，异性相吸

电场强度:
$$
\overrightarrow{E}=\frac{\overrightarrow{F}}{q_0}
$$
电场中某点的电场强度$\overrightarrow{E}$等于该点处的单位试验电荷所受的电场力


电场强度叠加原理
点电荷系所激发的电场中某点处的电场强度等于各个点电荷单独存在时对该点所激起的电场强度的**矢量和**


+ 点电荷电场强度
$$
\overrightarrow{E}=\frac{1}{4\pi \epsilon _0}\frac{Q}{r^2}\overrightarrow{e_r}
$$

+ 电荷连续分布的电场
$$
d\overrightarrow{E}=\frac{1}{4\pi \epsilon _0}\frac{dq}{r^2}\overrightarrow{e_r}\,\, \Rightarrow \overrightarrow{E}=\int{\frac{1}{4\pi \epsilon _0}}\frac{\overrightarrow{e_r}}{r^2}dq
$$
$$
\text{电荷体密度} \rho \,\,\text{：} dq=\rho dV
\\
\text{电荷面密度} \sigma \,\,\text{：} dq=\sigma dS
\\
\text{电荷线密度} \lambda \,\,\text{：} dq=\lambda dl
$$


+ 电偶极子的电场强度


+ 电场线：
```
切线方向为电场强度方向
疏密表示电场强度的大小

始于正电荷，止于负电荷，非闭合线
任何两条电场线不相交 
```
+ 电场强度通量
定义：通过电场中某个面的电场线数
 记作：$\Phi_{e}$

$$
\Phi_{e}=E\cdot S
$$
积分形式：
$$
\Phi_{e}=\int_{S}^{}E\cdot dS=\int_{S}^{}Ecos\theta dS
$$

#### 高斯定理
![alt text](image-23.png)
在真空静电场中，穿过任意`闭合曲面`的电场强度通量 = 该闭合曲面所包围的所有电荷的代数和除以$\epsilon_0$

### 静电场的环路定理和电势能
+ 静电场力所做的功：
静电场力做功，与路径无关

+ 静电场的环路定理
沿闭合路径一周，电场力做功为零。(静电场是保守场)

+ 电势能：
沿电场线方向，电势降低，电场力做正功，电势能减小。
实验电荷再电场中某处的电势能 == 把它从该点移动到零势能处静电场力所做的功

![alt text](image-24.png)
![alt text](image-25.png)
![alt text](image-26.png)

1. 电势能是个参考量，与零电势的选取有关
2. 

#### 电势
电场中某一点$A$的电势$V_{A}$等于把单位正试验电荷从点$A$ 移动到无限远处(电势为0)，静电力所做的功;记作：
$$
V_{A}=\int_{A\infty}^{}E\cdot dl
$$

电势差：两点电势的差值：$U_{AB}=V_{A}-V_{B}$
静电场中 A、B两点的电势差$U_{AB}$ 在数值上等于把单位正试验电荷从A移动到B ，静电场力做的功；

计算电势的方式：
![alt text](image-27.png)

+ 等势面：
电场中电势相等的点所构成的面。


静电平衡条件：
```
1. 导体内部任何一点处的电场强度为0
2. 导体表面处电场强度的方向，都与导体表面垂直
推论：
导体内各点电势相等
导体表面为等势面
```

+ 电容：
孤立导体的电容为孤立导体所带电荷Q与其电势V的比值
$$
C=\frac{Q}{V}
$$
2. 电容器的电容：
电容器的电容为电容器一块极板所带电荷Q与极板电势差VA-VB的比值
$$
C=\frac{Q}{V_A-V_B}=\frac{Q}{U}\,\, U=\int_{AB}{\overrightarrow{E}\cdot d\overrightarrow{l}}
$$
电容器的大小仅于导体的形状，相对位置其间的电介质有关，和所带的电荷量无关。
![alt text](image-28.png)

静电场的能量？？？

### 第七章
+ 电流：
通过截面S的电荷随时间的变化率
$ I=\frac{dq}{dt} $
$ dq=env_ddtS $
$ v_d $: 电子漂移速度的大小

磁感强度：$ \vec{B} $
运动电荷在磁场中受力：
$ \overrightarrow{F}=q\overrightarrow{v}\times \vec{B} $


毕奥萨伐尔定律
$$
d\overrightarrow{B}=\frac{\mu _0}{4\pi}\frac{Id\overrightarrow{l}\times \overrightarrow{r}}{r^3}
$$

+ 有限载流长直导线的磁场
![alt text](image-29.png)
$$
B=\frac{\mu _0I}{4\pi r_0}\left( \cos \theta _1-\cos \theta _2 \right) 
$$
$$
\text{无限长：}\theta _1\rightarrow 0, \theta _2\rightarrow \pi \,\,
$$

$$
\text{半无限长：}\theta _1\rightarrow \frac{\pi}{2}, \theta _2\rightarrow \pi 
$$

+ 圆形载流导线轴线上的磁场
![alt text](image-30.png)
$$
B=\frac{\mu _0IR^2}{2r^3}, r=\sqrt{x^2+R^2}
$$
1. 若线圈有N圈，
$ B=\frac{N\mu _0IR^2}{2r^3}, r=\sqrt{x^2+R^2} $
2. $x=0\text{时，}B=\frac{\mu _0I}{2R} $
3. $ x\gg R\text{，}B=\frac{\mu _0IR^2}{2x^3} $

推广：


+ 运动电荷的磁场


7-5 磁通量和磁场的高斯定理
1. 磁感线
切线方向: $ \vec{B} $的方向
疏密程度: $ \vec{B} $的大小

2. 磁通量
垂直通过某曲面的磁感线数；
匀强磁场：$\varPhi =\overrightarrow{B}\cdot \overrightarrow{S}$
一般情况：$\varPhi =\int_S{\overrightarrow{B}\cdot d\overrightarrow{S}}$

磁场高斯定理：$\oint_S{\overrightarrow{B}\cdot d\overrightarrow{S}}=0$
通过任意闭合曲面的磁通量为0

安培环路定理

$$
\oint_S{\overrightarrow{B}\cdot d\overrightarrow{l}=\mu _0\sum_{i=1}^n{I_i}}
$$
在真空的恒定磁场中，磁感强度$\overrightarrow{B}$沿任一闭合路径的积分的值，等于$\mu _0$乘以该闭合路径所穿过的各电流的代数和(电流I的正负，与磁场方向满足右手螺旋准则)

![](img/2025-06-20-10-02-13.png)


带电粒子在电场和磁场中受力分析：
电场力：$\overrightarrow{F_e}=q\overrightarrow{E}$
磁场力(洛伦兹力)：$\overrightarrow{F_m}=q\overrightarrow{v}\times \overrightarrow{B}$ 方向的另外一种判断方式(左手定则：伸出左手，磁场线穿手心，四指指向电流方向，大拇指所致的方向为洛伦兹力方向)

安培力：(各个粒子所受洛伦兹力的合力)

$$
d\overrightarrow{F}=Id\overrightarrow{l}\times \overrightarrow{B}
$$

磁场作用于载流线圈的磁力距 ？？？

磁介质 
$$
\overrightarrow{B}=\overrightarrow{B_0}+\overrightarrow{B}'
$$
![](img/2025-06-20-10-31-15.png)

### 第八章：电磁感应 电磁场
电磁感应定律：
当穿过闭合回路所围面积的磁通量发生变化时，回路中会产生感应电动势，且感应电动势正比于磁通量对时间变化率的负值
$$
E_i=-k\frac{d\varPhi}{dt}
$$

楞次定律：
闭合的导线回路中所出现的感应电流，总是使它自己激发的磁场反抗任何引发电磁感应的原因(反抗相对运动，磁场变化或者线圈变形)

动生电动势:
动生电动势的非静电力场来源---> 洛伦兹力

导体中的正负电子受到洛伦兹力的影响，聚集在导体两端产生电压差。此时电子同时受到电场力和洛伦兹力当两者相等时，电压稳定。

![](img/2025-06-20-10-59-44.png)
![](img/2025-06-20-11-00-00.png)

感生电动势？？？

+ 自感 -- 自感电动势：


+ 互感 -- 互感电动势 



### 第九章：振动
#### 简谐振动
简谐振动的依据：$ F=-kx $
微分形式：
![alt text](image-13.png)
简谐振动方程：$x=A\cos\left(\omega t+\varphi\right)$
$$ v=\frac{\mathrm{d}x}{\mathrm{d}t} $$
$$ a=\frac{d^2x}{\mathrm{d}t^2} $$

A:振幅
T:周期：$ T=\frac{2\pi}{\omega} $ 其中：弹簧振子: $ \omega=\sqrt{\frac{k}{m}} $
$\nu$:频率: $ \nu=\frac{1}{T} $
$\omega t+\varphi$: 振动的相位
$\varphi$: 初相位

#### 单摆和复摆
$$ \frac{d^2\theta}{dt^2}=-\frac{g}{l}\theta $$
$ \omega=\sqrt{\frac{x}{l}} $
$ T=\frac{2\pi}{\omega}=2\pi\sqrt{\frac{x}{l}} $
#### 简谐振动的能量
![alt text](image-14.png)


### 第十章：波动
#### 机械波

波长$ \lambda $：一个完整波长的长度
周期$T$：波前进一个波长的距离所需要的时间
频率：$\nu=\frac{1}{T}$
波速：在波动过程中，某一个振动状态在单位时间内所传播的距离；也称相速(波长除以时间)$ u=\frac{\lambda}{T}$


$$
\sqrt{x}
$$
波函数
$
y=A\cos \left[ w\left( t-\frac{x}{u} \right) +\varphi \right] \,\,\varDelta t=\frac{x}{u}
$
$
y=A\cos \left[ 2\pi \left( \frac{t}{T}-\frac{x}{\lambda} \right) +\varphi \right] 
$

$
y=A\cos \left[ \omega t-\frac{2\pi x}{\lambda}+\varphi \right] 
$

波的干涉：
频率相同，振动方向平行，相位相同(或者相位差恒定的)的两列波相遇时，使得某些地方振动始终加强，而使得另外一些地方振动始终减弱的现象，称为波的干涉现象

干涉条件：波频率相同，振动方向相同，位相位差恒定； 满足干涉条件的波称为相干波
干涉现象：某些点振动始终加强，另一些点振动始终减弱或者完全抵消。

$$
y_p=y1+y_2=A\cos \left( \omega t+\varphi _3 \right) \,\,; A=\sqrt{A_{1}^{2}+A_{2}^{2}+2A_1A_1\cos \varDelta \varphi}
$$

$$
\varDelta \varphi =\left( \varphi _2-\frac{2\pi r_2}{\lambda} \right) -\left( \varphi _1-\frac{2\pi r_1}{\lambda} \right) 
$$


$\varDelta \varphi =2k\pi $ 合振幅最大
$\varDelta \varphi =(2k+1)\pi $ 合振幅最小

干涉的波程差条件：
当$\delta =r_1-r_2=2k\frac{\lambda}{2}$ (半波长的偶数倍)
合振幅最大:
当$\delta =r_1-r_2=(2k+1)\frac{\lambda}{2}$ (半波长的偶数倍)
合振幅最小:

相干波：
产生条件: 两列振幅相同的相干波相向传播
驻波方程：$ y=2A\cos 2\pi \frac{x}{\lambda}\cos 2\pi \nu t $

相位跃变(半波损失) -- 从波疏到波密介质


+ 多普勒效应
发射频率$\mathrm{v}$和接收频率$\mathrm{v}'$不相等

$$
\mathrm{v}'=\frac{\mathrm{u}\pm \mathrm{v}_0}{\mathrm{u}\mp \mathrm{v}_{\mathrm{s}}}\mathrm{\nu}
$$

$\mathrm{v}_0$ 观察者向波源运动 + 远离 -
$\mathrm{v}_{\mathrm{s}}$ 波源向观察者运动 - 远离 +






### 第十一章：光学

真空中的光速: $ \mathrm{c}=\frac{1}{\sqrt{\mathrm{\varepsilon}_0\mathrm{\mu}_0}} $

![alt text](image-21.png)
相干光的产生：
+ 振幅分割法
+ 波阵面分割法

![alt text](image-16.png)
![alt text](image-17.png)

劳埃德镜


光在真空中的速度：
光在介质中的速度：
介质中的波长：

光程：介质折射率与光的几何路程之积= `nr`
物理意义：光在介质中通过的几何路程折算到真空中的路程

光程差：两光程之差 $ \Delta =\mathrm{nr}_2-\mathrm{r}_1 $

相位差： $
\Delta \mathrm{\varphi}=2\mathrm{\pi}\frac{\Delta}{\mathrm{\lambda}} $
![alt text](image-18.png)
![alt text](image-19.png)


劈尖：

$ \Delta =2nd+\frac{\lambda}{2} $

牛顿环：
$ \Delta =2nd+\frac{\lambda}{2} $

迈克尔逊干涉仪：？

光的衍射：

单缝衍射：

$$
b\sin \theta =\pm 2k\frac{\lambda}{2}=\pm k\lambda 干涉相消(暗纹)
$$

$$
b\sin \theta =\pm \left( 2k+1 \right) \frac{\lambda}{2} 干涉相加(明纹)
$$




























### 第十二章：气体动理论

$$
pV=\nu RT=\frac{m‘}{M}RT
$$

`m‘` 系统总质量 `m'=Nm`
`M` 摩尔质量  `M=NA m`
`m` 单个分子质量 


$$
p=nkT
$$

$k=\frac{R}{N_A}$ :玻尔兹曼常数
$n=\frac{N}{V}$   :气体分子数密度

$$
p=\frac{2}{3}n\overline{\varepsilon _k}
$$

$$
p=nkT
$$

$$
\overline{\varepsilon _k}=\frac{1}{2}m\overline{v^2}
$$

分子的平均能量：

理想气体的内能：分子动分子内原子间的势能
1mol 理想气体的内能：
$$
E=N_A\overline{\varepsilon }=\frac{i}{2}RT 
$$

理想气体的内能：
$$
E=\nu \frac{i}{2}RT
$$

理想气体内能变化：
$$
dE=\nu \frac{i}{2}RdT
$$

![alt text](image-20.png)
`f(v)`物理意义：
表示在温度T的平衡状态下，速率在`V附近`单位速率区间的分子数占总数的百分比

三种统计速率：
+ 最概然速率
$$
_p=\sqrt{2}\sqrt{\frac{kT}{m}}
$$

+ 平均速率
$$
\overline{v}=\sqrt{\frac{8}{\pi}}\sqrt{\frac{kT}{m}}
$$

+ 方均根速率
$$
\sqrt{\overline{v^2}}=\sqrt{3}\sqrt{\frac{kT}{m}}
$$

$$
v_p<\overline{v}<\sqrt{\overline{v^2}}
$$



### 第十三章：热力学基础
理想气体的内能：
表征系统状态的单值函数，理想气体的内能仅是温度的函数；系统内能的增量只和系统的始末状态有关，和系统经历的过程无关
$$
E=E\left( T \right) 
$$


`热力学第一定律`：
系统从外界吸收的热量，一部分使得系统的内能增加，另外一部分使系统对外界做功。
$$
Q=E_2-E_1+W=\varDelta E+W
$$
准静态过程：
$$
Q=\varDelta E+\int_{V1}^{V2}{pdV}
$$

微变过程：
$$
dQ=dE+dW=dE+pdV
$$

Q >0 系统吸热 <0 放热
$\varDelta E $ >0 内能增加，<0 内能减小
W >0 系统对外界做功，<0 外界对系统做功

理论基础公式:
$ pV=\nu RT $
$ Q=E_2-E_1+W=\varDelta E+\int_{V1}^{V2}{pdV} $
$ dQ=dE+dW=dE+pdV $
$ E=E\left( T \right)  $

#### 等容过程 摩尔定体热容
V 为常量

$ dV=0\ dW=0 $
$ dQ_v=dE=\nu \frac{i}{2}RdT $


摩尔定体热容：1mol 理想气体在等体过程中吸收热量为$ dQ_v $ =使得温度升高$dT$,其摩尔定体热容为：

$
C_{V,M}=\frac{dQ_V}{dT}
$

$\nu $mol理想气体:
$ dQ_V=\nu C_{V,M}dT $
由热力学第一定律:
$$
Q_V=\nu C_{V,M}\left( T_2-T_1 \right) =E_2-E_1
$$


#### 等压过程 摩尔定压热容
p为常量


`热力学第二定律`:
1. 不可能制造出这样一种循环工作的热机，它只使单一热源冷却来做功，而不放出热量给其他物体。或者说不使外界发生任何变化；

2. 不可能把热量从低温物体自动传到高温物体而不引起外界的变化 











### 第十四章：相对论
狭义相对论的基本原理：
+ 相对性原理：物理定律在所有的惯性系中都具有相同的表达形式；
+ 光速不变原理：真空中的光速是一个常量，沿各个方向都等于`c`,与光源或观测者的远动状态无关，

洛伦兹坐标变换式：
$$
\begin{cases}
	\beta =v/v\\
	\gamma =\sqrt{1-\beta ^2}\\
\end{cases}
$$

$$
\text{洛伦兹坐标正变换}\begin{cases}
	x'=\frac{x-vt}{\sqrt{1-\beta ^2}}=\gamma \left( x-vt \right)\\
	y'=y\\
	z'=z\\
	t'=\frac{t-\frac{v}{c^2}x}{\sqrt{1-\beta ^2}}=\gamma \left( t-\frac{v}{c^2}x \right)\\
\end{cases}
$$
$$
\text{洛伦兹坐标反变换}\begin{cases}
	x=\gamma \left( x'+vt' \right)\\
	y=y'\\
	z=z'\\
	t=\gamma \left( t'+\frac{v}{c^2}x' \right)\\
\end{cases}
$$




$$
\text{洛伦兹速度正变换}\begin{cases}
	u_{x}^{'}=\frac{u_x-v}{1-\frac{v}{c^2}u_x}\\
	u_{y}^{'}=\frac{u_y}{\gamma \left( 1-\frac{v}{c^2}u_x \right)}\\
	u_{z}^{'}=\frac{u_x}{\gamma \left( 1-\frac{v}{c^2}u_x \right)}\\
\end{cases}
$$

$$
\text{洛伦兹速度逆变换}\begin{cases}
	u_x=\frac{u_{x}^{'}+v}{1+\frac{v}{c^2}u_{x}^{'}}\\
	u_y=\frac{u_{y}^{'}}{\gamma \left( 1+\frac{v}{c^2}u_{x}^{'} \right)}\\
	u_z=\frac{u_{z}^{'}}{\gamma \left( 1+\frac{v}{c^2}u_{x}^{'} \right)}\\
\end{cases}
$$

s'系中 ：
+ 物体在运动方向上长度收缩
+ 时间延缓


相对论下的速度和动量
1. 相对论动量遵循洛伦兹变换
$$
\text{相对论动量：}\overrightarrow{p}=\frac{m_0\overrightarrow{v}}{\sqrt{1-\beta ^2}}=\gamma m_0\overrightarrow{v}
$$

2. 相对论质量
$$
\text{相对论质量：}m=\frac{m_0}{\sqrt{1-\beta ^2}}
$$
$$
\text{相对论动能：}E_k=mc^2-m_0c^2
$$
$$
\text{静能量：}E_0=m_0c^2
$$

$$
\text{总能量：}E=E_k+E_0=mc^2
$$
$$
\text{相对论质能关系：}E=mc^2
$$




### 第十五章：量子力学

1. 热辐射基本概念：
+ 单色辐射出射度：
单位时间内从物体单位表面积发出的频率在 $ \nu $ 附近单位频率区间内的电磁波的能量

$ M_{\nu}\left( T \right) 或者  M_{\lambda}\left( T \right) $


+ 辐射出射度
单位时间，单位面积上所辐射出的各种频率(或者各种波长)的电磁波的能量总和
$$
M\left( T \right) =\int_0^{\infty}{M_{\nu}\left( T \right) d\nu =}\int_0^{\infty}{M_{\lambda}\left( T \right) d\lambda}
$$

黑体：
若物体在任何温度下，能吸收一切外来的电磁辐射，则称此物体为黑体(绝对黑体)。 -- 黑体是理想模型

普朗克量子假说：
黑体中的分子、原子的振动可以看作谐振子，这些谐振子的能量状态是分立的，相应的能量是某一最小能量的整数倍即：$ \varepsilon ,  2\varepsilon , ... , n\varepsilon$
$$
\varepsilon =nh\nu \,\,\left( n=1,2,3... \right) \,\,h=6.63\times 10^{-34}J\cdot s
$$

+ 光电效应：


截止频率：$ \nu _0 $
对某种金属来说，只有入射光的频率大于某一频率$ \nu _0 $时，电子才会从金属表面溢出。
$ \nu _0 $称为截止频率或者红线频率。
截止频率和`材料有关`与`光强无关`。

$$
h\nu =\frac{1}{2}mv^2+W
$$
h: 普朗克常量
v: 照射光的频率
W：溢出功与材料有关
$$
eU_0=\frac{1}{2}mv^2
$$
外加反向的遏止电压 $eU_0$恰能阻止光电子到达阳极

+ 康普顿效应
$$
\varDelta \lambda =\frac{h}{m_0c}\left( 1-\cos \theta \right) =\lambda _c\left( 1-\cos \theta \right) 
$$

+ 玻尔氢原子理论

+ 德布罗意波

$$
\text{德布罗意公式}\left\{ \begin{array}{c}
	\lambda =\frac{h}{p}=\frac{h}{mv}\\
	\nu =\frac{E}{h}=\frac{mc^2}{h}\\
\end{array} \right. 
$$


+ 实物粒子二象性

+ 不确定关系

自由粒子平面波函数
$$
\varPsi \left( x,t \right) 
$$

波函数的统计意义：
概率密度： 表示在某处单位体积内粒子出现的概率
$$
\left| \varPsi \right|^2=\varPsi \varPsi ^{^*}
$$

$$
\int{\left| \varPsi \right|^2}=1
$$

