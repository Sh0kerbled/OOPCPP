#include <iostream>
#include <cstdint>
using namespace std;

class Person
{
public:
	int age;
	string name;
	string gender;
	string weight;

	void changename();

	void changeage();
	void changeweight();
};

class student {
public:
	string sy;
	void changesy();
};



int main()
{
	Person c;
	c.age = 43;
	c.name = Derek;
	c.gender = Male;
	c.weight = 67 kg;
	cout << c.weight;

}