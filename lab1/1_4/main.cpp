#include <fstream>
#include <set>

std::ifstream f ("1_4.in");
std::ofstream g ("1_4.out");

std::set<int> a;
int n, k;

int main() {
    f >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        f >> x;
        a.insert(x);
    }

    g << *std::next(a.begin(), k - 1);

    return 0;
}