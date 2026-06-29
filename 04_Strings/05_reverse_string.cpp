// =========================================================
//  Topic   : Strings - Reverse String and First Half
//  Concept : Reverse full string, reverse first half only
//  Time    : O(n)  |  Space: O(1) in-place
// =========================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Full reverse using two pointers
void reverseString(string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// Reverse only first half
// "abcdef" -> "cbadef" (first 3 chars reversed, rest unchanged)
void reverseFirstHalf(string& str) {
    int half = str.length() / 2;
    int left = 0, right = half - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// Reverse only second half
void reverseSecondHalf(string& s) {
    int n = s.length();
    int left = n / 2, right = n - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// Reverse each word individually
// "Hello World" -> "olleH dlroW"
void reverseEachWord(string& str) {
    int start = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (i == str.length() || str[i] == ' ') {
            int left = start, right = i - 1;
            while (left < right) swap(str[left++], str[right--]);
            start = i + 1;
        }
    }
}

int main() {

    // Full Reverse
    string s1 = "Hello World";
    cout << "Original: " << s1 << endl;

    string s2 = s1;
    reverseString(s2);
    cout << "Full reverse: " << s2 << endl;

    // STL one-liner
    string s3 = s1;
    reverse(s3.begin(), s3.end());
    cout << "STL reverse: " << s3 << endl;

    // First Half Reverse
    string s4 = "abcdef";
    cout << "\nOriginal: " << s4 << endl;
    reverseFirstHalf(s4);
    cout << "First half rev: " << s4 << endl;   // "cbadef" -> "cbadef"

    // Second Half Reverse
    string s5 = "abcdef";
    reverseSecondHalf(s5);
    cout << "Second half rev: " << s5 << endl;   // "abcfed"

    // Reverse each word
    string s7 = "Hello World";
    reverseEachWord(s7);
    cout << "\nEach word reversed: " << s7 << endl;  // "olleH dlroW"

    // STL partial reverse
    string s8 = "HelloWorld";
    int half = s8.length() / 2;
    reverse(s8.begin(), s8.begin() + half);         // reverse first half only
    cout << "STL first half rev: " << s8 << endl << endl;

    // Check if string is palindrome using reverse
    string s9 = "racecar";
    string s9_rev = s9;
    reverse(s9_rev.begin(), s9_rev.end());
    cout << s9 << " is palindrome?: " << (s9 == s9_rev ? "Yes" : "No") << endl;

    string s10 = "hello";
    string s10_rev = s10;
    reverse(s10_rev.begin(), s10_rev.end());
    cout << s10 << " is palindrome?: " << (s10 == s10_rev ? "Yes" : "No") << "\n";

    return 0;
}

/*
 KEY POINTS:
  - Full reverse: two pointers from both ends, swap until they meet
  - First half: right pointer stops at (length/2 - 1)
  - For odd length: middle character is untouched (half = n/2 skips it)
  - STL: reverse(begin, end) for full; reverse(begin, begin+k) for partial
  - Palindrome check: compare string with its reverse
*/