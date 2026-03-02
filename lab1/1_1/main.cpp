#include <fstream>

std::ifstream f ("1_1.in");
std::ofstream g ("1_1.out");

int v[1001], n, q;

int main() {
    f >> n >> q;
    for (int i = 1; i <= n; i++) {
        f >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        f >> l >> r;
        g << v[r] - v[l -1] << '\n';
    }
}