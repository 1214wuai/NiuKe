//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ� �ж�����������

class Solution {
public:
	int jumpFloorII(int number) {
		//return 1<<(number-1);
		if (number < 1)
			return -1;
		else if (number == 1)
			return 1;
		else
			return 2 * jumpFloorII(number - 1);
	}
};