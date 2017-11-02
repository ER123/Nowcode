#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* createRandomList()
{
	RandomListNode *node, *tail;
	RandomListNode *head = new RandomListNode(NULL);
	int label;
	tail = head;
	cin >> label;
	while (label != -1)
	{
		node = new RandomListNode(label);
		tail->next = node;
		tail = node;
		cin >> label;
	}
	RandomListNode *p = head;
	int i = 0;
	while (p->next->next != NULL)
	{
		if (i % 2 == 0)
		{
			p->random = p->next->next;
		}
		p = p->next;
		i++;
	}
	return head;
}

void splitList(RandomListNode *pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return;
	RandomListNode *head1, *head2;
	RandomListNode *p1 = pHead;
	RandomListNode *p2;

	head1 = pHead;	
	head2 = p2 = p1->next;	

	while (p1->next != NULL)
	{
		p1->next = p2->next;
		p1 = p1->next;
		p2->next = p1->next;
		p2 = p2->next;
	}
	return;
}

RandomListNode* copy(RandomListNode *pHead)
{
	RandomListNode *p = pHead;
	
	while (p != NULL)
	{
		RandomListNode *node = new RandomListNode(p->label);
		node->next = p->next;
		p->next = node;
		p = node->next;
	}
	
	p = pHead;
	while (p != NULL)
	{
		RandomListNode *node = p->next;
		if (p->random)
		{
			node->random = p->random->next;
		}
		p = node->next;
	}
	
	RandomListNode *pClone = pHead->next;
	RandomListNode *temp;
	p = pHead;
	while (p->next!=NULL)
	{
		temp = p->next;
		p->next = temp->next;
		p = temp;
	}

	return pClone;
}

int main()
{
	RandomListNode *p;
	p = createRandomList();

	splitList(p);

	RandomListNode *res = copy(p);

	system("pause");
	return 0;
}
