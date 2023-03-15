#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
	int value;
	Node *next;
};
struct List {
	Node* head;
};
void add(List* pList, int number);
void print(List* plist);
void found(List* plist, int number);
void clear(List* plist);
void Delete(List* plist, int number);

int main()
{
	//Node* head = NULL;
	List list;
	int number;
	list.head = NULL;
	while (cin >> number && number != -1)
	{
		add(&list, number);
	}
	print(&list);
	cin >> number;
	found(&list, number);
	Delete(&list, number);
	clear(&list);
	return 0;
}
void add(List* pList, int number)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node* last = pList->head;
	if (!last)
		pList->head = p;
	else
	{
		while (last->next)
			last = last->next;
		last->next = p;
	}
}

void print(List* plist)
{
	Node* p = plist->head;
	for (; p; p = p->next)
		cout << p->value << "\t";
}

void found(List* plist,int number)
{
	Node* p;
	int IsFound = 0;
	for (p = plist->head; p; p->next)
	{
		if (p->value == number) {
			cout << "YES" << endl;
			IsFound = 1;
			break;
		}
	}
	if (IsFound == 0)
		cout << "NO" << endl;
}

void clear(List* plist)
{
	Node* p;
	Node* q;
	for (p = plist->head; p; p = q)
	{
		q = p->next;
		free(p);
	}
}

void Delete(List* plist,int number)
{
	Node* p;
	Node* q;
	for (q = 0, p = plist->head; p; q = p, p = p->next)
	{
		if (p->value == number)
		{
			if (q) {
				q->next = p->next;
			}
			else {
				plist->head = p->next;
			}
			free(p);
			break;
		};
	}
}
