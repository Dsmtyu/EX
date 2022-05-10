#ifndef __IMATH_H__
#define __IMATH_H__
#define add add
#define aver aver
#define copyarry copyarray
#define toint toint
#define fac fac
#define ilength ilength
#define mul mul
#define powh powh
#define sub sub
#define stoarry stoarry
#define gcd gcd
#define lcm lcm
#define sizeofa sizeofa 

#include <string.h>
using namespace std;


/* �ַ�ת���� */
int toint(char& t) {
	return t - '0';
}


/* ��a����n��mȥb���� */
void copyarry(int* a, int* b, const int& m, const int& n = 0) {
	int i;
	for (i = n; i < m; ++i)
		b[i] = a[i];
	return;
}


/* ��������ƽ��ֵ */
void aver(int *a, double ave, const int& m, const int& n = 0) {
	int i, sum, cnt;
	sum = cnt = 0;
	for (i = n; i < m; ++i)
		sum += a[i], ++cnt;
	ave = sum / cnt;
	return;
}


/* ��ȡ�������� */
int ilength(int& n) {
	int cnt = 0;
	while (n != 0)
		n /= 10, ++cnt;
	return cnt;
}


/* ��ȡ�����ͳ��� */
long long ilength(long long& n) {
	int cnt = 0;
	while (n != 0)
		n /= 10, ++cnt;
	return cnt;
}


/* �ַ���ת�������� */
void stoarry(string& t, int a[], const int& m, const int& n = 0) {
	int i;
	for (i = n; i < m; ++i)
		a[i] = toint(t[i]);
	return;
}


/* �ӷ�����(�߾���)������string���� */
string sub(string& s1, string& s2);
string add(string& x, string& y) {
	string tar;
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[la + 5], b[lb + 5], c[m + 10], lc = 1, n = 0;
	char ch;
	bool f = false;	// ����
	/* ��ʼ���� */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* ���� */
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

	/* ��ȡ�ַ�תΪ���� */
	for (i = n; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = n; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	i = 0;
	while (lc <= la || lc <= lb) {
		c[lc] = a[lc] + b[lc] + i;	// ����֮�ͼ�iλ
		i = c[lc] / 10;				// ��iλ
		c[lc] %= 10;				// ��ȡ��ǰ1λ
		++lc;
	}

	c[lc] = i;						// ���λ��λΪi
	while (c[lc] == 0 && lc > 1)
		--lc;						// ɾ��ǰ��0
	if (f)
		tar.push_back('-');

	/* ����������תΪ�ַ��� */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


/* ��������(�߾���)������string���� */
string sub(string& s1, string& s2) {
	string x = s1, y = s2, tar;
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[la + 5], b[lb + 5], c[m + 10], lc = 1;
	char ch;
	bool f = false;
	/* ��ʼ���� */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* ���� */
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

	/* �������ж� */
	if (la < lb || (la == lb && toint(x[0]) < toint(y[0]))) {
		swap(x, y);			// ����
		tar.push_back('-');	// ����
	}

	/* ��ȡ�ַ�תΪ���� */
	for (i = 0; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = 0; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	i = 1;
	while (i <= la || i <= lb) {
		if (a[i] < b[i]) {
			a[i] += 10;		// ��ǰ��λ(������)
			--a[i + 1];
		}
		c[i] = a[i] - b[i];	// ��Ӧλ���
		++i;
	}

	lc = i;					// iλ����
	while (c[lc] == 0 && lc > 1)
		--lc;				// ɾ��ǰ��0

	/* ����������תΪ�ַ��� */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


/* �˷�����(�߾���)������string����  */
string mul(string& s1, string& s2) {
	string x = s1, y = s2, tar;
	int la = x.length(), lb = y.length();
	const int m = max(la, lb);
	int i, j, a[m + 10], b[m + 10], c[la * lb + 10], lc, t;
	char ch;
	bool f = false;
	/* ��ʼ���� */
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	/* Ϊ0��(��֦) */
	if (x[0] == '0' || y[0] == '0')
		return "0";

	/* ���� */
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

	/* ��ȡ�ַ�תΪ���� */
	for (i = 0; i < la; ++i)
		a[la - i] = toint(x[i]);

	for (i = 0; i < lb; ++i)
		b[lb - i] = toint(y[i]);

	for (i = 1; i <= la; ++i) {
		t = 0;		// ��Ž�λ
		for (j = 1; j <= lb; ++j) {
			c[i + j - 1] = a[i] * b[j] + t + c[i + j - 1];	// ��ǰ��+�ϴγ˻�+ԭ��
			t = c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
		c[i + lb] = t;		// ��λ
	}

	lc = la + lb;
	while (c[lc] == 0 && lc > 1)
		--lc;				// ɾ��ǰ��0
	if (f)
		tar.push_back('-');	// ����
	/* ����������תΪ�ַ��� */
	for (i = lc; i > 0; --i) {
		ch = c[i] + '0';
		tar.push_back(ch);
	}
	return tar;
}


/* ������ */
string powh(int& base, int& exponent) {
	int i;
	string tar = "1", b = to_string(base);
	for (i = 0; i < exponent; ++i)
		tar = mul(tar, b);
	return tar;
}


/* �׳� */
string fac(int& n) {
	// ��������Ǹ�������ʾ����
	if (n < 0)
		return "����û�н׳ˣ�";
	else {
		int i;
		string f, x;
		for (i = 1; i <= n; ++i) {
			x = to_string(i);
			f = mul(f, x);
		}
		return f;
	}
}


/* ���Լ�� */
int gcd(int& a, int& b) {
	// ����ת��
	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

long long gcd(long long& a, long long& b) {
	// ����ת��
	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}


/* ��С������ */
int lcm(int& a, int& b) {
	int minn = (a > b) ? a : b;
	while (1) {
		if (minn % a == 0 && minn % b == 0) {
			return minn;
		}
		++minn;
	}
}

long long lcm(long long& a, long long& b) {
	long long minn = (a > b) ? a : b;
	while (1) {
		if (minn % a == 0 && minn % b == 0) {
			return minn;
		}
		++minn;
	}
}


# endif
