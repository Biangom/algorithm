// made by �輺��
// ���� : ��ȣ�� ��

#include <iostream>
#include <stack>
#include <string>
using namespace std;



 //stack�� main���� �������־���.
 //�� stack�� �̿��Ͽ� �ٸ� �Լ����� ����� �ϰ�, push�� �Ͽ��µ�
 //�� stack�� empty�� �Ǿ������?
 //�� ������ �����ΰ�.


int calc(stack<char> st, stack<int> numSt, char* input)
{
	int i = 0;
	char now;
	while (true)
	{
		if (input[i] != '\0')
		{
			now = input[i];
			if (now == ')')
			{
				if (st.top() == '[')
				{
					return 0;
				}
				st.pop();
				numSt.push(2);
			}
			else if (now == ']')
			{
				if (st.top() == '(')
				{
					return 0;
				}
				st.pop();
				numSt.push(3);
			}
			st.push(input[i]);
			st.top() = now;
			i++;
		}
		else
			break;
	}

	while (!numSt.empty())
	{
		printf("%d", numSt.top());
		numSt.pop();
	}

	return 1;
}

int main(void){
	char input[30];

	stack<char> st;
	stack<int> numSt;

	int result = 0;
	
	scanf("%s", input);

	st.push(input[0]);

	result = calc(st, numSt, input);

	return 0;
}