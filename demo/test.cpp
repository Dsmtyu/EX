#include <fstream>
#include <iostream>
#include <time.h>
#include "../Imath.h"
string a, b; 
string x, y, z;

int main() {
	cin.tie(0);		// �ɲ��� 
	cout.tie(0);	// �ɲ��� 
	
	clock_t start, end;
	ofstream outfile;
   	outfile.open("test.dat");
	cin >> a >> b;
	
	start = clock();
	// �ӷ�
	x = add(a, b);
	// ���� 
	y = sub(a, b);
	// �˷� 
	z = mul(a, b);
	end = clock();
	
	outfile << x << endl << y << endl << z << endl << endl; 
	cout << x << endl << y << endl << z << endl;
	cout << "Complete, use " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
} 
