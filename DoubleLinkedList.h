#pragma once
#include "Monster.h"
#include <cstring>

struct  DoubleLinkedList
{
	Monster3* pHead{nullptr};
	Monster3* pTail{nullptr};

	int size{ 0 };
};

void CreateMonster(DoubleLinkedList& list, const char* name, int hp, int mp)
{
	Monster3* m = new Monster3;
	m->hp = hp;
	m->mp = mp;
	strncpy_s(m->name, name, NAME_LENGTH);
	m->pNext = m->pPrev = nullptr;

	list.size++;

	if (list.pTail == nullptr)
	{
		list.pHead = list.pTail = m;
	}
	else
	{
		m->pPrev = list.pTail;
		list.pTail->pNext = m;
		list.pTail = m;
	}

}

void DeleteList(DoubleLinkedList& list)
{
	Monster3* m = list.pHead;
	Monster3* pNext{};

	while (m != nullptr)
	{
		pNext = m->pNext;

		delete m;

		m = pNext;
	}
	list.pHead = list.pTail = nullptr;
	list.size = 0;
}

void PrintList(const DoubleLinkedList& list)
{
	Monster3* m = list.pHead;

	while (m != nullptr)
	{
		std::cout << m->name << ", " << m->hp << ", " << m->mp << std::endl;
		m = m->pNext;
	}
}

void DeleteMonster(DoubleLinkedList& list, const char* name)
{
	Monster3* m = list.pHead;

	while (m != nullptr)
	{
		if (strcmp(m->name, name) == 0)
		{
			break;
		}

		m = m->pNext;
	}

	if (m != nullptr)
	{
		if (m->pPrev == nullptr)
		{
			//m->pNext->pPrev = nullptr;
			list.pHead = m->pNext;
		}
		else
		{
			m->pPrev->pNext = m->pNext;
		}
		if (m->pNext == nullptr)
		{
			//m->pPrev->pNext = nullptr;
			list.pTail = m->pPrev;
		}
		else
		{
			m->pNext->pPrev = m->pPrev;
		}
	}
	delete m;
}


void DoubleLinkedListTest()
{
	DoubleLinkedList list{};

	CreateMonster(list, "wolf", 100, 0);
	CreateMonster(list, "Demon", 200, 100);
	
	PrintList(list);

	DeleteMonster(list, "Demon");

	PrintList(list);

	DeleteList(list);
}