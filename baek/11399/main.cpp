// made by dragostea

#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int num;
	int* arr;
	int i;
	int result = 0;
	scanf("%d", &num);

	arr = new int[num];

	for (i = 0; i < num; i++)
		scanf("%d",&arr[i]);

	sort(arr, arr + num);

	for (i = 0; i < num; i++)
	{
		result += arr[i] * (num - i);
	}
	printf("%d", result);
}