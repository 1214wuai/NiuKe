#include<iostream>

using namespace std;

int main()
{
	
	int num1, num2;
	cin >> num1 >> num2;
	if (num1 == 0)
		return num2;
	if (num2 == 0)
		return num1;
		int sum = 0, carry = 0;
		while (num2 != 0)
		{
			sum = num1 ^ num2;
			carry = (num1&num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		cout << sum << endl;

	return 0;
}