// =======================================================================
//  Topic   : Strings - Longest Common Prefix
//  Problem : Find the longest string that is a prefix of all strings
//  Leetcode: 14
//  Time    : O(n * m) where n = number of strings, m = min string length
// =======================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Horizontal Scan
// Compare prefix with each string one by one
string lcpHorizontal(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];       // assume first string is the prefix

    for (int i = 1; i < strs.size(); i++) {
        // Shrink prefix until strs[i] starts with it
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);  // trim one char from end
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

// Method 2: Vertical Scan (column by column)
// Compare character at same position across all strings
string lcpVertical(vector<string>& strs) {
    if (strs.empty()) return "";

    for (int col = 0; col < strs[0].length(); col++) {
        char c = strs[0][col];      // character from first string at this column

        for (int row = 1; row < strs.size(); row++) {
            // If column exceeds string length OR char doesn't match -> stop
            if (col >= (int)strs[row].length() || strs[row][col] != c) {
                return strs[0].substr(0, col);
            }
        }
    }
    return strs[0];     // entire first string is the common prefix
}

// Method 3: Sort + compare first and last -> O(n log n × m)
// After sorting, first and last strings differ the most
// Their common prefix = common prefix of all strings
string lcpSort(vector<string> strs) {
    if (strs.empty()) return "";

    sort(strs.begin(), strs.end());

    string first = strs.front();
    string last  = strs.back();

    int i = 0;
    while (i < first.length() && i < last.length() && first[i] == last[i]) {
        i++;
    }
    return first.substr(0, i);
}

// Helper: print test result
void testLCP(vector<string> strs) {
    cout << "Strings: [";
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << ", ";
    }
    cout << "]\n";
    cout << "  Vertical: " << lcpVertical(strs)   << endl;
    cout << "  Horizontal: " << lcpHorizontal(strs) << endl;
    cout << "  Sort: " << lcpSort(strs) << endl << endl;
}

int main() {

    testLCP({"flower", "flow", "flight"});
    // "fl"

    testLCP({"dog", "racecar", "car"});
    // ""  (no common prefix)

    testLCP({"abc", "abc", "abc"});
    // "abc" (all same)

    testLCP({"a"});
    // "a" (single string)

    testLCP({"", "abc"});
    // "" (empty string has no prefix)

    return 0;
}

/*
 KEY POINTS:
  - Horizontal: trim prefix string character by character until all strings start with it
  - Vertical: go column by column, stop when any string differs or ends
  - Sort: after sorting, only first and last need comparison
  - Vertical scan is usually most intuitive and efficient in practice
*/