#pragma warning(disable:4996);

//�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡
//���ǵ�������һ��������ͨ��һ�ű������Ϣӳ��� ����4λ���롣
//��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ�� �����4λ��
//| 1 1 | ^n = > | Xn ..|
//|1 0|          |.. .. | 
//����n = 2ʱ�� 
//| 1 1 | ^ 2 = > | 1 1 | *| 1 1 | = > | 2 1|
//|1 0|      |1 0|   |1 0|    |1 1 |
//��2��Ӧ�����ǡ�0002����
//
//�������� : �����ж������ݡ�
//	ÿ���������У�
//	
//	��һ�а���һ������n(1��n��100)��
//	�ڶ��а���n��������Xi(1��Xi��10000)
//	������� : 
//	��Ӧÿһ�����룬���һ����Ӧ�����롣
//	6
//	18 15 21 13 25 27 - ��418109877711037713937811
//	5
//	1 10 100 1000 10000 - ��00010089410135017501

//#include<iostream>
//using std::cout;
//using std::endl;
//
//int arr[10000] = { 0,1,2,3,5 };
//
//void arr_init()
//{
//	for (int i = 3; i < 10000; ++i)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//		if (arr[i] >= 10000)
//			arr[i] %= 10000;
//	}
//}
//int main()
//{
//	int a, b;
//	while (scanf("%d", &a) != EOF)
//	{
//		while (a--)
//		{
//			scanf("%d", &b);
//			cout << arr[b];
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	vector<int> v;
//	while (cin >> n)
//	{
//		if (n >= 1 && n <= 100000)
//		{
//			if (n == 1)
//				v.push_back(1);
//			//cout<<1;
//			else if (n == 2)
//				v.push_back(2);
//			//cout<<2;
//			else
//			{
//				int x = 1;
//				int y = 2;
//				int count = 0;
//				for (int i = 2; i<n; i++)
//				{
//					count = x + y;
//					x = y;
//					y = count;
//				}
//				if (count>999999)
//				{
//					count %= 1000000;
//				}
//				v.push_back(count);
//				//cout<<count;
//			}
//		}
//	}
//	for (int i = 0; i<v.size(); i++)
//	{
//		cout << v[i] << endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	if (n >= 1 && n <= 1000000000000000000)
//	{
//		int count = 0;
//		for (int i = 0; i <= n; i++)
//		{
//			vector<int> v;
//			int x = 1;
//			int y = i;
//			while (y>0)
//			{
//				v.push_back(x&y);
//				y = y >> 1;
//			}
//			int start = 0;
//			int end = v.size() - 1;
//			while (start <= end)
//			{
//				if (v[start] == v[end])
//				{
//					if ((start == end) || (start + 1 == end))
//					{
//						count++;
//						break;
//					}
//					start++;
//					end--;
//				}
//				else
//					break;
//			}
//		}
//		cout << count+1;
//	}
//	system("pause");
//	return 0;
//}
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	if (a <= 1000000000 && a>b && b>c && c >= 1)
//	{
//		int A = 1, B = 1, C = 1;
//		for (int i = 0; i < a; i++)
//		{
//			A *= 2;
//		}
//		for (int i = 0; i < b; i++)
//		{
//			B *= 2;
//		}
//		for (int i = 0; i < c; i++)
//		{
//			C *= 2;
//		}
//		int x = A + B - C;
//		int count = 0;
//		while (x > 0)
//		{
//			if (x & 1 == 1)
//				count++;
//			x = x >> 1;
//		}
//		cout << count;
//	}
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	vector<int> v;
	if (n >= 1 && n <= 1000)
	{
		for (int i = 2; i <= n; i++)
		{
			for (int j = 2; j<i; j++)
			{
				if (i%j != 0)
					continue;
				//i��������
				for (int k = 0; k<v.size(); k++)
				{
					int sum = v[k];
					while (sum<i)
					{
						sum *= v[k];
						if (sum == i)
						{
							v.push_back(i);
							goto str;
						}
					}
				}
				goto str;
			}
			v.push_back(i);
		str:
			;
		}
		cout << v.size();
	}
	system("pause");
	return 0;
}