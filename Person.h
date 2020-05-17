#ifndef PERSON
#define PERSON

#include <string>
using std::string;

// ������� ���������� ���������� ���������� ��� � ���������� �����
string age_in_correct_form(const uint8_t age)
{
	if ((age == 1) || ((age > 20) && ((age % 10) == 1)))
		return std::to_string(age) + " ���";
	if ((age < 5) || ((age > 20) && ((age % 10) > 0) && ((age % 10) < 5)))
		return std::to_string(age) + " ����";
	return std::to_string(age) + " ���";
}

// ����� �������� � ������������ ���������, ���������� ���������������
class Person
{
protected:
	string  name_;
	uint8_t age_;
public:
	Person(const string& name, uint8_t age) : name_(name), age_(age)
	{}
	string get_name()
	{
		return name_;
	}
	uint8_t get_age()
	{
		return age_;
	}
	virtual string say_hello(Person* other_person) = 0;
	virtual string tell_about_myself()
	{
		return ("- ���� ����� " + name_ + ", ��� " + age_in_correct_form(age_));
	}
	virtual ~Person() {}
};

// ����� ���������, ����������� ��������
class Formalist : public Person
{
public:
	Formalist (const string& name, uint8_t age): Person(name, age)
	{}
	virtual string say_hello(Person* other_person)
	{
		const string hello = "����������, "+ other_person->get_name() + "!\n";
		return hello;
	}
	virtual string tell_about_myself()
	{
		const string intro =  Person::tell_about_myself() + ", � � ���������.\n";
		return intro;
	}
};

// ����� ��������, ����������� ��������
class Informal : public Person
{
public:
	Informal(const string& name, uint8_t age) : Person(name, age)
	{}
	virtual string say_hello(Person* other_person)
	{
		const string hello = "������, " + other_person->get_name() + "!\n";
		return hello;
	}
	virtual string tell_about_myself()
	{
		const string intro = Person::tell_about_myself() + ", � � ��������.\n";
		return intro;
	}
};

// ����� �������, ����������� ��������
class Realist : public Person
{
private:
	// ������� ���������� ������������� ������� � ��������
	uint8_t difference_in_age(const uint8_t age1, const uint8_t age2)
	{
		if (age1 >= age2) 
			return (age1 - age2);
		return (age2 - age1);
	}
public:
	Realist(const string& name, uint8_t age) : Person(name, age)
	{}
	virtual string say_hello(Person* other_person)
	{
		string hello;
		if (difference_in_age(age_, other_person->get_age()) <= 5)
			hello = "������, " + other_person->get_name() + "!\n";
		else
			hello = "����������, " + other_person->get_name() + "!\n";
		return hello;
	}
	virtual string tell_about_myself()
	{
		const string intro = Person::tell_about_myself() + ", � � �������.\n";
		return intro;
	}
};

#endif
