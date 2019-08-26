#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void GetArray(int size, int value)
{
	size = (int)((size + 1)*rand());
	cout << size << endl;
}
void Print(vector<int>&v)
{
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
void BubbleSort(vector<int>& v)
{
	for (int i = v.size()-1 ; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j+1])
				swap(v[j], v[j+1]);
		}
	}
}

void InsertSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int tmp = v[i];
		int j = i;
		for (j; (j > 0) && (v[j - 1] > tmp); j--)
			v[j] = v[j - 1];
		v[j] = tmp;
	}
}

void SelectSort(vector<int>& v)
{
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)
		{
			if (v[min] > v[i])
				min = i;
			if (v[max] < v[i])
				max = i;
		}
		swap(v[left], v[min]);
		if (max == left)
			max = min;
		swap(v[max], v[right]);
		left++;
		right--;
	}
}

void adjustDown(vector<int>& v, int root, int sz)
{
	int parent = root;
	int child = root * 2 + 1;
	if (child + 1 < sz && v[child + 1] > v[child])
		child++;
	while (child < sz)
	{
		if (v[parent] < v[child])
		{
			swap(v[parent], v[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(vector<int>& v)
{
	int sz = v.size();
	for (int i = (sz-1) / 2; i >= 0; i--)
	{
		adjustDown(v, i, sz);
	}
	for (int i = sz - 1; i >= 0; i--)
	{
		swap(v[0], v[i]);
		adjustDown(v, 0, i);
	}

}

int Quick_Sort(vector<int>& v, int left, int right)
{
	int keyindex = right;
	int key = v[right];
	while (left < right)
	{
		while (left < right && v[left] <= key)
			left++;
		while (left<right && v[right]>=key)
			right--;
		swap(v[left], v[right]);
	}
	swap(v[keyindex], v[right]);
	return right;
}
int Quick_Sort2(vector<int>& v, int left, int right)
{
	int tmp = v[right];
	while (left < right)
	{
		if (left < right && v[left] < tmp)
			left++;
		v[right] = v[left];
		if (left<right && v[right]>tmp)
			right--;
		v[left] = v[right];
	}
	v[right] = tmp;
	return right;
}

int Quick_Sort3(vector<int>&v, int left, int right)
{
	int cur = left;
	int key = v[right];
	int prev = cur - 1;
	while (cur <= right)
	{
		if (v[cur] < key && ++prev != cur)
			swap(v[prev], v[cur]);
		cur++;
	}
	swap(v[++prev], v[right]);
	return prev;
}
void _QuickSort(vector<int>& v, int left, int right)
{
	if (left > right)
		return;
	//int div = Quick_Sort(v, left, right);
	//int div = Quick_Sort2(v, left, right);
	int div = Quick_Sort(v, left, right);
	_QuickSort(v, left, div - 1);
	_QuickSort(v, div + 1, right);
}
void QuickSort(vector<int>& v)
{
	
	int left = 0;
	int right = v.size()-1;
	_QuickSort(v,left, right);
}
void __Merge(vector<int>& v, int left1, int right1, int left2, int right2, vector<int>& tmp)
{
	int start = left1;
	int index = left1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (v[left1] < v[left2])
			tmp[index++] = v[left1++];
		else
			tmp[index++] = v[left2++];
	}
	
	while (left2 <= right2)
		tmp[index++] = v[left2++];
	
	while (left1 <= right1)
		tmp[index++] = v[left1++];
	for (int i = start; i < index; i++)
		v[i] = tmp[i];
}
void _Merge(vector<int>& v, int left, int right,vector<int>& tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_Merge(v, left, mid, tmp);
	_Merge(v, mid + 1, right, tmp);
	__Merge(v, left, mid, mid + 1, right, tmp);
}
void MergeSort(vector<int>& v)
{
	int sz = v.size();
	if (sz < 1)
		return;
	vector<int> tmp(sz, 0);
	_Merge(v, 0, sz - 1,tmp);
}
void test()
{

}
int main()
{
	vector<int> v = { 9,8,7,6,5,4,3,2,1 };
	//BubbleSort(v);//√∞≈› O(N^2)
	//InsertSort(v);//≤Â»ÎO(N)~~O(N^2)
	//SelectSort(v);//—°‘ÒO(N^2)
	//HeapSort(v);//O(N*logN)
	//QuickSort(v);//O(N*logN)~~O(N^2)
	//MergeSort(v);
	//Print(v);
	system("pause");
	return 0;
}
