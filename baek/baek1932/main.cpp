// made by dragostea
/*

������ȹ�� ���� >> ���ڻﰢ��

*/

#include <iostream>
#include <cmath>

// �Ƕ�̵� index���� ��ȿ���� �˻�
bool isVaild(int** arr, int i, int j)
{
	// i�� ���� ������ ����� false�� ���
	if (i < 0 || arr[i][j] == -1)
		return false;
	return true;
}

// �Ƕ�̵� ���·� �Է��� �޴� �Լ�
int insert(int** arr, int len)
{
	int i = 0;
	int limit = 2;
	int j = 0;
	int valLeft = 0, valRight = -1;
	int maxes = 0;
	int max = -1;

	scanf("%d",&arr[0][0]);

	for (i = 1; i < len; i++)
	{
		for (j = 0; j < limit; j++)
		{
			scanf("%d", &arr[i][j]);			

			// �� ���ʺθ�, ������ �θ� ��ȿ������ �˻��Ѵ�.
			// ��ȿ������ �˻������� �� ���� �θ��� ���� ���
			// �� �θ�� �ڽſ� ���� �� �� �ִ���
			// �ڽſ� �ʱ�ȭ��Ų��.
			if (isVaild(arr, i - 1, j - 1))
				valLeft = arr[i - 1][j - 1];
			else
				valLeft = -1;

			if (isVaild(arr, i - 1, j))
				valRight = arr[i - 1][j];
			else
				valRight = -1;
			maxes = fmax(valLeft + arr[i][j], valRight + arr[i][j]);
			arr[i][j] = maxes;

			// i ���� �������� �����ߴٸ�
			// ������ �� �ִ��� ��� ��ȯ�Ѵ�.
			if (i == len - 1)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}

		}
		limit++;
	}
	return max;
}

int calc(int** arr, int len)
{
	int i, j;
	int limit = 1;


	for (i = 0; i < len; i++)
	{
		for (j = 0; j < limit; j++)
		{

		}
		limit++;
	}
	return 0;
}

int main(void)
{
	int input;
	int** arr;
	int i, j;
	int result;

	// �迭 �ʱ�ȭ �ܰ�
	scanf("%d", &input);
	arr = new int*[input];
	for (i = 0; i < input; i++)
	{
		arr[i] = new int[input];
		for (j = 0; j < input; j++)
		{
			arr[i][j] = -1;
		}
	}

	result = insert(arr, input);

	printf("%d ", result);

	return 0;
}