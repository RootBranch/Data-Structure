#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int date;
	Node* next;
};

struct List {
	Node* head;
};

void Create(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	int date;
	while (cin >> date && date != -1)
	{
		Node* last = plist->head->next;
		Node* p=(Node*)malloc(sizeof(Node));
		p->next = NULL;
		p->date = date;
		if (!last)
		{
			plist->head->next = p;
		}
		else
		{
			while (last->next)
			{
				last = last->next;
			}
			last->next = p;
		}
	}
}

void print(List* plist)
{
	Node* p = plist->head->next;
	while (p)
	{
		cout << p->date << " ";
		p = p->next;
	}
	cout << endl;
}


void split(List* plist)
{
	Node* p = plist->head->next;
	List list1;
	List list2;
	list1.head = (Node*)malloc(sizeof(Node));
	list1.head->next = NULL;
	list2.head = (Node*)malloc(sizeof(Node));
	list2.head->next = NULL;
	Node* q1 = list1.head;
	Node* q2 = list2.head;
	while (p)
	{
		if (p->date < 0)
		{
			q1->next = p;
			p = p->next;
			q1 = q1->next;
			q1->next = NULL;
		}
		else {
			q2->next = p;
			p = p->next;
			q2 = q2->next;
			q2->next = NULL;
		}
	}
	print(&list1);
	print(&list2);
}

int main()
{
	List list1;

	Create(&list1);

	split(&list1);

	return 0;
}