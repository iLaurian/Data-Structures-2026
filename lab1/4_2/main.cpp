#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int left = 1, right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid * mid <= n && (mid + 1) * (mid + 1) > n) {
            std::cout << mid << std::endl;
            return 0;
        }
        if (mid * mid < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}