#ifndef CREATE_RANDOM_PERSON
#define CREATE_RANDOM_PERSON

#include "Person.h"
#include <cstdlib>   // ��� ������� ������ ���������� ����� srand() � rand()
#include <ctime>     // ����� � randomize ��������� �� ����� ������� ���������

// ������� ������ ���������� ����� ����� ����� ��������� ����������
static uint8_t getRandomNumber(uint8_t min, uint8_t max)
{
	static const double fraction = 1.0 / static_cast<double>(RAND_MAX + 1.0);
	return static_cast<uint8_t>(rand() * fraction * (max - min + 1) + min);
}

// ������� �������� �������� ���������� ����
Person* create_random_person()
{
	// ���� �������� ���������� ����� �� ������
	enum Names
	{
		Alexandr = 1, Andrew, Anastasiya, Irina, Nataliya, Pavel, Roman, Svetlana, Sergey, Tatyana, n_names
	};
	Names name = static_cast<Names>(getRandomNumber(1, Names::n_names-1));
	string random_name;
	switch (name)
	{
	case Alexandr:
		random_name = "���������";
		break;
	case Andrew:
		random_name = "������";
		break;
	case Anastasiya:
		random_name = "���������";
		break;
	case Irina:
		random_name = "�����";
		break;
	case Nataliya:
		random_name = "�������";
		break;
	case Pavel:
		random_name = "�����";
		break;
	case Roman:
		random_name = "�����";
		break;
	case Svetlana:
		random_name = "��������";
		break;
	case Sergey:
		random_name = "������";
		break;
	case Tatyana:
		random_name = "�������";
		break;
	default:
		random_name = "���������";
	};

	// �������� ���������� ��������
	uint8_t random_age = getRandomNumber(20, 40);

	// ���� �������� �������� ���������� ���� � ���������� ����� ��������� ������ � ���������:
	enum Person_types
	{
		formalist = 1, informal, realist, n_types
	};
	Person_types random_type = static_cast<Person_types>(getRandomNumber(1, Person_types::n_types-1));
	switch (random_type)
	{
	case formalist:
		return new Formalist(random_name, random_age);
	case informal:
		return new Informal(random_name, random_age);
	case realist:
		return new Realist(random_name, random_age);
	default:
		return new Realist(random_name, random_age);
	};
}

#endif