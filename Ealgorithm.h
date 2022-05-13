#ifndef __EALGORITHM_H__
#define __EALGORITHM_H__
#define bsearch bsearch
#define minin minin
#define maxax maxax

#include <iostream>
using namespace std;


/*二分查找顺序数组中的target是否存在*/
bool bsearch(int a[], int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) >> 1;
		if (a[mid] > target)
			end = mid - 1;
		else if (a[mid] < target)
			start = mid + 1;
		else
			return true;
	}
	return false;
}


/*查找数组最小值*/
int minin(int a[], int start, int end) {
	int minn = a[start];
	for (int i = start + 1; i < end; ++i)
		if (a[i] < minn)
			minn = a[i];
	return minn;
}


/*查找数组最大值*/
int maxax(int a[], int start, int end) {
	int maxx = a[start];
	for (int i = start + 1; i < end; ++i)
		if (a[i] > maxx)
			maxx = a[i];
	return maxx;
}


#endif