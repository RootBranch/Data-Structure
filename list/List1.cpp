//将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来的两个链表的储存空间，不另外占用别的存储空间。表中不能有重复的数据


#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int value;
	Node* next;
};


struct List {
	Node* head;
};


void Create(List* plist)
{
	int number;
	while (cin >> number && number != -1)
	{
		Node* last = plist->head->next;
		Node* p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
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

void Add(List* plist1, List* plist2)
{
	Node* p1 = plist1->head->next;
	Node* p2 = plist2->head->next;
	Node* p3 = p3 = plist1->head;
	while (p1 && p2)
	{
		if (p1->value < p2->value)
		{
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
		else if (p1->value == p2->value)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
			Node* q = p2;
			p2 = p2->next;
			free(q);
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	p3->next = p1 ? p1 : p2;
}

void print(List* plist)
{
	Node* p = plist->head->next;
	while (p)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	List list1;
	list1.head = (Node*)malloc(sizeof(Node));
	list1.head->next = NULL;
	List list2;
	list2.head = (Node*)malloc(sizeof(Node));
	list2.head->next = NULL;
	Create(&list1);
	Create(&list2);

	Add(&list1, &list2);

	print(&list1);

	return 0;
}