#include <fstream>

std::ifstream f ("2_1.in");
std::ofstream g ("2_1.out");

class Vector {
    int* data;
    int size, capacity;

    public:
        Vector(int n) {
            size = 0;
            capacity = n;
            data = new int[capacity];
        }

        int get_size() const {
            return size;
        }

        void push_back(int x) {
            if (size < capacity) {
                data[size] = x;
                size++;
                return;
            }

            int* new_data = new int[2 * capacity + 1];

            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            new_data[size] = x;

            delete[] data;
            data = new_data;
            size++;
            capacity = 2 * capacity + 1;
        }

        void pop_back() {
            if (size <= 0) return;
            size--;
        }

        ~Vector() {
            delete[] data;
        }
};

int main() {
    Vector v(3);

    v.push_back(5);
    v.push_back(10);

    g << v.get_size() << '\n';

    v.pop_back();

    g << v.get_size() << '\n';

    return 0;
}