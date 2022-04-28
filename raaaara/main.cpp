#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

/*namespace zero {
	class DivisionByZero {
		string message;
	public:
		DivisionByZero(string themessage = "") : message(themessage) { }
		const string& getMessage() const { return message; }
	};
	template <typename dbz>
	dbz div(dbz a, dbz b) {
		if (b == 0)
			throw DivisionByZero("Division By Zero");
		return a / b;
				
	}
}*/
class Ex {
public:
	double x;
	Ex(const double& xia) :x(xia){}
		~Ex(){}
};
class Bar {
	double y;
public:
	Bar() { y = 0; }
	~Bar(){}
	void g(const double& a) {
		if (y + a <= 100) {
			y = a;
		}
		else throw Ex(y * a);
	}
};
//task 3
class illegalCommand
{
private:
	int pos_x;
	int pos_y;
	int newPos_x;
	int newPos_y;
	string message;
public:
	illegalCommand(int c_x, int c_y, int n_x, int n_y) :
		pos_x(c_x), pos_y(c_y), newPos_x(n_x), newPos_y(n_y), message("")
	{
		if (abs(pos_x - newPos_x) > 1)
		{
			message += "X coord is TOO big!\n";
			message += to_string(pos_x) + to_string(pos_y) + to_string(newPos_x) + to_string(newPos_y) + "\n";
		}

		if (abs(pos_y - newPos_y) > 1)
		{
			message += "bro sheesh Y coord is too big!\n";
			message += to_string(pos_x) + to_string(pos_y) + to_string(newPos_x) + to_string(newPos_y) + "\n";
		}

		if (pos_x == newPos_x && pos_y == newPos_y)
		{
			message += "I CANT SteP Here\n";
			message += to_string(pos_x) + to_string(pos_y) + to_string(newPos_x) + to_string(newPos_y) + "\n";
		}
	}

	const string& getInfo() const
	{
		return message;
	}
};

class OffTheField {
	int pos_x;
	int pos_y;
	int newPos_x;
	int newPos_y;
	string message;
public:
	OffTheField(int ax, int ay, int bx, int by) : pos_x(ax), pos_y(ay), newPos_x(bx), newPos_y(by), message("") {
		if (abs(pos_x - newPos_x) > 1) {
			message += "Too big coord for me!\n";
			message += to_string(pos_x) + to_string(pos_y) + to_string(newPos_x) + to_string(newPos_y) + "\n";
		}
		if (pos_x == newPos_x && pos_y == newPos_y)
		{
			message += "I cant't step here!\n";
			message += '[' + std::to_string(pos_x) + to_string(pos_y) + to_string(newPos_x) + ';' + to_string(newPos_y) + "\n";
		}
	}
	const std::string& getInfo() const
	{
		return message;
	}
};
class Robot
{
private:
	int pos_x;
	int pos_y;
public:
	Robot(int x = 5, int y = 5) : pos_x(x), pos_y(y)
	{
		std::cout << pos_x << "," << pos_y << std::endl;
	}

	void move(int x, int y)
	{
		if (abs(pos_x - x) > 1 || abs(pos_y - y) > 1 || (pos_x == x && pos_y == y))
			throw illegalCommand(pos_x, pos_y, x, y);
		if (x > 10 || x < 1 || y > 10 || y < 1)
			throw OffTheField(pos_x, pos_y, x, y);

		std::cout << pos_x << "," << pos_y << x << "," << y << std::endl;

		pos_x = x;
		pos_y = y;
	}
};

int main()
{
	/*try {
		double result = zero::div(34, 0);
		cout << result << endl;
	}
	catch (const zero::DivisionByZero& c) {
		cerr << c.getMessage() << endl;
	}
	return 0;*/

	int x = 0, y = 0;
	Robot r;

	while (true)
	{
		std::cin >> x >> y;

		if (x == 0 && y == 0)
			break;

		try
		{
			r.move(x, y);
		}
		catch (const illegalCommand& e)
		{
			std::cerr << e.getInfo() << std::endl;
		}
		catch (const OffTheField& e)
		{
			std::cerr << e.getInfo() << std::endl;
		}
	}

}