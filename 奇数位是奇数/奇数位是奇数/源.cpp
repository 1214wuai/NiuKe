#include<iostream>
#include<vector>
using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len) {
	//int i = 0, j = 1;
	//while(i<len && j<len)
	//{
	//  while(i<len && (arr[i]&1==0))i+=2;
	// while(j<len && (arr[j]&1==1))j+=2;
	//if(i<len && j<len)swap(arr[i],arr[j]);
	//}
	int i = 0, j = 1;
	while (i < len && j < len) {
		while (i < len && (arr[i] & 1) == 0) i += 2;
		while (j < len && (arr[j] & 1) == 1) j += 2;
		if (i < len && j < len) swap(arr[i], arr[j]);
	}
}
int main()
{
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(9);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(6);

	oddInOddEvenInEven(arr, arr.size());
	return 0;

}
