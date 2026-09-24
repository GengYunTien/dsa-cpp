#include <vector>
#include <unordered_set>
using namespace std;

// Solution: use unordered_set to track seen numbers
// - reserve space upfront to avoid rehashing overhead
// - if current number already exists in set, duplicate found
// Time Complexity: O(n)
// Space Complexity: O(n)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    s.reserve(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (s.count(nums[i])) {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}