// To-Do: 2:div函数
#ifndef HIGH_H
#define HIGH_H

#include <string.h>

using namespace std;


/* 字符转数字 */
int toint(char& t) {
	return t - '0';
}


/* 字符串转数字数组 */
void toarry(string& t, int a[], const int& l) {
	int i;
	for (i = 0; i < l; ++i)
		a[i] = toint(t[i]);
}


/* 加法运算(高精度)，返回string类型 */
string sub(string& s1, string& s2);
string add(string& x, string& y) {
	string tar; 
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[m + 5], b[m + 5], c[m + 10], lc = 1, n = 0;
	char ch;
	bool f = false;	// 负数
	/* 初始化空 */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* 负数 */
	if (x[0] == '-' && y[0] == '-') {
		++n;
		f = true;
	} else if (x[0] == '-' || y[0] == '-') {
		string s1 = x, s2 = y;
		if (x[0] == '-')
			s1.erase(s1.begin());
		if (y[0] == '-')
			s2.erase(s2.begin());
		return sub(s1, s2);
	}

	/* 获取字符转为数字 */
	for (i = n; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = n; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	i = 0;
	while (lc <= la || lc <= lb) {
		c[lc] = a[lc] + b[lc] + i;	// 两数之和加i位
		i = c[lc] / 10;				// 进i位
		c[lc] %= 10;				// 获取当前1位
		++lc;
	}

	c[lc] = i;						// 最高位进位为i
	while (c[lc] == 0 && lc > 1)
		--lc;						// 删除前导0
	if (f)
		tar.push_back('-');

	/* 将数字数组转为字符串 */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


/* 减法运算(高精度)，返回string类型 */
string sub(string& s1, string& s2) {
	string x = s1, y = s2, tar;
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[m + 5], b[m + 5], c[m + 10], lc = 1;
	char ch;
	bool f = false;
	/* 初始化空 */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* 负数 */
	if (x[0] == '-' && y[0] == '-') {
		x.erase(x.begin()), y.erase(s2.begin());
		return sub(x, y);
	} else if (x[0] == '-') {
		x.erase(x.begin());
		return "-" + add(x, y);
	} else if (y[0] == '-') {
		y.erase(y.begin());
		return add(x, y);
	}

	/* 正负数判断 */
	if (la < lb || (la == lb && toint(x[0]) < toint(y[0]))) {
		swap(x, y);			// 交换
		tar.push_back('-');	// 负数
	}

	/* 获取字符转为数字 */
	for (i = 0; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = 0; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	i = 1;
	while (i <= la || i <= lb) {
		if (a[i] < b[i]) {
			a[i] += 10;		// 向前借位(不够减)
			--a[i + 1];
		}
		c[i] = a[i] - b[i];	// 对应位相减
		++i;
	}

	lc = i;					// i位数字
	while (c[lc] == 0 && lc > 1)
		--lc;				// 删除前导0
		
	/* 将数字数组转为字符串 */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


/* 乘法运算(高精度)，返回string类型  */
string mul(string& s1, string& s2) {
	string x = s1, y = s2, tar;
	int la = x.length(), lb = y.length();
	const int m = max(la, lb);
	int i, j, a[m + 5], b[m + 5], c[la * lb], lc, t;
	char ch;
	bool f = false;
	/* 初始化空 */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* 为0？(剪枝) */
	if (x[0] == '0' || y[0] == '0')
		return "0";

	/* 负数 */
	if (x[0] == '-') {
		f = true;
		s1.erase(s1.begin());
	}
	if (y[0] == '-') {
		f = true;
		s2.erase(s2.begin());
	}
	if (x[0] == '-' && y[0] == '-') {
		f = false;
	}

	/* 获取字符转为数字 */
	for (i = 0; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = 0; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	for (i = 1; i <= la; ++i) {
		t = 0;		// 存放进位
		for (j = 1; j <= lb; ++j) {
			c[i + j - 1] = a[i] * b[j] + t + c[i + j - 1];	// 当前积+上次乘积+原数
			t = c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
		c[i + lb] = t;		// 进位
	}

	lc = la + lb;
	while (c[lc] == 0 && lc > 1)
		--lc;				// 删除前导0
	if (f)
		tar.push_back('-');	// 负数
	/* 将数字数组转为字符串 */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


#endif
