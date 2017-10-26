#include <iostream>

using namespace std; 

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void createList(ListNode* &l)
{
	ListNode *newNode, *p;
	p = l;
	int val;
	cin >> val;
	while(val != -1)
	{
		newNode = new ListNode(val);
		if (newNode == NULL)
		{
			cout << "new failed" << endl;
			exit(-1);
		}
		p->next = newNode;
		p = newNode;
		cin >> val;
	}
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

	if (pListHead == NULL || k <=0)
		return NULL;

	ListNode *p = pListHead, *q = pListHead;
	int i = 0;
	while (i < k && p != NULL){
		p = p->next;
		i++;
	}
	if (p == NULL)
		return NULL;
	while (p != NULL){
		p = p->next;
		q = q->next;
	}
	return q;

	//if (pListHead == NULL || k == 0)
	//		return NULL;
	//ListNode*pTail = pListHead, *pHead = pListHead;
	//for (int i = 1; i < k; ++i)
	//{
	//	if (pHead->next != NULL)
	//		pHead = pHead->next;
	//	else
	//		return NULL;
	//}
	//while (pHead->next != NULL)
	//{
	//	pHead = pHead->next;
	//	pTail = pTail->next;
	//}
	//return pTail;
}


int main()
{
	ListNode *l = new ListNode(-1);
	createList(l);

	ListNode *p = FindKthToTail(l, 0);

	return 0;
}
