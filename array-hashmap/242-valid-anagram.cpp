#include <string>
#include <unordered_map>
using namespace std;

// Anagram: two strings are anagrams if they contain
//          the same characters with the same frequency
//          e.g. "anagram" and "nagaram" are anagrams

// Solution: use hashmap to count character frequency
// - increment count for each character in s
// - decrement count for each character in t
// - if any count goes below 0, t has extra character not in s
// Time Complexity: O(n)
// Space Complexity: O(n)
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }
    for (char c : t) {
        if (--m[c] < 0) {
            return false;
        }
    }
    return true;
}