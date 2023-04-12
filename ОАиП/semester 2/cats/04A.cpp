#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(int k, vector<int>& nums, vector<bool>& used, vector<int>& current) {
    if (k == nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            cout << current[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                current[k] = nums[i];
                generatePermutations(k + 1, nums, used, current);
                used[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    vector<bool> used(n, false);
    vector<int> current(n);
    generatePermutations(0, nums, used, current);

    return 0;
}
