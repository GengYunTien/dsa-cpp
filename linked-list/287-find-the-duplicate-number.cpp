#include <iostream>
#include <vector>
using namespace std;

// Solution: Floyd's Cycle Detection
// - treat array values as pointers to next index
// - Phase 1: find the intersection point inside the cycle
// - Phase 2: reset slow to start, move both one step at a time to find duplicate
// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}