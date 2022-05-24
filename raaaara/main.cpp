#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
using namespace std;
//task 1
class Person {
private:
	vector<tuple<string, string, string>> people;
public:
	Person() {
		people = {
		{"Nurgaziev", "Dauren", "Kairatovich"}
		};
	}
	pair<bool, string> FindPerson(string find_patronymic) {
		for (const auto& [surname, name, patronymic] : people) {
			if (surname == find_patronymic) {
				return { true, patronymic };
			}
		}
		return { false, "" };
	}

};
//-----------------------------------------------------------------------------------------------------------------
//task 2

/*struct PhoneNumber
{
private:
	vector<tuple<int, int, string, optional<int> >> phonenum;
	int countryNum;
	int cityNum;
	string justNum;
	optional<int> addedNum = nullopt;
public:
	PhoneNumber() {
		phonenum = {
			{7, 911, "123456", 12}
		};
	}
	pair<string,optional<int>> FindNum(string findnumb) {
		for (const auto& [countryNum, cityNum, justNum, addedNum] : phonenum) {
			if (justNum == findnumb) {
				return {justNum, addedNum};
			}
		}
	}

};*/
struct PhoneNumber
{
	int country_code;
	int city_code;
	string number;
	optional<int> additional_number;
};
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.country_code, p1.city_code, p1.number, p1.additional_number) < tie(p2.country_code, p2.city_code, p2.number, p2.additional_number);
}

optional<int> getOptInt(string& s)
{
	if (s == "")
	{
		return nullopt;
	}

	return stoi(s);
}

ostream& operator<<(ostream& out, const PhoneNumber& p)
{
	out << '+' << p.country_code << '(' << p.city_code << ')' << p.number;

	if (p.additional_number.has_value())
	{
		out << ' ' << p.additional_number.value();
	}

	return out;
}

int main()
{
	Person people_list;
	bool success;
	string surname;
	tie(success, surname) = people_list.FindPerson("Nurgaziev");
	cout << success << " " << surname << endl;
	tie(success, surname) = people_list.FindPerson("Taganov");
	cout << success << " " << surname << endl;
}