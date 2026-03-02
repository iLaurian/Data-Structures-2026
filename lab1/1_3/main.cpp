#include <fstream>

std::ifstream f ("1_3.in");
std::ofstream g ("1_3.out");

int n, mat[1001][1001], x, i;

int main() {
    f >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f >> mat[i][j];
    f >> x;

    int step = 0, i = 1, j = n;
    bool ok = false;
    while (step <= 2*n) {
        if (mat[i][j] < x) i++;
        if (mat[i][j] > x) j--;
        if (mat[i][j] == x) {
            ok = true;
            g << i << ' ' << j << '\n';
            break;
        }
        step++;
    }

    if (!ok) g << -1 << ' ' << -1 << '\n';

    return 0;
}