// ============================================================
//  Topic   : Strings - Anagram
//  Problem : Check if two strings are anagrams of each other
//  Leetcode: 242 (Valid Anagram)
//  Two strings are anagrams if they have the same characters
//  with the same frequencies (order doesn't matter)
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    string a, b;

    cout << "Enter string 1: ";
    cin >> a;

    cout << "Enter string 2: ";
    cin >> b;

    // Method 1 : Sorting
    // Time : O(n log n)
    // Space: O(1)

    if (a.length() != b.length()) {
        cout << "\nSort Method : NOT Anagram\n";
    }
    else {
        string s1 = a;
        string s2 = b;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2)
            cout << "\nSort Method : Anagram\n";
        else
            cout << "\nSort Method : NOT Anagram\n";
    }

    // Method 2 : Frequency Array -> Works only for lowercase letters
    // Time : O(n)
    // Space: O(1)

    if (a.length() != b.length()) {
        cout << "Frequency Method : NOT Anagram\n";
    }
    else {

        int freq[26] = {0};

        for (int i = 0; i < a.length(); i++)
            freq[a[i] - 'a']++;

        for (int i = 0; i < b.length(); i++)
            freq[b[i] - 'a']--;

        bool flag = true;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Frequency Method : Anagram\n";
        else
            cout << "Frequency Method : NOT Anagram\n";
    }

    // Method 3 : HashMap -> Works for all characters
    // Time : O(n)
    // Space: O(n)

    if (a.length() != b.length()) {
        cout << "HashMap Method : NOT Anagram\n";
    }
    else {

        unordered_map<char, int> mp;

        for (char ch : a)
            mp[ch]++;

        for (char ch : b)
            mp[ch]--;

        bool flag = true;

        for (auto x : mp) {
            if (x.second != 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "HashMap Method : Anagram\n";
        else
            cout << "HashMap Method : NOT Anagram\n";
    }

    return 0;
}

/*
 KEY POINTS:
  - Always check length first -> different lengths can never be anagrams
  - Sort method: simple but O(n log n) -> modifies strings (pass by value)
  - Freq array: O(n) time, O(1) space -> works for lowercase letters only
  - HashMap: O(n) time, O(k) space where k = unique chars -> works universally
  - Group anagrams: use sorted string as hashmap key
  - Anagram ignores order -> only character frequencies matter
*/