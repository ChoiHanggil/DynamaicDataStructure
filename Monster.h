#pragma once
#include <iostream>

const int NAME_LENGTH{ 16 };

struct Monster
{
	char name[NAME_LENGTH];
	int hp;
	int mp;

};


struct  Monster2
{
	char name[NAME_LENGTH];
	int hp;
	int mp;

	Monster2* pNext;
};