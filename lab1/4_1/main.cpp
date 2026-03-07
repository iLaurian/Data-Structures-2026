#include <iostream>
#include <vector>

bool canAllocateCandies(const std::vector<int>& candies, long long k, int numOfCandies) {
    long long maxNumOfChildren = 0;

    for (int candie : candies) {
        maxNumOfChildren += candie / numOfCandies;
    }

    return maxNumOfChildren >= k;
}

int maximumCandies(std::vector<int>& candies, long long k) {
    int maxCandies = -1;
    for (int i = 0; i < candies.size(); i++) {
        if (maxCandies < candies[i])
            maxCandies = candies[i];
    }

    int left = 0, right = maxCandies;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canAllocateCandies(candies, k, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    std::vector<int> candies = {5, 8, 6};
    std::cout << maximumCandies(candies, 3) << std::endl;
    return 0;
}