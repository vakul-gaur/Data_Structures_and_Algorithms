// ============================================================
//  Topic   : Strings - StringStream and Reverse Words
//  Concept : stringstream for parsing; reverse word order in sentence
//  Leetcode: 151 Reverse Words in a String
// ============================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Using stringstream to extract words, then reverse the vector
string reverseWordsStream(string& s) {
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word) words.push_back(word);

    reverse(words.begin(), words.end());

    string result = "";
    for (int i = 0; i < (int)words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }
    return result;
}

// Method 2: Reverse entire string, then reverse each word
// "the sky is blue" -> "eulb si yks eht" -> "blue is sky the"
string reverseWordsInPlace(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    int l = 0;
    int r = 0;

    while (i < n) {

        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            break;

        if (l != 0)
            s[l++] = ' ';

        r = l;

        while (i < n && s[i] != ' ')
            s[l++] = s[i++];

        reverse(s.begin() + r, s.begin() + l);
    }

    s.resize(l);
    return s;
}

int main() {

    // Reverse Words
    cout << "\nReverse Words\n";
    string s1 = "the sky is blue";
    cout << "Original: " << s1 << endl;
    cout << "Reversed(ss): " << reverseWordsStream(s1) << endl;
    cout << "Reversed(ip): " << reverseWordsInPlace(s1) << endl;

    string s2 = "  hello world  ";
    cout << "\nWith extra spaces:\n";
    cout << "Original: " << s2 << "\"\n";
    cout << "Reversed(ss): " << reverseWordsStream(s2) << endl;
    // ss>> automatically skips extra spaces -> clean output

    return 0;
}

/*
 KEY POINTS:
  - Stream method: extract words into vector -> reverse vector -> join
  - In-place method: reverse all -> reverse each word (no extra space O(1))
  - ss>> automatically handles multiple spaces / leading-trailing spaces
*/
