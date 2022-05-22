#ifndef __EALGORITHM_H__
#define __EALGORITHM_H__

using namespace std;

/* 二分查找顺序数组中的target是否存在 */
bool bsearch(int a[], int &left, int &right, int &target)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (a[mid] > target)
			right = mid - 1;
		else if (a[mid] < target)
			left = mid + 1;
		else
			return true;
	}
	return false;
}

/* 查找数组最小值 */
int minin(int a[], int &start, int &end)
{
	int minn = a[start];
	for (int i = start + 1; i < end; ++i)
		if (a[i] < minn)
			minn = a[i];
	return minn;
}

/* 查找数组最大值 */
int maxax(int a[], int &start, int &end)
{
	int maxx = a[start];
	for (int i = start + 1; i < end; ++i)
		if (a[i] > maxx)
			maxx = a[i];
	return maxx;
}


#endif
