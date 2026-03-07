#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(const vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> nums(N + 1);
    for (int i = 0; i < N + 1; ++i) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums);
    cout << duplicate << endl;

    return 0;
}