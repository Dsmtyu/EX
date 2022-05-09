// To-Do: 2:div����
#ifndef HIGH_H
#define HIGH_H

#include <string.h>

using namespace std;


/* �ַ�ת���� */
int toint(char& t) {
	return t - '0';
}


/* �ַ���ת�������� */
void toarry(string& t, int a[], const int& l) {
	int i;
	for (i = 0; i < l; ++i)
		a[i] = toint(t[i]);
}


/* �ӷ�����(�߾���)������string���� */
string sub(string& s1, string& s2);
string add(string& x, string& y) {
	string tar; 
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[m + 5], b[m + 5], c[m + 10], lc = 1, n = 0;
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
	int i, la = x.length(), lb = y.length(), m = max(la, lb), a[m + 5], b[m + 5], c[m + 10], lc = 1;
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
	int i, j, a[m + 5], b[m + 5], c[la * lb], lc, t;
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


#endif
