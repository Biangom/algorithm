#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;




int* white;
int* blue;
int* isReg;

int wh_c = 0;
int bl_c = 0;


queue<int> que;

int BFS(int x) {

	return 0;
}

int main(void)
{
	//int input;

	//cin >> input;

	//int* a = new int[input];

	//int size = _msize(a) / sizeof(*a);

	//cout << size << endl;


	int num;
	cin >> num;

	// �л� �迭 ����
	int** stu_info = new int*[num + 1];
	int* white = new int[num + 1];
	int* blue = new int[num + 1];
	int* isReg = new int[num + 1];

	// ------

	for (int i = 1; i <= num; i++) {
		int input;
		cin >> input;
		stu_info[i] = new int[input];
		for (int j = 0; j < input; j++) {
			int input_num;
			cin >> input_num;
			stu_info[i][j] = input_num;
		}
	}
	
	white[0] = 1; // ù��° �л��� 1
	wh_c++;

	// ** Ȯ�ο� - �ߵ�����
	// i, i��° �л�
	for (int i = 1; i <= num; i++) {
		int len = _msize(stu_info[i]) / sizeof(*stu_info[i]);

		// j�ݺ����� ���� �Ⱦ��ϴ� �л����� �����Ѵ�.
		// stu_info[i][j] = i��°�л��� j������ �Ⱦ��ϴ� �л��� ��ȣ
		for (int j = 0; j < len; j++) {
			blue[bl_c++] = stu_info[i][j];
			//cout << stu_info[i][j];
		}
		//cout << endl;
	}


	for (int i = 0; i < num; i++) {
		delete[] stu_info[i];
	}
	delete[] stu_info;
	delete[] white;
	delete[] blue;
	
	return 0;
}