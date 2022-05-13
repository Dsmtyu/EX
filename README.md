# EX for C/C++
---

### 介绍
Emath: 提供各种数学函数，高精度，最大公约数等
Ealgorithm: 提供常用的算法工具，二分查找等

### 软件使用
使用 Microsoft Visual Studio Code, Dev-C++  
TDM-GCC 9.2.0 编译运行 (其他开发环境亦可)

### 安装教程
1. 下载EX  
2. 切到EX目录下或将头文件加入到编译器标准库目录下

### 使用说明

1.  #include "Emath.h" 使用高精度(正负数)以及各种功能
2.  #include <Emath.h> 标准库目录

### 参与贡献

1.  Fork 本仓库
2.  新建分支
3.  提交代码
4.  新建 Pull Request

### 更新历史

### **v1.0.2.37**
* Ealgorithm.h (使用VScode重构)
```cpp
1. bsearch(int a[], int left, int right, int target) 二分查找数组中从left到right的traget
2. minin(int a[], int start, int end) 返回数组中的最小值
3. maxax(int a[], int start, int end) 返回数组中的最大值
```

### **v1.0.1.50**  
* Emath.h (使用Dev-C++)
```cpp
1. toint(char& t) 字符转数字  
2. copyarry(int a[], int b[], const int& m, const int& n = 0) 从a复制n到m去b数组  
3. aver(int a[], double ave, const int& m, const int& n = 0) 在数组a中从n到m计算数组平均值  
4. ilength(int(long long)& n) 获取(长)整数长度  
5. stoarry(string& t, int a[], const int& m, const int& n = 0) 把字符串s从n到m转数字数组a  
6. add(string& x, string& y) 加法运算(高精度)，返回string类型  
7. sub(string& s1, string& s2) 减法运算(高精度)，返回string类型  
8. mul(string &s1, string &s2) 乘法运算(高精度)，返回string类型
9. powh(int &base, int &exponent) 幂运算(高精度)，返回string类型  
10. fac(int &n) 阶乘(高精度)，返回string类型  
11. gcd(int(long long) &a, int(long long) &b) 最大公约数
12. lcm(int(long long) &a, int(long long) &b) 最小公倍数
```
