#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Judge(string str) 
{									 //ʹ��ջ�ж�����ƥ��
	stack<char> s;
	for (int i = 0; i < str.length(); i++) 
	{
		switch (str[i])
		{
		case '(':
			s.push('(');
			break;
		case '[':
			s.push('[');
			break;
		case '{':
			s.push('{');
			break;

		case ')':
			if (s.top() == '(') 
			{
				s.pop();
			}
			else 
			{
				return false;
			}
			break;
		case ']':
			if (s.top() == '[') 
			{
				s.pop();
			}
			else 
			{
				return false;
			}
			break;
		case '}':
			if (s.top() == '{') 
			{
				s.pop();
			}
			else 
			{
				return false;
			}
			break;
		default:
			break;
		}
	}
	if (s.empty()) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main() 
{
	string str;
	cin >> str;
	if (Judge(str))
	{
		cout << "ƥ�䣡" << endl;
	}
	else
	{
		cout << "��ƥ�䣡" << endl;
	}
	return 0;
}