#include <iostream>

using namespace std;

typedef struct node{
	int val;
	struct node *next;
}Node;

/*
1.非递归方法，使用三个指针，把当前指针指向前指针
*/
//void reverse(Node *&head)
//{
//	if ((head == NULL) || (head->next == NULL))
//		return;
//	Node *pPre = head;
//	Node *pCur = head->next;
//	Node *pNext = NULL;
//	while (pCur != NULL)
//	{
//		pNext = pCur->next;
//		pCur->next = pPre;
//		pPre = pCur;
//		pCur = pNext;
//	}
//	head->next = NULL;
//	head = pPre;
//}

/*
2.采用递归的方法,在对当前结点逆置时，先逆置其后结点，将后续结点指向当前结点
*/
void reverse(Node *pCur, Node *&head)
{
	if ((pCur == NULL) || (pCur->next == NULL))
		head = pCur;
	else
	{
		Node *pNext = pCur->next;
		reverse(pNext, head);
		pNext->next = pCur;
		pCur->next = NULL;
	}
}

void printList(Node *head)
{
	Node *p = head;
	while (p->next != NULL)
	{
		cout << p->val <<"  ";
		p = p->next;
	}
	cout << p->val << endl;
}

int main()
{
	Node p9{ 9, NULL };
	Node p7{ 7, &p9 };
	Node p5{ 5, &p7 };
	Node p3{ 3, &p5 };
	Node p1{ 1, &p3 };
	Node *head = &p1;
	printList(head);
	Node *temp = head;
	reverse(temp,head);
	printList(head);

	system("pause");
	return 0;
}
