#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode *newHead = NULL;
	ListNode *p = newHead;

	if (pHead1->val <= pHead2->val)
	{
		newHead = pHead1;
		newHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		newHead = pHead2;
		newHead->next = Merge(pHead1, pHead2->next);
	}

	return newHead;
}

int main()
{
	ListNode *pHead1 = new ListNode(0);
	ListNode *p1 = pHead1;
	ListNode *pHead2 = new ListNode(0);
	ListNode *p2 = pHead2;

	for (int i = 1; i < 5; i++)
	{
		ListNode *p = new ListNode(i);
		p1->next = p;
		p1 = p1->next;
	}
	for (int i = 1; i < 5; i++)
	{
		ListNode *p = new ListNode(i*2);
		p2->next = p;
		p2 = p2->next;
	}

	ListNode *NewHead = Merge(pHead1, pHead2);

	return 0;
}
