#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

//task 1

class container {
    int* data;
    int size;
    int capacity;
    int& operator[](int idx) {}
public:
    container() : size(0), data(nullptr),capacity(0) {}
    container(int _size) : size(_size) {
        if (_size == 0) {
            container();
        }
        else if (_size < 0) {
            data = new int[_size];
            capacity = 0;
        }
        virtual ~container() {
            delete[] data;
        }

    }
};

int main()
{
      
}