#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int a;
	node* next;
};
int main()
{
	node* head = NULL;
	int m=0;
	while (cin >> m && m != -1)
	{
		node* p = (node*)malloc(sizeof(node));
		p->a = m;
		p->next = NULL;
		node *last = head;
		if (last)
		{
			while (last->next)
			{
				last = last->next;
			}
			last->next = p;
		}
		else
			head = p;
	}
	return 0;
}
