#include <vector>
using namespace std;

// Solution: Two Pointers - swap characters from both ends toward center
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}