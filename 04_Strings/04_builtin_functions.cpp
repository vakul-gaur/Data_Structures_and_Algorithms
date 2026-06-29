// ============================================================
//  Topic   : Strings - Built-in Functions
//  Concept : Essential std::string member functions with examples
// ============================================================

#include <iostream>
#include <string>
#include <algorithm>    // for sort, reverse, transform
using namespace std;

int main() {

    string str = "Hello World!";
    cout << "Base string: " << str << endl;

    // Size / Capacity
    cout << "Size:\n";
    cout << "length() = size()= " << str.length() << "\n";
    cout << "empty()= " << str.empty() << "\n";
    cout << "capacity()= " << str.capacity()<< "\n";

    // Access
    cout << "\nAccess:\n";
    cout << "front()= " << str.front() << endl;   // 'H'
    cout << "back()= " << str.back() << endl;     // '!'
    cout << "s[6]= " << str[6] << endl;           // 'W'
    cout << "at(6)= " << str.at(6) << endl;       // 'W' (bounds-checked)

    // Substring
    cout << "\nSubstring:\n";  // substr(startPos, length)
    cout << "substr(0, 5)= " << str.substr(0, 5) << endl;   // "Beautiful"
    cout << "substr(6)= " << str.substr(6) << endl;         // "World" (till end)

    // Find
    cout << "\nFind:\n";
    cout << "find(World)= " << str.find("World") << endl;   // 6
    cout << "find(xyz)= " << str.find("xyz") << endl;   // string::npos
    cout << "rfind(l)= " << str.rfind("l") << endl;   // last 'l' position
    cout << "find_first_of(aeiou)= " << str.find_first_of("aeiou") << endl; // first vowel

    if (str.find("He") != string::npos)
        cout << "He found in s" << endl;

    // Insert / Erase
    cout << "\nInsert / Erase\n";
    string t = "Hello World";
    t.insert(5, " Brave");      // insert " Brave" at index 5
    cout << "After insert: " << t << "\n";    // "Hello Brave World"

    t.erase(5, 6);                     // erase 6 chars starting at index 5
    cout << "After erase : " << t << "\n";   // "Hello World"

    // Replace
    cout << "\nReplace\n";
    t.replace(6, 5, "Coders");           // replace 5 chars at pos 6 with "Coders"
    cout << "After replace: " << t << "\n";  // "Hello Coders"

    // append / +=
    cout << "\nAppend\n";
    string a = "Hello";
    a.append("World");
    cout << "After append: " << a << "\n";
    a += "!";
    cout << "After +=: " << a << "\n";
    a.push_back('?');
    cout << "After push_back: " << a << "\n";

    // Case Conversion
    cout << "\nCase Conversion\n";
    string upper = "hello";
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "To upper: " << upper << endl;

    string lower = "HELLO";
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "To lower: " << lower << endl;

    // Sort / Reverse
    cout << "\nSort / Reverse\n";
    string srt = "dcbae";
    sort(srt.begin(), srt.end());
    cout << "Sorted : " << srt << "\n";      // "abcde"

    reverse(srt.begin(), srt.end());
    cout << "Reversed: " << srt << "\n";     // "edcba"

    // Clear
    string clr = "bye";
    clr.clear();
    cout << "\nAfter clear: \"" << clr << "\" size=" << clr.size() << endl;

    // Compare
    cout << "\nCompare\n";
    cout << "abc.compare(abc)= " << string("abc").compare("abc") << endl; // 0
    cout << "abc.compare(abd)= " << string("abc").compare("abd") << endl; // negative

    return 0;
}

/*
 QUICK REFERENCE TABLE:
  s.length() / s.size()       -> number of characters
  s.empty()                   -> true if size == 0
  s.front() / s.back()        -> first / last char
  s.substr(pos, len)          -> substring from pos with length len
  s.find(t)                   -> first occurrence of t (string::npos if not found)
  s.rfind(t)                  -> last occurrence
  s.find_first_of("aeiou")    -> first char that matches any in set
  s.insert(pos, t)            -> insert t at pos
  s.erase(pos, len)           -> remove len chars from pos
  s.replace(pos, len, t)      -> replace len chars at pos with t
  s.append(t) / s += t        -> concatenate
  s.push_back(c)              -> add single char at end
  s.pop_back()                -> remove last char
  s.clear()                   -> empty the string
  s.compare(t)                -> 0 if equal, <0 if s<t, >0 if s>t
  sort(s.begin(), s.end())    -> sort characters
  reverse(s.begin(), s.end()) -> reverse in place
*/
