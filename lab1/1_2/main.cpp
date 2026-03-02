#include <fstream>

std::ifstream f ("1_2.in");
std::ofstream g ("1_2.out");

int a[1001], n, s;

int main() {
    f >> n >> s;
    for (int i = 1; i <= n; i++)
        f >> a[i];

    int l = 1, r = n, best_diff = INT_MAX, i = 0, j = 0;
    while (l < r) {
        int sum = a[l] + a[r];
        int diff = abs(sum - s);
        if (diff == 0) {
            i = l; j = r;
            break;
        }
        if (diff < best_diff) {
            best_diff = diff;
            i = l; j = r;
        }

        if (sum < s) l++;
        else r--;
    }

    g << i << " " << j << "\n";
    return 0;
}