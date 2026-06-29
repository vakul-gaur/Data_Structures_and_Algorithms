// ===============================================================
//  Topic   : Strings - Introduction and String as a Datatype
//  Concept : C-style strings vs C++ std::string
//            std::string is the preferred, safe, modern approach
// ===============================================================

#include <iostream>
#include <string>       // required for std::string
#include <cstring>      // for C-style string functions (strlen, strcpy, etc.)
using namespace std;

int main() {

    // C-STYLE STRINGS (char arrays)
    char c1[] = "Hello";             // compiler adds '\0' at end automatically
    char c2[10] = "World";           // fixed buffer of 10 bytes
    char c3[] = {'H','i','\0'};      // manually add null terminator

    cout << "C-Style Strings:\n";
    cout << c1 << "\n";
    cout << "Length (strlen): " << strlen(c1) << "\n";   // doesn't count '\0'
    cout << "sizeof c1: " << sizeof(c1) << "\n";   // includes '\0' -> 6

    // C++ std::string (preferred)
    string s1 = "Hello";
    string s2("World");
    string s3(5, 'A');              // "AAAAA" - fill constructor
    string s4 = s1;                 // copy
    string s5 = s1 + " " + s2;      // concatenation

    cout << "\nC++ std::string\n";
    cout << "s1: " << s1 << "\n";
    cout << "s3: " << s3 << "\n";
    cout << "s5: " << s5 << "\n";

    // Basic properties
    cout << "\nLength: " << s1.length() << "\n";      // or s1.size()
    cout << "Size: " << s1.size() << "\n";            // same as length()
    cout << "Empty?: " << s1.empty() << "\n";         // 0 = not empty
    cout << "Capacity: " << s1.capacity() << "\n";    // internal buffer size

    // Input
    string word, line;
    cout << "\nEnter a single word: ";
    cin >> word;                    // reads until whitespace

    cin.ignore();                   // clear the newline left by cin>>
    cout << "Enter a full line: ";
    getline(cin, line);             // reads the entire line including spaces

    cout << "Word: " << word << "\n";
    cout << "Line: " << line << "\n";

    // Comparison
    string a = "apple", b = "banana";
    cout << "\n\"apple\" == \"apple\" : " << (a == a) << "\n";   // 1 (true)
    cout << "\"apple\" <  \"banana\": " << (a < b)  << "\n";     // 1 (lexicographic)
    cout << "a.compare(b): " << a.compare(b) << "\n";            // negative = a < b

    return 0;
}

/*
 KEY POINTS:
  - C-style char[]: fixed size, manual null terminator, unsafe
  - std::string: dynamic, safe, has built-in operations - always prefer this
  - cin >> reads one word; getline() reads the full line
  - Use cin.ignore() between cin>> and getline() to skip leftover '\n'
  - string.length() == string.size() -> both work
  - string comparison operators (<, >, ==) work lexicographically
*/
