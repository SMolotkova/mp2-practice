//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int Eval(const string & left, char oper, const  string & right);
//bool IsOperator(char inch);
//int Priority(char inch);
//string ReversePolishNotation(const string& instr);
//int Result(const string & postfix);
//
//int main()
//{
//	string infixStr = "3+9+(9+(9+1)-100)";
//	cout << "Infix: " << infixStr << endl;
//	string postfixStr = ReversePolishNotation(infixStr);
//	cout << "Postfix: " << postfixStr << endl;
//	cout << "Result: " << Result(postfixStr) << endl;
//
//	system("pause");
//}
//int Eval(const string & left, char oper, const  string & right)
//{
//	int a = stoi(left);
//	int b = stoi(right);
//	switch (oper)
//	{
//	case '*':
//		return a * b;
//	case '/':
//		return a / b;
//	case '+':
//		return a + b;
//	case '-':
//		return a - b;
//	default:
//		return 0;
//	}
//
//}
//
//bool IsOperator(char inch)
//{
//	return inch == '*' || inch == '/' ||
//		inch == '+' || inch == '-';
//}
//
//int Priority(char inch)
//{
//	if (inch == '*' || inch == '/') return 2;
//	if (inch == '+' || inch == '-') return 1;
//	return 0;
//}
//string ReversePolishNotation(const string& instr)
//{
//	string postfix;
//
//	stack<char> mstack;
//	for (char cur : instr)
//	{
//		//  ��������� � ���������� �������� � ����������� ������ � ������� �� ��������� � �������� �������.
//		if (isdigit(cur))
//			postfix += cur;
//
//		//  ��� ��������� �������� � �������� ������� :
//		if (IsOperator(cur))
//		{
//			//���� � ����� ��� �������� ��� ������� ���������
//			//����� �������� ����������� ������, �������� ������� � ����;
//
//			if (mstack.empty() || mstack.top() == '(')
//				mstack.push(cur);
//			//  ���� ����� �������� ����� �������* ���������, ��� ������� �������� � �����, �� ����� �������� ������� � ����;
//			else if (Priority(mstack.top()) < Priority(cur))
//				mstack.push(cur);
//			//  ���� ����� �������� ����� ������� ��� ������ ���������, ��� ������� �������� � �����, �� ��������, ����������� � �����,
//			//�� ��������� ����������� ������ ��� �� �������� � ����������� �������, ��� � ����� ��������, ��������������� � ����������� ������, � ����� �������� ������� � ����.
//			else if (Priority(mstack.top()) >= Priority(cur))
//			{
//				while (!mstack.empty() && mstack.top() != '(' && !(Priority(mstack.top()) < Priority(cur)))
//				{
//					postfix += mstack.top();
//					mstack.pop();
//				}
//				mstack.push(cur);
//			}
//		}
//
//		//  ����������� ������ ������� � ����.
//		if (cur == '(')
//			mstack.push(cur);
//
//		//  ����������� ������ ����������� �� ����� � ����������� ������ ��� �������� �� ��������� ����������� ������, ����������� ������ ��������� �� �����.
//		if (cur == ')')
//		{
//			while (!mstack.empty() && mstack.top() != '(')
//			{
//				postfix += mstack.top();
//				mstack.pop();
//			}
//			if (mstack.top() == '(')
//				mstack.pop();
//		}
//	}
//	//  ����� ����, ��� �� ��������� �� ����� ��������� ���������, ��������, ���������� � �����, ��������������� � ����������� ���������.
//	while (!mstack.empty())
//	{
//		postfix += mstack.top();
//		mstack.pop();
//	}
//	return postfix;
//}
//
//int Result(const string & postfix)
//{
//	stack<string> mstack;
//	for (char cur : postfix)
//	{
//		if (isdigit(cur))
//			mstack.push(string(1, cur));
//
//		else if (IsOperator(cur))
//		{
//			string right = mstack.top();
//			mstack.pop();
//			string left = mstack.top();
//			mstack.pop();
//			int res = Eval(left, cur, right);
//			mstack.push(to_string(res));
//		}
//	}
//	return  stoi(mstack.top());
//}
#include "Stack.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int lengs_of_postfix_form = 0;
	float amount = 0;
	char* strUser = new char[20];
	cout << " Enter: your expression ";
	cin.getline(strUser, 20);
	char tmp[10];
	char* post = PostfixForm(strUser, lengs_of_postfix_form);
	for (int i = 0; i < lengs_of_postfix_form; i++)
		tmp[i] = post[i];
	try
	{
		amount = Calculate(tmp, lengs_of_postfix_form);
	}
	catch (WrongDivision& s)
	{
		cout << s.what() << endl;
	};
	cout << "\n  Result = " << amount;
	cin.get();
	int d;
	cin >> d;
}