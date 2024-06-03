#pragma once
#include "Monster.h"
#include <cstring>
struct SingleLinkedList
{
	Monster2* pHead;
	Monster2* pTail;

	int size;
};

void CreateMonser(SingleLinkedList& list, const char* name, int hp, int mp)
{
	Monster2* m = new Monster2;
	m->hp = hp;
	m->mp = mp;
	strncpy_s(m->name, name, NAME_LENGTH);
	m->pNext = nullptr;
	list.size++;

	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		list.pHead = m;
		list.pTail = m;
	}
	else
	{
		list.pTail->pNext = m;
		list.pTail = m;
	}
}

int GetMonsterCount(const SingleLinkedList& list)
{
	return list.size;
	/*
	Monster2*m = list.pHead;
	int count;
	while(m->pNext != nullptr)
	{
		count++;
		m = m->pNext;
	}
	return count;
	*/
}

void PrintMonsters(const SingleLinkedList& list)
{
	Monster2* m = list.pHead;

	while (m != nullptr)
	{
		std::cout << m->name << ", " << m->hp << ", " << m->mp << std::endl;
		m = m->pNext;
	}
}

bool FindMonsters(const SingleLinkedList& list, const char* name)
{
	Monster2* m = list.pHead;
	while (m != nullptr)
	{
		if (strcmp(m->name, name))
		{
			return true;
		}
		m = m->pNext;
	}
	return false;
}

void DeleteList(SingleLinkedList& list)
{
	Monster2* m = list.pHead;
	Monster2* next;
	while (m != nullptr)
	{
		next = m->pNext;
		delete m;
	}

	list.size = 0;
	list.pHead = list.pTail = nullptr;

}

void DeleteMonster(SingleLinkedList& list, const char* name)
{
	Monster2* m = list.pHead;
	Monster2* previous = nullptr;

	while (m != nullptr)
	{
		if (strcmp(m->name, name) == 0)
		{
			break;
		}

		previous = m;
		m = m->pNext;
	}
	if (m != nullptr)
	{
		if (list.pHead == list.pTail)
		{
			list.pHead = list.pTail = nullptr;
		}
		else if (previous == nullptr)
		{
			list.pHead = m->pNext;
		}
		else if (m == list.pTail)
		{
			previous->pNext = nullptr;
			list.pTail = previous;
		}
		else
		{
			previous->pNext = m->pNext;
		}
		list.size--;
		delete m;
	}
}

void SingleLinkedListTest()
{
	SingleLinkedList list{};
	CreateMonser(list, "wolf", 100, 0);
	CreateMonser(list, "Demon", 200, 100);
	std::cout << GetMonsterCount(list) << std::endl;

	PrintMonsters(list);

	std::cout << FindMonsters(list, "wolf") << std::endl;

	DeleteMonster(list, "wolf");



	DeleteList(list);
}


