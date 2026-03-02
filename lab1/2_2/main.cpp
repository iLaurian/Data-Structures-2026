#include <fstream>
#include <cstdlib>
#include <ctime>

std::ifstream f ("2_2.in");
std::ofstream g ("2_2.out");

class GetRandom {
    int* data;
    int capacity, size;

    public:
    GetRandom (int capacity) {
        this->capacity = capacity;
        this->size = 0;
        data = new int[capacity];
    }

    void insert(int x) {
        if (this->size >= this->capacity) {
            g << "Error: Capacity reached!\n";
            return;
        }
        this->data[this->size] = x;
        this->size++;
    }

    void pop() {
        if (this->size == 0) {
            g << "Error: Cannot pop from an empty pool!\n";
            return;
        }

        int randIdx = rand() % this->size;
        g << this->data[randIdx] << '\n';
        this->data[randIdx] = this->data[this->size - 1];
        this->size--;
    }

    ~GetRandom () {
        delete[] data;
    }
};

int main() {
    srand((unsigned)time(nullptr));

    GetRandom a(10);

    a.insert(3);
    a.insert(24);
    a.insert(90);

    a.pop();

    a.insert(87);
    a.insert(63);
    a.insert(71);

    a.pop();
    a.pop();

    return 0;
}