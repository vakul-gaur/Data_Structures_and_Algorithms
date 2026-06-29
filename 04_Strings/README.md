# 📦 Strings — Complete Notes & Revision Guide

> A **string** is a sequence of characters. In C++, prefer `std::string` over C-style `char[]` — it's safer, dynamic, and has rich built-in methods.

---

## 📁 Files in This Folder

| File | Topic |
|------|-------|
| `01_intro_string_datatype.cpp` | C-style vs std::string, cin vs getline, comparison |
| `02_indexing_characters.cpp` | Access, modify, iterate, ASCII values, char functions |
| `03_vowel_digit_count.cpp` | isVowel check, count vowels/consonants/digits/spaces |
| `04_builtin_functions.cpp` | substr, find, insert, erase, replace, sort, reverse |
| `05_reverse_string.cpp` | Full reverse, first-half reverse, palindrome check |
| `06_integer_to_string.cpp` | to_string, manual int<->string, digit arithmetic |
| `07_stringstream_reverse_words.cpp` | ss for split/parse/build, reverse word order |
| `08_neighbouring_diff_chars.cpp` | Count characters whose available neighbours are different. |
| `09_anagram.cpp` | Anagram check (sort / freq array / hashmap) |
| `10_longest_common_prefix.cpp` | Horizontal, vertical, sort methods - Leetcode 14 |
| `11_isomorphic.cpp` | Two-hashmaps, Last seen index - Leetcode 205 |

---

## 🧠 Concept 1 — String Basics

```cpp
string s = "Hello";
s.length()    // 5
s.size()      // 5 (same thing)
s.empty()     // false
s[0]          // 'H'  (no bounds check)
s.at(0)       // 'H'  (throws if out of range)
s.front()     // 'H'
s.back()      // 'o'

// Input
cin >> s;           // reads ONE word (stops at space)
getline(cin, s);    // reads FULL LINE including spaces
```

---

## 🧠 Concept 2 — ASCII Values (Memorize!)

```
'A' = 65 'Z' = 90
'a' = 97 'z' = 122
'0' = 48 '9' = 57

'a' - 'A' = 32       -> add 32 to uppercase = lowercase
c - '0'              -> char digit to int ('7' -> 7)
'0' + digit          -> int to char digit (7 -> '7')
c - 'a'              -> index in alphabet ('c' -> 2)
```

---

## 🧠 Concept 3 — Char Classification (`<cctype>`)

```cpp
isalpha(c)   // is letter (a-z, A-Z)?
isdigit(c)   // is digit (0-9)?
islower(c)   // is lowercase?
isupper(c)   // is uppercase?
isspace(c)   // is space/tab/newline?
isalnum(c)   // is letter or digit?
tolower(c)   // convert to lowercase
toupper(c)   // convert to uppercase
```

---

## 🔧 Built-in Function Quick Reference

```cpp
s.substr(pos, len)              // substring
s.find("abc")                   // first occurrence (string::npos if not found)
s.rfind("abc")                  // last occurrence
s.find_first_of("aeiou")        // first char matching any in set
s.insert(pos, "text")           // insert at position
s.erase(pos, len)               // remove len chars from pos
s.replace(pos, len, "text")     // replace len chars at pos
s.append("text") / s += "text"  // append
s.push_back('c')                // add single char at end
s.pop_back()                    // remove last char
s.clear()                       // empty the string
sort(s.begin(), s.end())        // sort characters
reverse(s.begin(), s.end())     // reverse in place
```

---

## 🔧 Algorithm Quick Reference

### Vowel Check
```cpp
bool isVowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
```

### Reverse String (Two Pointer)
```cpp
int l = 0, r = s.length() - 1;
while (l < r) swap(s[l++], s[r--]);
```

### Number <-> String
```cpp
string str = to_string(42);        // int → string
int n       = stoi("42");          // string → int
long long l = stoll("9876543210"); // string → long long
char c = '0' + digit;             // int digit → char
int d  = c - '0';                 // char → int digit
```

### StringStream
```cpp
stringstream ss(sentence);
string word;
while (ss >> word) { /* each word */ }         // split by whitespace

string token;
while (getline(ss, token, ',')) { /* CSV */ }  // split by comma
```

### Anagram Check (Optimal)
```cpp
int freq[26] = {0};
for (char c : a) freq[c-'a']++;
for (char c : b) freq[c-'a']--;
// All zeros? -> anagram
```

### Count Neighbouring Different Chars
```cpp
int count = 0;
for (int i = 0; i < s.length()-1; i++)
    if (s[i] != s[i+1]) count++;
```

### Longest Common Prefix (Vertical Scan)
```cpp
for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[i - 1] && s[i] != s[i + 1]) count++;
}
```

### Isomorphic Strings (Two Maps)
```cpp
unordered_map<char,char> s2t, t2s;
for (int i = 0; i < s.size(); i++) {
    if (s2t.count(s[i]) && s2t[s[i]] != t[i]) return false;
    if (t2s.count(t[i]) && t2s[t[i]] != s[i]) return false;
    s2t[s[i]] = t[i];
    t2s[t[i]] = s[i];
}
```

---

## ⏱️ Time Complexities

| Operation | Time | Space |
|-----------|------|-------|
| Access s[i] | O(1) | O(1) |
| find, rfind | O(n*m) | O(1) |
| substr | O(k) | O(k) |
| sort characters | O(n log n) | O(1) |
| Anagram (freq array) | O(n) | O(1) |
| Anagram (sort) | O(n log n) | O(1) |
| LCP (vertical) | O(n*m) | O(1) |
| Isomorphic | O(n) | O(1) |
| Reverse string | O(n) | O(1) |
| Reverse words | O(n) | O(n) |
| Neighbour diff count | O(n) | O(1) |

---