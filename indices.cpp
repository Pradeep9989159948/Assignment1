#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

pair<int, int> findTwoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return make_pair(num_map[complement], i);
        }
        num_map[nums[i]] = i;
    }
    return make_pair(-1, -1); // Should not reach here due to problem constraints
}

int getValidInput() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter an integer: ";
        } else {
            break;
        }
    }
    return value;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    n = getValidInput();

    vector<int> nums(n);
    cout << "Enter the elements of the array Example 3<Space>3: ";
    for (int i = 0; i < n; ++i) {
        nums[i] = getValidInput();
    }

    int target;
    cout << "Enter the target sum: ";
    target = getValidInput();

    pair<int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "{" << result.first << ", " << result.second << "}" << endl;
    } else {
        cout << "No result" << endl;
    }

    return 0;
}
