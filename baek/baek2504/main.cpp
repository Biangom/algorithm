// made by 김성식
// 문제 : 괄호의 값

#include <iostream>
#include <stack>
#include <string>
using namespace std;



 //stack을 main에서 선언해주었다.
 //그 stack을 이용하여 다른 함수에서 계산을 하고, push를 하였는데
 //그 stack이 empty가 되어버린다?
 //이 오류는 무엇인가.


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