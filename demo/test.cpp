#include <fstream>
#include <iostream>
#include <time.h>
#include "../Imath.h"
string a, b; 
string x, y, z;

int main() {
	cin.tie(0);		// 可不加 
	cout.tie(0);	// 可不加 
	
	clock_t start, end;
	ofstream outfile;
   	outfile.open("test.dat");
	cin >> a >> b;
	
	start = clock();
	// 加法
	x = add(a, b);
	// 减法 
	y = sub(a, b);
	// 乘法 
	z = mul(a, b);
	end = clock();
	
	outfile << x << endl << y << endl << z << endl << endl; 
	cout << x << endl << y << endl << z << endl;
	cout << "Complete, use " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
} 
