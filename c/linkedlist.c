/* linkedlist.c */
#include <stdlib.h>
#include "linkedlist.h"

static link head = NULL;

link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(unsigned char key)
{
	link p;
	for (p = head; p; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)
{
	p->next = head;
	head = p;
}

void delete(link p)
{
	link *pnext;
	for (pnext = &head; *pnext; pnext = &(*pnext)->next)
		if (*pnext == p) 
		{
			*pnext = p->next;
			return;
		}
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link q, p = head;
	head = NULL;
	while (p) 
	{
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p);
}

link pop(void)
{
	if (head == NULL)
		return NULL;
	else 
	{
		link p = head;
		head = head->next;
		return p;
	}
}

void insert_sort(void)
{
	link pnext;
	link i;
	link j;
	link k;
	link m;
	for (pnext = head; pnext; m = pnext, pnext = j)
	{
		i = head;
		j = pnext->next;
		while (i != pnext)
		{
			k = i->next;
			if ((k == pnext) && (pnext->item >= i->item))
				break;
			if ((i == head) && (pnext->item <= i->item))
			{
				head = pnext;
				pnext->next = i;
				m->next = j;
				break;
			}
			if ((pnext->item <= k->item) && (pnext->item >= i->item))
			{
				i->next = pnext;
				pnext->next = k;
				m->next = j;
				break;
			}
			i = i->next;
		}

	}
}
