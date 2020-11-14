#include<iostream>
#include<string>
#include<stack>
using namespace std;

int Calculate(char* str)
{
	stack<int> s;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int o1 = 0;
		int o2 = 0;
		int result = 0;
		switch (str[i])
		{
		case '+':
			o1 = s.top();
			s.pop();
			o2 = s.top();
			s.pop();
			result = o2 + o1;
			s.push(result);
			break;
		case '-':
			o1 = s.top();
			s.pop();
			o2 = s.top();
			s.pop();
			result = o2 - o1;
			s.push(result);
			break;
		case '*':
			o1 = s.top();
			s.pop();
			o2 = s.top();
			s.pop();
			result = o2 * o1;
			s.push(result);
			break;
		case '/':
			o1 = s.top();
			s.pop();
			o2 = s.top();
			s.pop();
			result = o2 / o1;
			s.push(result);
			break;
		default:
			s.push(str[i]);
			break;
		}
	}
	return s.top();
}

int main()
{
	char str[] = { 3, 17, 15, '-', '*', 18, 6, '/', '+', '\0' };
	cout << Calculate(str) << endl;;
	return 0;

}