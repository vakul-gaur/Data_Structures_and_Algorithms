// ====================================================================
//  Topic   : Strings - Isomorphic Strings
//  Problem : Two strings are isomorphic if chars in s can be replaced
//            to get t, with a consistent one-to-one mapping
//  Leetcode: 205
//  Time    : O(n)  |  Space: O(1) — fixed 256 char alphabet
// ====================================================================

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    string s, t;

    cout << "Enter String 1: ";
    cin >> s;

    cout << "Enter String 2: ";
    cin >> t;

    // Method 1 : Two HashMaps
    // Time  : O(n) | Space : O(n)

    if (s.length() != t.length()) {
        cout << "\nMethod 1 : NOT Isomorphic\n";
    }
    else {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        bool flag = true;
        for (int i = 0; i < s.length(); i++) {

            // Check s -> t
            if (sToT.count(s[i])) {

                if (sToT[s[i]] != t[i]) {
                    flag = false;
                    break;
                }

            } else {

                sToT[s[i]] = t[i];
            }

            // Check t -> s
            if (tToS.count(t[i])) {

                if (tToS[t[i]] != s[i]) {
                    flag = false;
                    break;
                }

            } else {

                tToS[t[i]] = s[i];
            }
        }

        if (flag)
            cout << "\nMethod 1: Isomorphic\n";
        else
            cout << "\nMethod 1: NOT Isomorphic\n";
    }

    // Method 2 : Last Seen Index (Optimal)
    // Time  : O(n) | Space : O(1)

    if (s.length() != t.length()) {
        cout << "Method 2 : NOT Isomorphic\n";
    }
    else {
        int lastS[256] = {0};
        int lastT[256] = {0};

        bool flag = true;
        for (int i = 0; i < s.length(); i++) {

            if (lastS[s[i]] != lastT[t[i]]) {

                flag = false;
                break;
            }

            // Store i+1 because arrays are initialized with 0
            lastS[s[i]] = i + 1;
            lastT[t[i]] = i + 1;
        }

        if (flag)
            cout << "Method 2: Isomorphic\n";
        else
            cout << "Method 2: NOT Isomorphic\n";
    }

    return 0;
}

/* KEY POINTS:            
 - Method 1: Check both s -> t and t -> s mapping -> Ensures one-to-one mapping.
            * Time  : O(n) | Space : O(n)
 - Method 2: Store last seen index of every character.
             * If last seen indices differ, strings are not isomorphic.
             * Store i+1 because arrays are initialized with 0.
             * Time  : O(n) | Space : O(1)
             * Where, n = Length of the strings
*/