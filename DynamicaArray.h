#pragma once
#include "Monster.h"

// �迭�� ��ü
// 1. ���� �� �߰�
// 2. ����
// (3. ����)

// 4. ����
// 5. Ž��(�˻�)
// 6. ���

struct DynamicArray
{
	Monster* pArray;
	int size;
};

void CreateMonster(DynamicArray& array, const char *name, int hp, int mp)
{
	Monster* temp = new Monster[array.size + 1];

	for (int i = 0; i < array.size; ++i)
	{
		temp[i] = array.pArray[i];
	}

	delete[] array.pArray;
	array.pArray = temp;

	Monster& m = array.pArray[array.size];
	strcpy_s(m.name, NAME_LENGTH, name);
	
	/*for (int i = 0; i < NAME_LENGTH && name[i] != '\0'; i++)
	{
		m.name[i] = name[i];
	}
	m.name[NAME_LENGTH - 1] = '\0';*/
	m.hp = hp;
	m.mp = mp;
	array.size++;
}

void DeleteMonster(DynamicArray& array, const char*name)
{
	int index{ -1 };
	
	for (int i = 0; i < array.size; ++i)
	{
		if (strcmp(array.pArray[i].name, name) == 0)
		{
			index = i;
				break;
		}
	}
	
	if (index != -1)
	{
		Monster* temp = new Monster[array.size - 1];
			int j{};
			for (int i = 0; i < array.size; ++i)
			{
				if (j != index)
				{
					temp[ j++ ] = array.pArray[i];
				}
			}
			delete[] array.pArray;
			array.pArray = temp;
			--array.size;
	}

}
int GetMonsterCount(const DynamicArray &array)
{
	return array.size;
}

bool FindMonsters(const DynamicArray& array, const char *name)
{
	for (int i = 0; i < array.size; ++i)
	{
		if (strcmp(array.pArray[i].name, name))
		{
			return true;
		}
	}
	return false;
}
void PrintMonsters(const DynamicArray &array)
{
	for (int i = 0; i < array.size; i++)
	{
		const Monster& m = array.pArray[i];
		std::cout << m.name << ", " << m.hp << ", " << m.mp << std::endl;
	}

}

void DynamicArryTest()
{
	DynamicArray array{};
	//���� �߰�
	CreateMonster(array, "Wolf", 100, 0);
	CreateMonster(array, "Demon", 200, 100);
	//���
	PrintMonsters(array);
	//����
	std::cout << GetMonsterCount(array) << std::endl;
	//ã��
	std::cout << FindMonsters(array, "wolf") << std::endl;
	//����
	DeleteMonster(array, "wolf");
	PrintMonsters(array);

	DeleteMonster(array, "Demon");
}