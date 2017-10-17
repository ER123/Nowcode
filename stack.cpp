#include <iostream>
#include <stdlib.h>
#include <stack>

#define Stack_Init_Size 10

using namespace std;

typedef int Element;
typedef int Status;

typedef struct myStack{
	Element *top;
	Element *bottem;
	int stackSize;
}myStack;

void printStack(myStack *s)
{
	if (s->top == s->bottem)
	{
		cout << "stack is empty!\n" << endl;
		return;
	}
	Element *p = s->top;
	for (p; p != s->bottem; p--)
	{
		cout << *(p-1) << " ";
	}
	cout << endl;
}

myStack *initStack()
{
	myStack *s;
	s = (myStack *)malloc(sizeof(myStack));
	if (!s)
	{
		cout << "Error!" << endl;
		exit(-1);
	}

	s->bottem = (Element *)malloc(Stack_Init_Size * sizeof(myStack));

	s->top = s->bottem;

	s->stackSize = Stack_Init_Size;

	return s;
}

Status DestoryStack(myStack *s)
{
	while (s->bottem != s->top)
	{
		Element *p = (s->top--);
		free(p);
	}
	return 1;
}

Element pop(myStack *s)
{
	if (s->bottem == s->top)
	{	
		cout << "stack is empty!" << endl;
		return 0;
	}

	Element e = *(s->top-1);

	s->top--;

	return e;
}

void push(myStack *s, Element e)
{
	if (s->top - s->bottem >= s->stackSize)
	{
		s->bottem = (Element *)realloc(s->bottem, (s->stackSize + Stack_Init_Size)*sizeof(Element));
		if (!s->bottem)
			exit(-1);
		s->stackSize += Stack_Init_Size;
	}
	*(s->top) = e;
	s->top++;
}

int level_of_char(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	if (c == '^')
		return 3;
	if (c == '(' || c == ')')
		return 10;
	else
		return 9999;
}

stack<char> reverse_Bolan(char* str)
{
	stack<char> s1, s2;//s1存放结果，s2辅助存放符号
	char num[10];
	char *p = str;
	while (*p != '#')
	{
		if (*p >= '0' && *p <= '9')//数字直接压栈
		{
			s1.push(*p);
		}

		else if (*p == ' ')
		{	
			p++;
			continue;
		}
		else if (s2.empty())
		{
			s2.push(*p);
		}
   		else if (*p == '(')//左括号压栈s2，用于以后出栈判断
		{
			s2.push(*p);
		}
		else if (*p == ')')//右括号将s2中符号弹出，压入s1直到碰到左括号，并将左括号弹出
		{
			while (s2.top() != '(')
			{
				s1.push(s2.top());
				s2.pop();
			}
			s2.pop();
		}
		else 
		{
			if (s2.top() == '(')
			{
				s2.push(*p);
			}
			else
			{
				while (!s2.empty() && level_of_char(*p) <= level_of_char(s2.top()))
				{
					s1.push(s2.top());
					s2.pop();
				}
				if (s2.empty() || s2.top() == '(' || level_of_char(*p) > level_of_char(s2.top()))
				{
					s2.push(*p);
				}
			}
		}
		p++;
	}
	while (!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
	return s1;
}

void reserveStack(stack<char> &s)
{
	if (s.empty())
		return;
	//cout << s.top() << endl;
	char c = s.top();
	s.pop();
	reserveStack(s);
	cout << c << " ";
	s.push(c);
}

int main()
{
	//myStack *s= initStack();
	//char str[10];
	//char c;
	//scanf("%c", &c);
	//while ('#' != c)
	//{
	//	
	//	if (c >= '0' && c < '9')
	//	{
	//		int i = 0;
	//		while (c != ' ')
	//		{
	//			str[i++] = c;
	//			scanf("%c", &c);
	//		}
	//		double num = atoi(str);
	//		push(s, num);
	//	}
	//	else if (c == '+')
	//	{
	//		int a = pop(s);
	//		int b = pop(s);
	//		push(s, a + b);
	//	}
	//	else if (c == '-')
	//	{
	//		int a = pop(s);
	//		int b = pop(s);
	//		push(s, a - b);
	//	}
	//	else if (c == '*')
	//	{
	//		int a = pop(s);
	//		int b = pop(s);
	//		push(s, a * b);
	//	}
	//	else if (c == '/')
	//	{
	//		int a = pop(s);
	//		int b = pop(s);
	//		push(s, a / b);
	//	}
	//	scanf("%c", &c);
	//}
	//cout << "result is " << pop(s) << endl;

	char str[100] = "1 + ( 2 + 3 ) * 4 + 5 * ( 6 + 7 * 8 ) #";
	cout << "中缀表达式：";
	cout << str << endl;

	stack<char> s = reverse_Bolan(str);

	cout << "后缀表达式：";
	reserveStack(s);
	cout << endl;
		
	system("pause");
	return 0;
}
